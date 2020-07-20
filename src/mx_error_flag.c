#include "../inc/uls.h"

int mx_file_exist(char *file) {
    struct stat *st = (struct stat*) malloc(sizeof (struct stat));
    int flag = 0;
    char *path = mx_path(NULL, file, 1);

    if ((lstat(path, st) != -1))
        flag = 1;
    free(st);
    st = NULL;
    mx_strdel(&path);
    return flag;
}

int mx_flag_check(char *flag_, int flag_stop) {
    int flag = -2;
    char *us_f = "ACFGRSacfglorsu1";

    if (flag_[0] == '-' && flag_stop == 0) {
        for (int j = 1; flag_[j] != '\0'; j++) {
            flag = 0;
            for (int count = 0; us_f[count] != '\0'; count++) {
                if (us_f[count] == flag_[j]) {
                    flag = -1;
                    break;
                }
            }
            if (flag == 0) {
                flag = j;
                break;
            }
        }
    }
    return flag;
}

static void if_error_check_loop(int *f_s, char **flags, int i) {
    if (mx_strcmp("--",flags[i]) == 0)
        *f_s = 1;
}

char **mx_error_check(int argc, char **flags, int *f_s, int *count) {
    DIR *dp;
    char **err_flags = (char**) malloc(sizeof (char*));
    char *p = NULL;
    char b[1024];

    for (int i = 1; i < argc; i++) {
        p = mx_path(NULL, flags[i], 1);
        dp = opendir(flags[i]);
        if_error_check_loop(f_s, flags, i);
        if ((flags[i][0] != '-' || mx_strcmp(flags[i], "-") == 0 || *f_s == 1)
            && (dp == NULL || (mx_find_flag(argc, flags, 'l') == 1
            && readlink(p, b, 1024) != -1)) && mx_strcmp("--",flags[i]) != 0) {
            err_flags = mx_realloc(err_flags, sizeof (char*) * (*count + 1));
            err_flags[(*count)++] = mx_strdup(flags[i]);
        }
        if ((mx_flag_check(flags[i], *f_s)) >= 0)
            mx_print_error_flag(i, (mx_flag_check(flags[i], *f_s)), flags);
        mx_close_dp(dp, flags[i], p, f_s);
    }
    return err_flags;
}

int mx_error_flag(int argc, char **flags) {
    int count = 0;
    int files = 0;
    int flag_stop = 0;
    char **error_flags = mx_error_check(argc, flags, &flag_stop, &count);

    if (mx_find_flag(argc, flags, 'f') == 0) {
        mx_sort_ascii(count, error_flags);
        if ((mx_find_flag(argc, flags, 'r') == 1))
            mx_sort_reverse(count, error_flags);
    }
    for (int j = 0; j != count; j++) {
        if (mx_file_exist(error_flags[j]) == 0)
            mx_error_dir(error_flags, j);
        else
            files++;
    }
    mx_free_void_arr((void**)error_flags, count);
    if (files == 0 && count != files && flag_stop == 0)
        exit(1);
    return (files > 0) ? 1 : 0;
}
