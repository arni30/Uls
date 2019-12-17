#include "../inc/uls.h"

void mx_ls_flag_G(char *current_position){
    struct dirent *ep = NULL;
    char **arr = malloc(268435455*sizeof(char*));
    DIR *dp = opendir(current_position);
    int count = 0;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            mx_printstr(ep->d_name);
            mx_printstr("   ");
            printf("%u8\n",ep->d_type);
            
            if (ep->d_name[0] != '.') {
                arr[count] = mx_strdup(ep->d_name);
                count++;
            }
        }
    }
    closedir(dp);
    arr = mx_realloc(arr, count * sizeof(char*));
    mx_sort_dir(arr,count);
    //return arr;
}
