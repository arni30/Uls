#include "../inc/uls.h"

void mx_print_dir_flag_G(t_array *dir, int delim, int count, int win_width) {
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
    int a= 0;
    while(a < 6){
        mx_printstr(dir->names[a]);
        mx_printchar('-');
        printf("%c",dir->type[a]);
        mx_printchar('\n');
        a++;
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

            //
            if(dir->type[i] == DT_DIR){
                mx_printstr(MX_DIR);
                mx_print_dir(dir->names[i], delim);
                mx_printstr(MX_FILE);
            }
            if(dir->type[i] == DT_REG){
                mx_printstr(MX_FILE);
                mx_print_dir(dir->names[i], delim);
            }
            if(dir->type[i] == 0){
                mx_printstr(MX_EXEC);
                mx_print_dir(dir->names[i], delim);
                mx_printstr(MX_FILE);
            }
            //
            i += e_col;
            k--;
        }
        if(dir->names[i] != NULL){
            if(dir->type[i] == DT_DIR){
                mx_printstr(MX_DIR);
                mx_printstr(dir->names[i]);
                mx_printstr(MX_FILE);
            }
            if(dir->type[i] == DT_REG){
                mx_printstr(MX_FILE);
                mx_printstr(dir->names[i]);
            }
            if(dir->type[i] == 0){
                mx_printstr(MX_EXEC);
                mx_printstr(dir->names[i]);
                mx_printstr(MX_FILE);
            }//without last space
        }
        mx_printchar('\n');
        y++;
    }
}
