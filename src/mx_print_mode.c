#include "../inc/uls.h"

void mx_print_mode(t_array *dir, int i) {
    int mode = dir->st[i]->st_mode;
    char *str = mx_strnew(10 * sizeof(char)); 

    mx_strcpy(str,"---------- ");
    mx_license_if(mode,str);
    mx_acl_attr_if(mode, str, dir, i);
    mx_printstr(str);
    if (dir->st[i]->st_nlink > 9)
        mx_printstr(" ");
    else
        mx_printstr("  ");
    free(str);
}
