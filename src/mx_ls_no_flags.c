#include "../inc/uls.h"

<<<<<<< HEAD
void mx_ls_no_flags(char *current_position) {    
=======
char **mx_ls_no_flags(char *current_position) {    
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
    struct dirent *ep = NULL;
    char **arr = malloc(268435455*sizeof(char*));
    DIR *dp = opendir(current_position);
    int count = 0;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (ep->d_name[0] != '.') {
                arr[count] = mx_strdup(ep->d_name);
                count++;
            }
        }
    }
    closedir(dp);
    arr = mx_realloc(arr, count * sizeof(char*));
    mx_sort_dir(arr,count);
<<<<<<< HEAD
    mx_loop_print(1,arr, "\n");
    //mx_output(arr);
    mx_free_void_arr((void**)arr, count);
=======
    return arr;
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
}
