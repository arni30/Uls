#include "../inc/uls.h"

static int mx_count_l_delim(int num_of_files, t_array *dir, char *to_name(t_array *dir, int n)) {
    int delim = 0;

    for (int i = 0; i < num_of_files; i++) {
        if(mx_strlen(to_name(dir, i)) > delim)
            delim = mx_strlen(to_name(dir, i));
    }
    delim = delim + 2;
    return delim;
}

void mx_ls_flag_l(t_array *dir, int flag_G, t_var *variable, char *position, int num_of_files, int flag_files) {
    variable->gid_delim = mx_count_l_delim(num_of_files, dir, mx_gid_to_name);
    variable->uid_delim = mx_count_l_delim(num_of_files, dir, mx_uid_to_name);
    if (flag_files == 0)
        mx_print_total(dir, num_of_files);

    for (int i = 0; i < num_of_files; i++) {
        mx_print_mode(dir, i, position,num_of_files);
        mx_print_link_uid_gid_size(dir, i, num_of_files, variable);
        mx_print_time_name(dir, i, flag_G, variable, num_of_files);
    }
}
