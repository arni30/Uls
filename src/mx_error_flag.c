#include "../inc/uls.h"

void mx_error_flag(int argc, char **flags){
    char *us_f = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
    int count = 0;
    int flag = 0;
    int j = 0;

    for (int i = 1; i < argc; i++) {
        count = 0;
        if (flags[i][0] != '-'){
            mx_error_dir(flags, i);
        }  
        while (us_f[count] != '\0'){
            j = 0;
            flag = 0;
            while (flags[i][j] != '\0') {
                if (us_f[count] == flags[i][j]) {
                    flag = 1;
                    break;
                }
                j++;
            }
            if (flag == 0) {
                mx_print_error_flag(i, j,flags);
            }
            count++;
        }
    }
}
