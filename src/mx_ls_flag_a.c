#include "../inc/uls.h"

void mx_ls_flag_a(char *current_position, t_array *dir) {
    struct dirent *ep = NULL;
    dir->type = malloc(sizeof(unsigned char));
    dir->names = malloc(sizeof(char *) * INT_MAX/16);
    DIR *dp = opendir(current_position);
    int count = 0;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            dir->names[count] = mx_strdup(ep->d_name);
            dir->type[count] = ep->d_type;
            count++;
        }
    }
    closedir(dp);
    dir->names = mx_realloc(dir->names, count * sizeof(char**));
    dir->type = mx_realloc(dir->type, count * sizeof(unsigned char));
    mx_sort_dir(dir->names, count, dir->type);
}
