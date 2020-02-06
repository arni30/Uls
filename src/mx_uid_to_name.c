#include "../inc/uls.h"

void mx_uid_to_name(int id){
    struct passwd *pw_ptr;

    if ((pw_ptr = getpwuid(id)) != NULL)
        mx_printstr(pw_ptr->pw_name);
}
