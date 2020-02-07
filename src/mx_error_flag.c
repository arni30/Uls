#include "../inc/uls.h"

int mx_flag_check(char *flag_, int flag_stop) {
    int flag = -2;
    char *us_f = "ACFGRSafglosuc1";//"ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";

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

char **mx_error_check_loop(int argc, char **flags, int *flag_stop, int *count) {
    DIR *dp;
    char **error_flags = malloc(sizeof(char*));

    for (int i = 1; i < argc; i++) {
        dp = opendir(flags[i]);
        if (mx_strcmp("--",flags[i]) == 0)
            *flag_stop = 1;
        if (((flags[i][0] != '-' || mx_strcmp(flags[i], "-") == 0) || *flag_stop == 1)
            && dp == NULL && mx_strcmp("--",flags[i]) != 0) {
            error_flags = mx_realloc(error_flags, sizeof(char*) * (*count + 1));
            error_flags[(*count)++] = mx_strdup(flags[i]);
        }
        if ((mx_flag_check(flags[i], *flag_stop)) >= 0)
            mx_print_error_flag(i, (mx_flag_check(flags[i], *flag_stop)), flags);
        if (dp != NULL) {
            if (flags[i][0] != '-' || mx_strcmp(flags[i], "-") == 0)
                *flag_stop = 1;
            closedir(dp);
        }
    }
    return error_flags;
}

int mx_error_flag(int argc, char **flags) {
    int count = 0;
    int files = 0;
    int flag_stop = 0;
    char **error_flags = mx_error_check_loop(argc, flags, &flag_stop, &count);;

    if (mx_find_flag(argc, flags, 'f') == 0)
        mx_sort_ascii(count, error_flags);
    for (int j = 0; j != count; j++) {
        if (mx_file_exist(error_flags[j]) == 0)
            mx_error_dir(error_flags, j);
        else
            files++;
    }
    mx_free_void_arr((void**)error_flags, count);
    if(files == 0 && count != files && flag_stop == 0)
        exit(1);
    else if (files > 0)
        return 1;
    else
        return 0;
}
