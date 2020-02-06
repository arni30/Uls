#include "../inc/uls.h"

void mx_color_print(int i, t_array *dir, t_var *variable, int num) {
    char *s_bl = mx_itoa(dir->st[i]->st_blocks);

    if (mx_find_flag(variable->argc1, variable->args, 's') == 1){
        for(int j = mx_count_max_sym(dir, 'b', num) - mx_strlen(s_bl); j > 0; j--) {
            mx_printstr(" ");
        }
        mx_printint(dir->st[i]->st_blocks);
        mx_printstr(" ");
    }
    if((dir->st[i]->st_mode & S_ISVTX) && ((dir->st[i]->st_mode & S_IFMT))){
        mx_printstr(MX_STICKY);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    else if(((dir->st[i]->st_mode & S_IFMT) == S_IFDIR)){
        mx_printstr(MX_DIR);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    else if(dir->type[i] == DT_REG){
        mx_printstr(MX_FILE);
        mx_print_dir(i, dir, variable, num);
    }
    else if(dir->type[i] == 0 && (dir->st[i]->st_mode & S_IFMT) != S_IFLNK){
        mx_printstr(MX_EXEC);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK){
        mx_printstr(MX_LINK);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    mx_if_sock_blk_fifo(dir, i, variable, num);
}



