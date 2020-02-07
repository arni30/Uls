#include "../inc/uls.h"

void mx_print_symlink(t_array *dir, int i) {
    char buf[PATH_MAX + 1];

    if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK){
        //buf = mx_strnew(mx_strlen(dir->names[i]));
        mx_printstr(" -> ");
        readlink(dir->names[i], buf, 1024);
        mx_printstr(dir->names[i]);
        mx_printstr(buf);
        //free(buf);
    }
}

static char *mx_first_flag(t_var *variable) {
    char *str = malloc(sizeof(str));
    for (int i = 1; i < variable->argc1; i++) {
        str = mx_realloc(str, sizeof(char) * (mx_strlen(str) + mx_strlen(variable->args[i]) + 1));
        str = mx_strcat(str, variable->args[i]);
    }
    return str;
}


void mx_print_time_name(t_array *dir, int i, int flag_G, t_var *variable, int num) {
    struct timespec *a = malloc(sizeof(struct timespec));
    char *time_out = malloc(sizeof(char) * 13);
    char *temp = NULL;
    time_t cur_time = 0;
    int y = 0;

    variable->delim = 0;
    char *str = mx_first_flag(variable);

    if (variable->flag_u == 1
        && (variable->flag_c) == 1) {
        if (mx_strchr(str, 'u') > mx_strchr(str, 'c'))
            a->tv_sec = dir->st[i]->st_atimespec.tv_sec;
        else
            a->tv_sec = dir->st[i]->st_ctimespec.tv_sec;
    }
    else if (variable->flag_u == 1) {
        a->tv_sec = dir->st[i]->st_atimespec.tv_sec;
    }
    else if (variable->flag_c == 1) {
        a->tv_sec = dir->st[i]->st_ctimespec.tv_sec;
    }
    else
        a->tv_sec = dir->st[i]->st_mtimespec.tv_sec;
    temp = ctime(&a->tv_sec);

    cur_time = time(NULL);
    if(cur_time - 15724800 <= a->tv_sec) {
        for (int i = 4; i < 16; i++, y++) {
            time_out[y] = temp[i];
        }
    }
    else {
        for (int i = 4; i < 10; i++, y++) {
            time_out[y] = temp[i];
        }
        y += 2;
        time_out[6] = ' ';
        time_out[7] = ' ';
        for (int k = 20; k < 24; k++, y++) {
            time_out[y] = temp[k];
        }
    }
    time_out[y] = '\0';
    mx_printstr(time_out);
    mx_printstr(" ");
    if (flag_G == 1 && isatty(1) == 1)
        mx_color_print(i, dir, variable, num);
    else
        mx_print_dir(i, dir, variable, num);
    mx_print_symlink(dir, i);
    mx_printstr("\n");
    free(a);
    a = NULL;
    mx_strdel(&time_out);
    mx_strdel(&str);
}
