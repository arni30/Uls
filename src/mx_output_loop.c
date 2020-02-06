#include "../inc/uls.h"

void mx_output_loop(t_array *dir, t_var *variable, int win_width,
                    void mx_print_output(int i, t_array *dir, t_var *variable, int num), int num_of_files) {
    int e_line = win_width / variable->delim;
    int e_col = 0;
    int isat = variable->delim;

    if (mx_find_flag(variable->argc1, variable->args, '1') == 1 || e_line < 1)
        e_line = num_of_files;
    e_line = count_el_in_line(num_of_files, e_line);
    e_col = (num_of_files / e_line);
    if (num_of_files % e_line != 0 )
        e_col += 1;
    for (int y = 0; y < e_col; y++) {

        for (int k = e_line,i = y; k != 0; k--, i += e_col) {
            if (i == 0 && isatty(1) == 0) {
                variable->delim -= 2;
            }
            if(i + e_col >= num_of_files){
                if(dir->names[i] != NULL) {
                    variable->delim = -1;
                    mx_print_output(i, dir, variable, num_of_files);
                    variable->delim = mx_count_delim(dir, variable, num_of_files);
                }
                break; //without last space
            }
            mx_print_output(i, dir, variable, num_of_files);
            variable->delim = isat;
        }
    }
}
