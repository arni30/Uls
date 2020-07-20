#include "../inc/uls.h"

static int count_ascii(char *s) {
    int count = 0;
    int n_a = 0;

    while (s[count]) {
        if (s[count] > 0) {
            n_a++;
        }
        count++;
    }
    return n_a;
}

static int count_len(int i, t_array *d, t_var *v, int n) {
    int len = mx_strlen(d->names[i]);
    int n_a = count_ascii(d->names[i]);

    len = (len - n_a) / 2 + (len - n_a) % 2 + n_a;
    if (v->flag_G == 1) {
        if (mx_print_flag_F(v, d, i) == -1)
            len--;
    }
    else {
        if (mx_print_flag_F(v, d, i) == 1)
            len++;
    }
    if (v->flag_s == 1)
        len += mx_count_max_sym(d, 'b', n) + 1;
    return len;
}

void mx_print_dir(int i, t_array *d, t_var *v, int n) {
    int len = count_len(i, d, v, n);
    char *bl = mx_itoa(d->st[i]->st_blocks);

    if (v->flag_s == 1 && (v->flag_G == 0 || (isatty(1) == 0))){
        for (int j = mx_count_max_sym(d, 'b', n) - mx_strlen(bl); j > 0; j--) {
            mx_printstr(" ");
        }
        mx_printint(d->st[i]->st_blocks);
        mx_printstr(" ");
    }
    mx_strdel(&bl);
    mx_printstr(d->names[i]);
    if (v->flag_G == 1 && isatty(1) == 1)
        mx_printstr(MX_FILE);
    if (v->delim != -1){
        for (int i = v->delim - len; i > 0; i--)
            mx_printstr(" ");
    }
    else
        mx_printstr("\n");
}
