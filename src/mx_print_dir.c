#include "../inc/uls.h"

void mx_print_dir(int i, t_array *dir, t_var *variable, int num) {
    char *s = mx_strdup(dir->names[i]);
    int len = mx_strlen(s);
    int count = 0;
    int n_a = 0;
    char *s_bl = mx_itoa(dir->st[i]->st_blocks);
    while (s[count]) {
        if(s[count] > 0) {
            n_a++;
        }
        count++;
    }
    if (variable->flag_s == 1 && (variable->flag_G == 0
        || (isatty(1) == 0))){
        for(int j = mx_count_max_sym(dir, 'b', num) - mx_strlen(s_bl); j > 0; j--) {
            mx_printstr(" ");
        }
        mx_printint(dir->st[i]->st_blocks);
        mx_printstr(" ");
    }
    mx_strdel(&s_bl);
    len = (len - n_a) / 2 + (len - n_a) % 2 + n_a;
    mx_printstr(s);
    if (variable->flag_G == 1) {
        if (mx_print_flag_F(variable, dir, i) == -1)
            len--;
    }
    else {
        if (mx_print_flag_F(variable, dir, i) == 1)
            len++;
    }
    if (variable->flag_s == 1)
        len += mx_count_max_sym(dir, 'b', num) + 1;
    if (variable->delim != -1){
        if (variable->flag_G == 1 && isatty(1) == 1)
            mx_printstr(MX_FILE);
        for(int i = variable->delim - len; i > 0; i--) {
            mx_printstr(" ");
        }
    }
    else
        mx_printstr("\n");
    free((void*)s);
}
