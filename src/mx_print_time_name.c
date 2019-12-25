#include "../inc/uls.h"

void mx_print_symlink(t_array *dir, char *buf, int i) {
    if ((dir->st[i]->st_mode & S_IFMT) == S_IFLNK){
        mx_printstr(" -> ");
        readlink(dir->names[i], buf, 1024);
        mx_printstr(buf);
    }
    free(buf);
}

void mx_print_time_name(t_array *dir, int i, int flag) {
    struct timespec *a = malloc(sizeof(struct timespec));
    char *time = malloc(sizeof(unsigned char) * CHAR_MAX);
    char *buf = malloc(sizeof(char)*1024);
    char *temp;

    a->tv_sec = dir->st[i]->st_mtimespec.tv_sec;
    temp = ctime(&a->tv_sec);
    for (int i = 4, y = 0; i < 16; i++, y++) {
        time [y] = temp[i];
    }
    mx_printstr(time);
    mx_printstr(" ");
    if (flag == 1)
        mx_color_print(i, dir, 0);
    else
        mx_print_dir(i, dir, 0);
    mx_print_symlink(dir, buf, i);
    mx_printstr("\n");
    free(a);
    free(time);
}

