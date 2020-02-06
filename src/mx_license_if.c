#include "../inc/uls.h"

void mx_license_if(int mode, char *str) {
    if(mode & S_IRUSR)
        str[1]='r';
    if(mode & S_IWUSR)
        str[2]='w';
    if(mode & S_IXUSR)
        str[3]='x';
    if(mode & S_IRGRP)
        str[4]='r';
    if(mode & S_IWGRP)
        str[5]='w';
    if(mode & S_IXGRP)
        str[6]='x';
    if(mode & S_IROTH)
        str[7]='r';
    if(mode & S_IWOTH)
        str[8]='w';
    if(mode & S_IXOTH)
        str[9]='x';
}
