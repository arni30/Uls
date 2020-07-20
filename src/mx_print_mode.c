#include "../inc/uls.h"

void mx_print_mode(t_array *dir, int i, char *position, int num_of_files) {
    char *str = mx_strnew(10 * sizeof (char) + 1);
    int size = dir->st[i]->st_nlink;
    int counter = 0;
    int len = 0;

    mx_strcpy(str,"---------- ");
    mx_license_if(dir->st[i]->st_mode,str);
    mx_acl_attr_if(dir->st[i]->st_mode, str, position, dir->names[i]);
    mx_printstr(str);
    if (size == 0)
        counter = 1;
    while (size > 0) {
        counter++;
        size /= 10;
    }
    len = mx_count_max_sym(dir, 'l', num_of_files) + 1 - counter;
    for (int y = 0; y < len; y++)
        mx_printchar(' ');
    mx_strdel(&str);
}

