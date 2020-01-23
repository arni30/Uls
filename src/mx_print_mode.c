#include "../inc/uls.h"

void mx_print_mode(t_array *dir, int i, char *position) {
    int mode = dir->st[i]->st_mode;
    char *str = mx_strnew(10 * sizeof(char));
    char curentFile[PATH_MAX + 1];
    int flag = 0;
    mx_strcpy(curentFile, position);
    strcat( curentFile, "/");
    strcat( curentFile, dir->names[i]);

    mx_strcpy(str,"---------- ");
    mx_license_if(mode,str);
    flag = mx_acl_attr_if(mode, str, curentFile);
    mx_printstr(str);
    if (dir->st[i]->st_nlink > 9)
        mx_printstr(" ");
    else if (flag == 1) {
        mx_printstr(" ");
    }
    else
        mx_printstr("  ");
    free(str);
}
