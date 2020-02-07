#include "../inc/uls.h"

char *mx_strrchr(char *str, int ch) {
    char *temp = NULL;
    int i = 0;
    int  index = 0;

    while(str[i]) {
        if (str[i] == ch) {
            index = i;
        }
        i++;
    }
    temp = mx_strnew(mx_strlen(str) - index - 1);
    for (int j = index + 1, k = 0; str[j]; j++, k++)
        temp[k] = str[j];
    return temp;
}

int mx_file_exist(char *file) {
    struct stat *st = (struct stat*) malloc(sizeof(struct stat));
    int flag = 0;
    char *path = mx_path(file, NULL, -1);

    if ((lstat(path, st) != -1))
        flag = 1;
    free(st);
    st = NULL;
    mx_strdel(&path);
    return flag;
}

char **mx_input_files(t_var *variable, int *num_files) {
    DIR *dp;
    int flag_stop = 0;
    char **files = malloc(sizeof(char*));

    for (int i = 1; i < variable->argc1; i++) {
        dp = opendir(variable->args[i]);
        if (mx_strcmp("--",variable->args[i]) == 0)
            flag_stop = 1;
        if (((variable->args[i][0] != '-' || mx_strcmp(variable->args[i], "-") == 0) || flag_stop == 1)
            && dp == NULL && mx_file_exist(variable->args[i]) == 1) {
            files = mx_realloc(files, sizeof(char*) * ((*num_files) + 1));
            files[*num_files] = mx_strdup(variable->args[i]);
            (*num_files)++;
        }
        if (dp != NULL) {
            if (variable->args[i][0] != '-')
                flag_stop = 1;
            closedir(dp);
        }
    }
    if (variable->flag_f == 0)
        mx_sort_ascii(*num_files, files);
    return files;
}


static void mx_sort_dir_filesize(int count, t_array *dir) {
    for(int i = 0 ; i < count - 1; i++) { 
       for(int j = i + 1 ; j < count ; j++) {  
            if (dir->st[j]->st_size > dir->st[i]->st_size){
                mx_swaps_arr(dir->names, i, j);
                struct stat *temp = dir->st[i];
                dir->st[i] = dir->st[j];
                dir->st[j] = temp;
                mx_swap_char((char*)&dir->type[i], (char*)&dir->type[j]);
            }
        }
    }
}

void mx_flag_R(int num_of_files, t_array *dir, t_var *variable, char *current_position) {
    int i = 0;
    char **dir_files = (char **)malloc(sizeof(char*));
    char *position = NULL;

    for (int j = 0; j < num_of_files; j++) {
        if ((dir->st[j]->st_mode & S_IFMT) == S_IFDIR && mx_strcmp(dir->names[j], ".") != 0 && mx_strcmp(dir->names[j], "..") != 0) {
            dir_files = mx_realloc(dir_files, sizeof(char*) * (i + 1));
            dir_files[i] = mx_strdup(dir->names[j]);
            i++;
        }
    }
    mx_free_dir(dir, num_of_files);
    for (int k = 0; k < i; k++) {
        position = mx_strdup(current_position);
        mx_printstr("\n");
        position = mx_realloc(position, sizeof(char) * (mx_strlen(current_position) + mx_strlen(dir_files[k]) + 2));
        if (mx_strcmp(position, "/") != 0)
            position = mx_strcat(position, "/");
        position = mx_strcat(position, dir_files[k]);
        mx_printstr(position);
        mx_printstr(":\n");
        mx_ls_dir(position, dir, variable, 0);
        mx_strdel(&position);
    }
    if (i > 0) {
        mx_free_void_arr((void**)dir_files, i);
    }
    else
        free(dir_files);
        dir_files = NULL;
}

void mx_ls_dir(char *current_position, t_array *dir, t_var *variable, int flag_files) {
    int g_fl = 0;
    struct dirent *ep = NULL;
    errno = 0;
    DIR *dp = opendir(current_position);
    char *errbuf = strerror(errno);
    int num_of_files = 0;
    char **files = NULL;

    mx_malloc_dir(dir);
    if (flag_files == 1 || dp != NULL) {
        if (flag_files == 0 && dp != NULL) {
            while ((ep = readdir(dp)) != NULL) {
                if ((variable->flag_a == 1
                     || variable->flag_f == 1))
                    mx_fill_dir(dir, ep, num_of_files++, current_position);
                else if (variable->flag_A == 1
                         && (mx_isalpha(ep->d_name[1])
                             || ep->d_name[0] != '.')) {
                    mx_fill_dir(dir, ep, num_of_files++, current_position);
                } else if (ep->d_name[0] != '.')
                    mx_fill_dir(dir, ep, num_of_files++, current_position);
            }
        }
        else if (flag_files == 1) {
            files = mx_input_files(variable, &num_of_files);
            for (int i = 0; i < num_of_files; i++) {
                mx_fill_file_dir(files[i], dir, i);
            }
            mx_free_void_arr((void **) files, num_of_files);
        }
        if (variable->flag_S == 1 && variable->flag_f == 0) {
            mx_sort_dir_filesize(num_of_files, dir);
        }
        else if (variable->flag_f == 0)
            mx_sort_dir(num_of_files, dir);
        if (variable->flag_G == 1) {
            g_fl = 1;
        }
        if ((variable->flag_l == 1 || variable->flag_o == 1
            || variable->flag_g == 1) && (isatty(1) == 0 || isatty(1) == 1)) {
            mx_ls_flag_l(dir, g_fl, variable, current_position, num_of_files, flag_files);
        }
        else
            mx_output(dir, variable, num_of_files, flag_files);
    }
    else {
        char *temp_pos = mx_strrchr(current_position, (unsigned char)'/');
        mx_print_error("uls: ");//ls: App Store.app: Permission denied
        mx_print_error(temp_pos);
        mx_print_error(": ");
        mx_print_error(errbuf);
        mx_print_error("\n");
        mx_strdel(&temp_pos);
    }
    if (variable->flag_R == 1 && dp != NULL) {
        mx_flag_R(num_of_files, dir, variable, current_position);
    }
    else
        mx_free_dir(dir, num_of_files);
    if(dp != NULL)
        closedir(dp);
}





