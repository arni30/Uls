#include "../inc/uls.h"

void mx_color_print(int i, t_array *dir, int delim) {
    if(dir->type[i] == DT_DIR){
        mx_printstr(MX_DIR);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    }
    else if(dir->type[i] == DT_REG){
        mx_printstr(MX_FILE);
        mx_print_dir(i, dir, delim);
    }
    else if(dir->type[i] == 0){
        mx_printstr(MX_EXEC);
        mx_print_dir(i, dir, delim);
        mx_printstr(MX_FILE);
    } 
}
