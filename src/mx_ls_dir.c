#include "../inc/uls.h"

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
    if (mx_find_flag(variable->argc1, variable->args, 'f') == 0)
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
    DIR *dp = opendir(current_position);
    int num_of_files = 0;
    char **files = NULL;

    mx_malloc_dir(dir);
    if (flag_files == 1 || dp != NULL) {
        if (flag_files == 0 && dp != NULL) {
            while ((ep = readdir(dp)) != NULL) {
                if ((mx_find_flag(variable->argc1, variable->args, 'a') == 1
                     || mx_find_flag(variable->argc1, variable->args, 'f') == 1))
                    mx_fill_dir(dir, ep, num_of_files++, current_position);
                else if (mx_find_flag(variable->argc1, variable->args, 'A') == 1
                         && (mx_isalpha(ep->d_name[1])
                             || ep->d_name[0] != '.')) {
                    mx_fill_dir(dir, ep, num_of_files++, current_position);
                } else if (ep->d_name[0] != '.')
                    mx_fill_dir(dir, ep, num_of_files++, current_position);
            }
            closedir(dp);
        }
        else if (flag_files == 1) {
            files = mx_input_files(variable, &num_of_files);
            for (int i = 0; i < num_of_files; i++) {
                mx_fill_file_dir(files[i], dir, i);
            }
            mx_free_void_arr((void **) files, num_of_files);
        }
        if (mx_find_flag(variable->argc1, variable->args, 'f') == 0)
            mx_sort_dir(num_of_files, dir);
        else if (mx_find_flag(variable->argc1, variable->args, 'S') == 1
                 && mx_find_flag(variable->argc1, variable->args, 'f') == 0) {
            mx_sort_dir_filesize(num_of_files, dir);
        }
        if (mx_find_flag(variable->argc1, variable->args, 'G') == 1) {
            g_fl = 1;
        }
        if ((mx_find_flag(variable->argc1, variable->args, 'l') == 1
            || mx_find_flag(variable->argc1, variable->args, 'o') == 1
            || mx_find_flag(variable->argc1, variable->args, 'g') == 1) && (isatty(1) == 0 || isatty(1) == 1)) {
            mx_ls_flag_l(dir, g_fl, variable, current_position, num_of_files, flag_files);
        }
        else
            mx_output(dir, variable, num_of_files, flag_files);
    }
    else {
        mx_print_error("uls: ");//ls: App Store.app: Permission denied
        mx_print_error(current_position);
        mx_print_error(": Permission denied\n");

    }
    if (mx_find_flag(variable->argc1, variable->args, 'R') == 1) {
        mx_flag_R(num_of_files, dir, variable, current_position);
    }
    else
        mx_free_dir(dir, num_of_files);
}





