#include "../inc/uls.h"

void mx_close_dp(DIR *dp, char *flag, char *p, int *flag_stop) {
    if (dp != NULL || mx_file_exist(flag) == 1) {
        if (flag[0] != '-' || mx_strcmp(flag, "-") == 0)
            *flag_stop = 1;
        if (dp != NULL)
            closedir(dp);
    }
    mx_strdel(&p);
}

char **mx_input_files(t_var *vr, int *num_files) {
    DIR *dp;
    char **files = (char**) malloc(sizeof (char*));
    char *p = NULL;
    char b[1024];

    for (int i = 1, stop = 0; i < vr->argc1; i++) {
        p = mx_path(NULL, vr->args[i], 1);
        dp = opendir(vr->args[i]);
        if (mx_strcmp("--", vr->args[i]) == 0)
            stop = 1;
        if (((vr->args[i][0] != '-' || mx_strcmp(vr->args[i], "-") == 0)
            || stop == 1) && (dp == NULL || (vr->flag_l == 1 &&
            readlink(p, b, 1024) != -1)) && mx_file_exist(vr->args[i]) == 1) {
            files = mx_realloc(files, sizeof(char*) * ((*num_files) + 1));
            files[(*num_files)++] = mx_strdup(vr->args[i]);
        }
        mx_close_dp(dp, vr->args[i], p, &stop);
    }
    return files;
}

static char **fill_dir_files(int *i, int num_of_files, t_array *dir) {
    char **dir_files = NULL;

    for (int j = 0; j < num_of_files; j++) {
        if ((dir->st[j]->st_mode & S_IFMT) == S_IFDIR
            && mx_strcmp(dir->names[j], ".")
                != 0 && mx_strcmp(dir->names[j], "..") != 0) {
            dir_files = mx_realloc(dir_files, sizeof (char*) * (*i + 1));
            dir_files[(*i)++] = mx_strdup(dir->names[j]);
        }
    }
    mx_free_dir(dir, num_of_files);
    return dir_files;
}

void mx_flag_R(int num_of_files, t_array *dir, t_var *variable, char *cur_p) {
    int i = 0;
    char **dir_files = fill_dir_files(&i, num_of_files, dir);
    char *pos = NULL;

    for (int k = 0, len = mx_strlen(cur_p); k < i; k++) {
        pos = mx_strdup(cur_p);
        mx_printstr("\n");
        pos = mx_realloc(pos, sizeof (char) * (len + 2));
        if (mx_strcmp(cur_p, "/") != 0)
            pos = mx_strcat(pos, "/");
        len = mx_strlen(pos) + mx_strlen(dir_files[k]) + 1;
        pos = mx_realloc(pos, sizeof (char) * (len));
        pos = mx_strcat(pos, dir_files[k]);
        mx_printstr(pos);
        mx_printstr(":\n");
        variable->flag_files = 0;
        mx_ls_dir(pos, dir, variable);
        mx_strdel(&pos);
    }
    mx_free_void_arr((void**) dir_files, i);
}

