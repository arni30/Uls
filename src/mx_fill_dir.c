#include "../inc/uls.h"

void mx_fill_dir(t_array *dir, struct dirent *ep, int count) {
    dir->st[count] = malloc(sizeof(struct stat) * INT_MAX/144);//почистить для вызова a и A
    if ((lstat(ep->d_name, dir->st[count]) >= 0) 
        && (dir->st[count]->st_mode > 0) 
        && (S_IEXEC & dir->st[count]->st_mode) 
        && (S_IFMT & dir->st[count]->st_mode) != S_IFDIR) {
        dir->type[count] = 0;
    }
    else {
        dir->type[count] = ep->d_type;
    }
    dir->names[count] = mx_strdup(ep->d_name);
}
