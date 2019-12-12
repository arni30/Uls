#include "../inc/uls.h"

char **mx_ls_flag__A(char *current_position) {
    struct dirent *ep = NULL;
    char **arr = malloc(268435455*sizeof(char*));
    DIR *dp = opendir(current_position);
    int count = 0;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (mx_isalpha(ep->d_name[1]) || ep->d_name[0] != '.'){
            arr[count] = mx_strdup(ep->d_name);
            count++;
            }
        }
    }
    closedir(dp);
    arr = mx_realloc(arr, count * sizeof(char*));
    mx_sort_dir(arr,count);
    // mx_output(arr);
    // mx_free_void_arr((void**)arr, count);
    return arr;
}
