#include "../inc/uls.h"

void mx_print_dir(int i, t_array *dir, int delim, char **argv) {
    const char *s = dir->names[i];
    int len = mx_strlen(s);
    int count = 0;
    int a_el = 0;

    while (s[count]) {
        if(s[count] > 0)
            a_el++;
        count++;
    }
    if (mx_find_flag(mx_count_arr_el(argv), argv, 's') == 1){
        mx_printstr("  ");
        mx_printint(dir->st[i]->st_blocks);
        mx_printstr(" ");
        len+=3;
    }
    len = (len - a_el) / 2 + (len - a_el) % 2 + a_el;

    mx_printstr(s);
    if (mx_print_flag_F(argv, dir, i) == 1)
        len++;
    if (delim != -1){
        for(int i = delim - len; i > 0; i--) {
            mx_printstr(" ");
        }
    }
    else
        mx_printstr("\n");
}
