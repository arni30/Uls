#include "../inc/uls.h"

//int mx_strlen1(char *s){
//    int i = 0;
//    int count = 0;
//
//    while (s[i] != '\0') {
//        if (s[i] < 0)
//            count++;
//        i++;
//    }
//
//    return i - count / 2 + count % 2;
//}
//
//int mx_switch_len(int n, int *i, char *source) {
//    switch (n) {
//        case 0xD0: {
//            n = source[*i]; (*i)++;
//            if (n == 0x81) {
//                n = 0xA8;
//                break;
//            }
//            if (n >= 0x90 && n <= 0xBF)
//                n = n + 0x2F;
//            break;
//        }
//        case 0xD1: {
//            n = source[*i]; (*i)++;
//            if (n == 0x91) {
//                n = 0xB7;
//                break;
//            }
//            if (n >= 0x80 && n <= 0x8F)
//                n = n + 0x6F;
//            break;
//        }
//    }
//    return n;
//}
//
//int mx_mb_loop(unsigned char n, char *source, char *m) {
//    int counter = 0;
//    int i = 0;
//    int k = mx_strlen(source);
//    while (i < k) {
//        n = source[i];
//        i++;
//        if (n >= 0xBF){
//            n = mx_switch_len(n, &i, source);
//        }
//        m[0] = n;
//        counter++;
//    }
//    return counter;
//}
//
//
//int mb_strlen(char *source) {
//    int counter = 0;
//    unsigned char n = 0;
//    char m[2] = { '0', '\0' };
//
//    counter = mx_mb_loop(n, source, m);
//    if(counter == mx_strlen1(source)){
//        return counter;
//    }
//    else {
//        return counter - 2;
//    }
//}

void mx_print_dir(int i, t_array *dir, t_var *variable, int num) {
    char *s = mx_strdup(dir->names[i]);
    int len = mx_strlen(s);
    int count = 0;
    int n_a = 0;
    char *s_bl = mx_itoa(dir->st[i]->st_blocks);
    while (s[count]) {
        //mx_printint(sizeof((char*)s[count]));
        if(s[count] > 0) {
            n_a++;
        }
//        else if (s[count] == '\xd0' && s[count+1] == '\xb8') {
//            len--;
//            count++;
//        }
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
        if (mx_find_flag(variable->argc1, variable->args, 'G') == 1 && isatty(1) == 1)
            mx_printstr(MX_FILE);
        for(int i = variable->delim - len; i > 0; i--) {
            mx_printstr(" ");
        }
    }
    else
        mx_printstr("\n");
    free((void*)s);
}
