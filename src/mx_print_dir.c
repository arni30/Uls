#include "../inc/uls.h"

void mx_print_dir(int i, t_array *dir, t_var *variable) {
    const char *s = dir->names[i];
    int len = mx_strlen(s);
    int count = 0;
    int a_el = 0;

    while (s[count]) {
        if(s[count] > 0)
            a_el++;
        count++;
    }
    if (mx_find_flag(variable->argc1, variable->args, 's') == 1){
        mx_printint(dir->st[i]->st_blocks);
        mx_printstr(" ");
        len += 3;
    }
    len = (len - a_el) / 2 + (len - a_el) % 2 + a_el;

    mx_printstr(s);
    if (mx_print_flag_F(variable, dir, i) == 1)
        len++;
    if (variable->delim != -1){
        for(int i = variable->delim - len; i > 0; i--) {
            mx_printstr(" ");
        }
    }
    else
        mx_printstr("\n");
}
