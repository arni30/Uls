#include "../inc/uls.h"

char *mx_uid_to_name(int id){   
    struct passwd *pw_ptr;

    if ((pw_ptr = getpwuid(id)) == NULL) {
        return NULL;
    }
    else { 
        return pw_ptr->pw_name;
    }
}
