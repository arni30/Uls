#include "../inc/uls.h"

void mx_color_print(int i, t_array *dir, t_var *variable) {
    if(dir->type[i] == DT_DIR){
        mx_printstr(MX_DIR);
        mx_print_dir(i, dir, variable);
        mx_printstr(MX_FILE);
    }
    else if(dir->type[i] == DT_REG){
        mx_printstr(MX_FILE);
        mx_print_dir(i, dir, variable);
    }
    else if(dir->type[i] == 0 && (dir->st[i]->st_mode & S_IFMT) != S_IFLNK){
        mx_printstr(MX_EXEC);
        mx_print_dir(i, dir, variable);
        mx_printstr(MX_FILE);
    } 
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK){
        mx_printstr(MX_LINK);
        mx_print_dir(i, dir, variable);
        mx_printstr(MX_FILE);
    }
    mx_if_sock_blk_fifo(dir, i, variable);
}



