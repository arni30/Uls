#include "../inc/uls.h"

void mx_output(t_array *dir, t_var *variable, int num_of_files, int flag_files) {
    int win_width = 0;

    win_width = mx_winsize();
    if (isatty(1) == 0 && mx_find_flag(variable->argc1, variable->args, 'C')==1)
        win_width = 80;
    variable->delim = mx_count_delim(dir, variable, num_of_files);

    if (mx_find_flag(variable->argc1, variable->args, 's') == 1 && flag_files == 0) {
        mx_print_total(dir, num_of_files);
    }
    if (mx_find_flag(variable->argc1, variable->args, '1') == 1)
        variable->delim = -1;
    if (isatty(1) == 0 && mx_find_flag(variable->argc1, variable->args, 'C') != 1) {
        variable->delim = -1;
        for (int i = 0; i < num_of_files; i++) {
            mx_print_dir(i, dir, variable, num_of_files);
        }
    }
    else if (mx_find_flag(variable->argc1, variable->args, 'G') == 1)
        mx_output_loop(dir, variable, win_width, mx_color_print, num_of_files);
    else
        mx_output_loop(dir, variable, win_width, mx_print_dir, num_of_files);
}
