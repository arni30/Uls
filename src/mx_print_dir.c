#include "../inc/uls.h"

static size_t utf8_char_length(char firstbyte) {
    if ((firstbyte & 0xC0) == 0xC0){
        if ((firstbyte & 0xF0) == 0xF0) {
            return 4;
        } else if ((firstbyte & 0xE0) == 0xE0) {
            return 3;
        } else {
            return 2;
        }
    }
    else {
        return 1;
    }
}
int mx_strlen_unicode(char *s){
    int i = 0;
    int l = 0;

    while (s[i] != '\0') {
        if (utf8_char_length(s[i]) != 1)
            l++;
        i+=utf8_char_length(s[i]);
    }
    i = 0;
    while (s[i] != '\0') {
        if (s[i] > 0)
            l++;
        i++;
    }
    return l;
}

void mx_print_dir(int i, t_array *dir, t_var *variable, int num) {
    char *s = mx_strdup(dir->names[i]);
    int len = mx_strlen(s);
    char *s_bl = mx_itoa(dir->st[i]->st_blocks);
    int n_a = 0;
    int count = 0;

    while (s[count]) {
        if (s[count] > 0) {
            n_a++;
        }
        count++;
    }
    if (mx_find_flag(variable->argc1, variable->args, 's') == 1 && mx_find_flag(variable->argc1, variable->args, 'G') == 0){
        for(int j = mx_count_max_sym(dir, 'b', num) - mx_strlen(s_bl); j > 0; j--) {
            mx_printstr(" ");
        }
        mx_printint(dir->st[i]->st_blocks);
        mx_printstr(" ");
    }
    mx_strdel(&s_bl);
//    if(len != (mx_strlen(s) - n_a) / 2 + (mx_strlen(s) - n_a) % 2 + n_a){
//        //len += 1;
//    }
    //mx_printint(len);
    len = (len - n_a) / 2 + (len - n_a) % 2 + n_a;
    mx_printstr(s);
    if (mx_find_flag(variable->argc1, variable->args, 's') == 0
        || mx_find_flag(variable->argc1, variable->args, 'G') == 1) {
        if (mx_print_flag_F(variable, dir, i) == -1)
            len--;
    }
    else {
        if (mx_print_flag_F(variable, dir, i) == 1)
            len++;
    }
    if (mx_find_flag(variable->argc1, variable->args, 's') == 1)
        len += mx_count_max_sym(dir, 'b', num) + 1;
    if (variable->delim != -1){
        mx_printstr(MX_FILE);
        for(int i = variable->delim - len; i > 0; i--) {
            mx_printstr(" ");
        }
    }
    else
        mx_printstr("\n");
    free((void*)s);
}
