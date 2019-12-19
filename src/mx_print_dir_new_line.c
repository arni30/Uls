#include "../inc/uls.h"

void mx_print_dir_new_line(t_array *dir, int delim, int count, int win_width) {
    int i;
    int y = 0;
    int e_line = win_width / delim;
    int e_col = 0;
    int k = 0;

    if (count > e_line) {
        while (count % e_line != 0 && count % e_line != e_line - 1){
            if(count % e_line != 0 || count % e_line != e_line - 1){
                break;
            }
            e_line--;
        }
    }
    e_col = (count / e_line);    
    if (count % e_line != 0 ) {
        e_col += 1;
    }
    while (y < e_col) {
        k = e_line;
        i = y;
        while (k != 1) {
            if(dir->names[i + 1] == NULL){
                break; //without last space
            }
            mx_print_dir(dir->names[i], delim);
            i += e_col;
            k--;
        }
        if(dir->names[i] != NULL){
            mx_printstr(dir->names[i]);//without last space
        }
        mx_printchar('\n');
        y++;
    }
}
