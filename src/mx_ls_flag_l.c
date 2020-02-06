#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir, int flag_G, t_var *variable, char *position, int num_of_files, int flag_files) {
    if (flag_files == 0)
        mx_print_total(dir, num_of_files);
    for (int i = 0; i < num_of_files; i++) {
        mx_print_mode(dir, i, position,num_of_files);
        mx_print_link_uid_gid_size(dir, i, num_of_files, variable);
        mx_print_time_name(dir, i, flag_G, variable, num_of_files);
    }
}
