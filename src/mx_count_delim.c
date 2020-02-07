#include "../inc/uls.h"
int mx_count_max_sym(t_array *dir, char link_or_size, int num_of_files) {
    int size = 0;
    int counter = 0;
    int max = 0;
    int flag = 0;
    for (int i = 0; i < num_of_files; i++) {
        counter = 0;
        if (link_or_size == 'l')
            size = dir->st[i]->st_nlink;
        else if (link_or_size == 's')
            size = dir->st[i]->st_size;
        else if (link_or_size == 'b')
            size = dir->st[i]->st_blocks;
        while (size > 0) {
            flag = 1;
            counter++;
            size /= 10;
        }
        if (counter > max)
            max = counter;
    }
    if (flag == 0)
        max = 1;
    return max;
}
int mx_count_delim(t_array *dir, t_var *variable, int num_of_files) {
    int delim = 8;
    int y = 0;
    for (int i = 0; i < num_of_files; i++) {
        y = mx_strlen(dir->names[i]);
        if (variable->flag_s == 1)
            y += mx_count_max_sym(dir, 'b', num_of_files) + 1;
        if (variable->flag_G == 1 && y >= delim && (isatty(1) != 0 || variable->flag_c == 0)) {
            delim = y + 1;
        }
        else if(y >= delim) {
            delim = (y/ 8) * 8 + 8;
        }
    }
    if (variable->flag_F == 1 && variable->flag_G == 0 && variable->flag_s == 0)
        delim += 8;
    return delim;
}
