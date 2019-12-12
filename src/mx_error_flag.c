#include "../inc/uls.h"

void mx_error_flag(int argc, char **flags){
    char *us_f = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
    int count = 0;
    int j = 0;
    int flag = 0;

    for (int i = 1; i < argc; i++) {
        if (flags[i][0] != '-' && opendir(flags[i]) == NULL){
            mx_error_dir(flags, i);
            exit(1);
        }  
        j = 1;
        while (flags[i][j] != '\0'){
            count = 0;
            flag = 0;
            while (us_f[count] != '\0') {
                if (us_f[count] == flags[i][j]) {
                    flag = 1;
                    break;
                }
                count++;
            }
            if(flag == 0){
                mx_print_error_flag(i, j, flags);
            }
            j++;          
        }
    }
}
