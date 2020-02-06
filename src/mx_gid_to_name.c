#include "../inc/uls.h"

void mx_gid_to_name(int id){
    struct group *pw_ptr;

    if ((pw_ptr = getgrgid(id)) != NULL)
        mx_printstr(pw_ptr->gr_name);
    else
        mx_printint(id);
}
