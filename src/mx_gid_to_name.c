#include "../inc/uls.h"

char *mx_gid_to_name(t_array *dir, int n){
    struct group *pw_ptr;

    if ((pw_ptr = getgrgid(dir->st[n]->st_gid)) != NULL)
        return pw_ptr->gr_name;
    else
        return mx_itoa(dir->st[n]->st_gid);
}
