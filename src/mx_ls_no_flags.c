#include "../inc/uls.h"

char **mx_ls_no_flags(char *current_position) {
    DIR *dp;
    struct dirent *ep = NULL;
    char **arr = malloc(1000 * sizeof(char*));
    int count = 0;

    dp = opendir(current_position);
    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (ep->d_name[0] != '.') {
                arr[count] = mx_strnew(mx_strlen(ep->d_name));
                arr[count] = ep->d_name;
                count++;
            }
        }
    }
    closedir(dp);
    mx_realloc(arr, count);
    mx_sort_dir(arr,count);
    return arr;  
}
// ls -a
