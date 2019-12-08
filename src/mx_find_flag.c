#include "../inc/uls.h"

int mx_find_flag(int argc, char **flags, char flag){
    int count = 0;
    int j = 0;

    for (int i = 1; i < argc; i++) {
        j = 1;
        while (flags[i][j] != '\0') {
            if (flag == flags[i][j]) {
                return 1;
            }
            count++;
        }
        j++;          
    }
    return 0;
}
