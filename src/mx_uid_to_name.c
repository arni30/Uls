#include "../inc/uls.h"

char *mx_uid_to_name(t_array *dir, int n) {
    struct passwd *pw_ptr;

    if ((pw_ptr = getpwuid(dir->st[n]->st_uid)) != NULL)
        return pw_ptr->pw_name;
    //pw_ptr = NULL;
    return NULL;
}
