#include "../inc/uls.h"

static int count_l_delim(int num_of_files, t_array *dir, char *to_name(t_array *dir, int n)) {
    int delim = 0;
    char *temp = NULL;

    for (int i = 0; i < num_of_files; i++) {
        temp = to_name(dir, i);
        if (mx_strlen(temp) > delim)
            delim = mx_strlen(temp);
        mx_strdel(&temp);
    }
    delim = delim + 2;
    return delim;
}

void mx_ls_flag_l(t_array *dir, t_var *var, char *pos, int num) {
    char *path = NULL;

    var->gid_delim = count_l_delim(num, dir, mx_gid_to_name);
    var->uid_delim = count_l_delim(num, dir, mx_uid_to_name);
    if (var->flag_files == 0)
        mx_print_total(dir, num);
    for (int i = 0; i < num; i++) {
        path = mx_path(pos, dir->names[i], var->flag_files);
        mx_print_mode(dir, i, path, num);
        mx_print_link_uid_gid_size(dir, i, num, var);
        mx_print_time_name(dir, i, var);
        if (var->flag_G == 1 && isatty(1) == 1)
            mx_color_print(i, dir, var, num);
        else
            mx_print_dir(i, dir, var, num);
        mx_print_symlink(dir, i, path);
        mx_strdel(&path);
    }
}
