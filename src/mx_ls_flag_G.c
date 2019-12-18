#include "../inc/uls.h"

void mx_ls_flag_G(char *current_position, t_array *dir){
    struct dirent *ep = NULL;
    dir = malloc(sizeof(t_array));
    DIR *dp = opendir(current_position);
    int count = 0;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            mx_printstr(ep->d_name);
            mx_printstr("   ");
            printf("%u\n",ep->d_type);
            
            if (ep->d_name[0] != '.') {
                dir->names[count] = mx_strdup(ep->d_name);
                count++;
            }
        }
    }
    closedir(dp);
    dir = mx_realloc(dir, count * sizeof(t_array*));
    mx_sort_dir(dir->names, count);
    //return arr;
}
