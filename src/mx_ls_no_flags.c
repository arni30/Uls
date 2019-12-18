#include "../inc/uls.h"

void mx_ls_no_flags(char *current_position, t_array *dir) {    
    struct dirent *ep = NULL;
    DIR *dp = opendir(current_position);
    int count = 0;
    
    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (ep->d_name[0] != '.') {
                printf("%d  ",mx_strlen(ep->d_name));
                printf("%s\n", ep->d_name);
                dir->type[count] = ep->d_type;
                dir->names[count] = mx_strdup(ep->d_name);
                count++;
            }
        }
    }
    closedir(dp);
    //dir = mx_realloc(dir, count * sizeof(t_array*));
    mx_sort_dir(dir->names, count);
}
