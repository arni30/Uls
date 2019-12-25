#include "../inc/uls.h"

void mx_output_loop(t_array *dir, int delim, int win_width, 
    void mx_print_output(int i, t_array *dir, int delim)) {
    int e_line = win_width / delim;
    int e_col = 0;
    int count = mx_count_arr_el(dir->names); 

    e_line = count_el_in_line(count, e_line);
    e_col = (count / e_line);    
    if (count % e_line != 0 ) {
        e_col += 1;
    }
    for (int y = 0; y < e_col; y++) {
        for (int k = e_line,i = y; k != 0; k--, i += e_col) {
            if(dir->names[i + e_col] == NULL){
                if(dir->names[i] != NULL)
                    mx_print_output(i, dir, -1);
                break; //without last space
            }
            mx_print_output(i, dir, delim);
        }
    }
}
