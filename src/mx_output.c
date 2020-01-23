#include "../inc/uls.h"

void mx_output(t_array *dir, t_var *variable) {
    int win_width = 0;
    int count;


    win_width = mx_winsize();
    if (isatty(1) == 0 && mx_find_flag(variable->argc1, variable->args, 'C')==1)
         win_width = 80;
    count = mx_count_arr_el(dir->names);
    variable->delim = mx_count_delim(dir->names, variable->argc1, variable->args);

    if (mx_find_flag(variable->argc1, variable->args, 's') == 1) {
        mx_print_total(dir);
        mx_printstr(" ");
    }
    if (mx_find_flag(variable->argc1, variable->args, '1') == 1)
            variable->delim = -1;
    if (isatty(1) == 0 && mx_find_flag(variable->argc1, variable->args, 'C') != 1) {
        variable->delim = -1;
        for (int i = 0; i < count; i++) {
            mx_print_dir(i, dir, variable);
        }
        variable->delim = mx_count_delim(dir->names, variable->argc1, variable->args);
    }
    else if (mx_find_flag(variable->argc1, variable->args, 'G') == 1)
        mx_output_loop(dir, variable, win_width, mx_color_print);
    else 
        mx_output_loop(dir, variable, win_width, mx_print_dir);
}
