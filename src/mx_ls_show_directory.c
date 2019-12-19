#include "../inc/uls.h"

char **mx_ls_show_directory(char *dir) {
    struct dirent *ep = NULL;
    char **arr = malloc(268435455*sizeof(char*));
    DIR *dp = opendir(dir);
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
    //mx_sort_dir(dir->names, count, dir->type);
    // mx_loop_print(arr, "\n");
    // mx_printchar('\n');
    //mx_free_void_arr((void**)arr, count);
    return arr;
}
