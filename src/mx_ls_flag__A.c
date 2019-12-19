#include "../inc/uls.h"

void mx_ls_flag__A(char *current_position, t_array *dir) {
    struct dirent *ep = NULL;
    dir->type = malloc(sizeof(unsigned char));
    dir->names = malloc(sizeof(char *) * INT_MAX/16);
    DIR *dp = opendir(current_position);
    int count = 0;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (mx_isalpha(ep->d_name[1]) || ep->d_name[0] != '.'){
                if ((lstat(ep->d_name, &dir->st[count]) >= 0) 
                    && (dir->st[count].st_mode > 0) 
                    && (S_IEXEC & dir->st[count].st_mode) 
                    && (S_IFDIR & dir->st[count].st_mode)) {
                    dir->type[count] = 0;
                }
                else {
                    dir->type[count] = ep->d_type;
                }
            dir->names[count] = mx_strdup(ep->d_name);
            count++;
            }
        }
    }
    closedir(dp);
    dir->names = mx_realloc(dir->names, count * sizeof(char**));
    dir->type = mx_realloc(dir->type, count * sizeof(unsigned char));
    mx_sort_dir(dir->names, count, dir->type);
}
