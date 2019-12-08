#include "../inc/uls.h"

void mx_ls_flag_1(char *current_position) {    
    struct dirent *ep = NULL;
    char **arr = malloc(13 * sizeof(char*));
    DIR *dp = opendir(current_position);
    int count = 0;

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
    //mx_realloc(arr, count);
    mx_sort_dir(arr,count);
    //mx_loop_print(arr, "\n");
}
