#include "../inc/uls.h"

void mx_ls_dir(char *current_position, t_array *dir, int flag) {
    struct dirent *ep = NULL;
    DIR *dp = opendir(current_position);
    int count = 0;

    mx_malloc_dir(dir);
    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (flag == 0 && ep->d_name[0] != '.')
                mx_fill_dir(dir, ep, count++);
            else if (flag == 1 && (mx_isalpha(ep->d_name[1]) 
                    || ep->d_name[0] != '.')){
                mx_fill_dir(dir, ep, count++);
            }
            else if (flag == -1)
                mx_fill_dir(dir, ep, count++);
        }
    }
    closedir(dp);
    mx_sort_dir(count, dir);
}
