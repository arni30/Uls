#include "../inc/uls.h"

void mx_if_sock_blk_fifo(int delim, t_array *dir, int i, char **argv) {
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFSOCK){
        mx_printstr(MX_SOCKET);
        mx_print_dir(i, dir, delim, argv);
        mx_printstr(MX_FILE);
    }
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFBLK 
        || (dir->st[i]->st_mode & S_IFMT) == S_IFCHR) {
        mx_printstr(MX_SOCKET);
        mx_print_dir(i, dir, delim, argv);
        mx_printstr(MX_FILE);
    }
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFIFO){
        mx_printstr(MX_FIFO);
        mx_print_dir(i, dir, delim, argv);
        mx_printstr(MX_FILE);
    }
}