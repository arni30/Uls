#include "../inc/uls.h"

int mx_print_flag_F(char **argv, t_array *dir, int i) {
    if (mx_find_flag(mx_count_arr_el(argv), argv, 'F') == 1) {
        mx_printstr(MX_FILE);
        if ((dir->st[i]->st_mode & S_IFMT) == S_IFDIR)
            mx_printchar('/');
        else if (dir->type[i] == 0 && (dir->st[i]->st_mode & S_IFMT) != S_IFLNK)
            mx_printchar('*');
        else if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK)
            mx_printchar('@');
        else if ((dir->st[i]->st_mode & S_IFMT) == S_IFIFO)
            mx_printchar('|');
        else if ((dir->st[i]->st_mode & S_IFMT) == S_IFSOCK)
            mx_printchar('=');
        else
            return 0;
        return 1;
    }
    return 0;
}