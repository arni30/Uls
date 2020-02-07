#include "../inc/uls.h"

static void mx_if_dir(int i, t_array *dir, t_var *variable, int num) {
    if((dir->st[i]->st_mode & S_IFMT) == S_IFDIR) {
        mx_printstr(MX_DIR);
        if((dir->st[i]->st_mode & S_ISVTX)
            && (dir->st[i]->st_mode & S_IWOTH)){
            mx_printstr(MX_STICKY);
        }
        else if (dir->st[i]->st_mode & S_IWOTH) {
            mx_printstr(MX_NO_STICKY);
        }
        mx_print_dir(i, dir, variable, num);
    }
    mx_printstr(MX_FILE);
}

static void mx_if_exec(int i, t_array *dir, t_var *variable, int num) {
    if((dir->st[i]->st_mode & S_IFMT) == S_IFREG) {
        mx_printstr(MX_FILE);
        if(dir->st[i]->st_mode & S_IXUSR){
            mx_printstr(MX_EXEC);
            if(dir->st[i]->st_mode & S_ISUID) {
                mx_printstr(MX_SET_UID);
            }
            else if(dir->st[i]->st_mode & S_ISGID) {
                mx_printstr(MX_SET_GID);
            }
        }
        mx_print_dir(i, dir, variable, num);
    }
    mx_printstr(MX_FILE);
}

void mx_color_print(int i, t_array *dir, t_var *variable, int num) {
    char *s_bl = mx_itoa(dir->st[i]->st_blocks);

    if (variable->flag_s == 1){
        for(int j = mx_count_max_sym(dir, 'b', num) - mx_strlen(s_bl); j > 0; j--) {
            mx_printstr(" ");
        }
        mx_printint(dir->st[i]->st_blocks);
        mx_printstr(" ");
    }
    mx_if_dir(i, dir, variable, num);
    mx_if_exec(i, dir, variable, num);
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK){
        mx_printstr(MX_LINK);
        mx_print_dir(i, dir, variable, num);
        mx_printstr(MX_FILE);
    }
    mx_if_sock_blk_fifo(dir, i, variable, num);
    mx_strdel(&s_bl);
}



