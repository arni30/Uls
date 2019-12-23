#include "../inc/uls.h"

char *mx_gid_to_name(int gid){
    struct group *grp_ptr;

    if ((grp_ptr=getgrgid(gid)) == NULL) {
        return NULL;
    }
    else {   
        return grp_ptr->gr_name;
    }
}
