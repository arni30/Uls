#include "../inc/uls.h"

static void mx_if_sock_blk_fifo(int delim, t_array *dir, int i) {
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFSOCK){
        mx_printstr(MX_SOCKET);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    }
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFBLK 
        || (dir->st[i]->st_mode & S_IFMT) == S_IFCHR) {
        mx_printstr(MX_SOCKET);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    }
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFIFO){
        mx_printstr(MX_FIFO);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    }
}

void mx_color_print(int i, t_array *dir, int delim) {
    if(dir->type[i] == DT_DIR){
        mx_printstr(MX_DIR);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    }
    else if(dir->type[i] == DT_REG){
        mx_printstr(MX_FILE);
        mx_print_dir(i, dir, delim);
    }
    else if(dir->type[i] == 0 && (dir->st[i]->st_mode & S_IFMT) != S_IFLNK){
        mx_printstr(MX_EXEC);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    } 
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK){
        mx_printstr(MX_LINK);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    }
    mx_if_sock_blk_fifo(delim, dir, i);
}



