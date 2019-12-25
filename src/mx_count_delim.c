#include "../inc/uls.h"

int mx_count_delim(char **dir, int argc, char **argv) {
    int count = 0;
    int delim = 8;
    int i = 0;

    while (dir[count]) {
        i = 0;
        while(dir[count][i]){
            i++;
        }
        if (mx_find_flag(argc , argv, 'G') == 1 && i >= delim) {
            delim = i + 1;
        }
        else if(i >= delim) {
            delim = (i / 8) * 8 + 8;
        }
        count++;
    }
    return delim;
}
