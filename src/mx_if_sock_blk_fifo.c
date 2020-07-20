#include "../inc/uls.h"

void mx_if_sock_blk_fifo(t_array *dir, int i, t_var *variable, int num) {
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFSOCK) {
        mx_printstr(MX_SOCKET);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    else if ((dir->st[i]->st_mode & S_IFMT) == S_IFBLK) {
        mx_printstr(MX_BLK);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    else if ((dir->st[i]->st_mode & S_IFMT) == S_IFIFO) {
        mx_printstr(MX_FIFO);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    else if ((dir->st[i]->st_mode & S_IFMT) == S_IFCHR) {
        mx_printstr(MX_CHR);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
}
