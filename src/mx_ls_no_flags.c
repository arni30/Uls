#include "../inc/uls.h"

void mx_ls_no_flags(char *current_position, t_array *dir) {    
    struct dirent *ep = NULL;
    DIR *dp = opendir(current_position);
    int count = 0;
    
    dir->st = malloc(sizeof(struct stat *) * INT_MAX/144);//почистить для вызова a и A
    dir->type = malloc(sizeof(unsigned char )* UCHAR_MAX);
    dir->names = malloc(sizeof(char *) * INT_MAX/8);
    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            if (ep->d_name[0] != '.') {
                dir->st[count] = malloc(sizeof(struct stat) * INT_MAX/144);
                if ((stat(ep->d_name, dir->st[count]) >= 0) 
                    && (dir->st[count]->st_mode > 0) 
                    && (S_IEXEC & dir->st[count]->st_mode) 
                    && (S_IFMT & dir->st[count]->st_mode) != S_IFDIR) {
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
    mx_sort_dir(count, dir);
}
