#include "../inc/uls.h"

void mx_error_flag(int argc, char **flags){
    char *us_f = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
    int flag = 0;
    DIR *dp;
    for (int i = 1; i < argc; i++) {
        dp = opendir(flags[i]);
        if (flags[i][0] != '-' && dp == NULL){
            mx_error_dir(flags, i);
            exit(1);
        }
        for (int j =1; flags[i][j] != '\0'; j++){
            flag = 0;
            for (int count = 0;us_f[count] != '\0'; count++) {
                if (us_f[count] == flags[i][j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                mx_print_error_flag(i, j, flags);
        }
        if (dp != NULL)
            closedir(dp);
    }
}
