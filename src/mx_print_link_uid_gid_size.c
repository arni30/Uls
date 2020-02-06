#include "../inc/uls.h"

static void mx_uid_gid_yes(t_array *dir, int i, int num_of_files) {
    int size = 0;
    int counter = 0;

    mx_uid_to_name(dir->st[i]->st_uid);
    mx_printstr("  ");
    size = dir->st[i]->st_size;
    if (size == 0)
        counter = 1;
    while (size > 0) {
        counter++;
        size /= 10;
    }
    mx_gid_to_name(dir->st[i]->st_gid);
    write(1, "       ", mx_count_max_sym(dir, 's', num_of_files) + 2 - counter);
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}

static void mx_gid_yes(t_array *dir, int i, int num_of_files) {
    int size = 0;
    int counter = 0;

    size = dir->st[i]->st_size;
    if (size == 0)
        counter = 1;
    while (size > 0) {
        counter++;
        size /= 10;
    }
    mx_gid_to_name(dir->st[i]->st_gid);
    write(1, "       ", mx_count_max_sym(dir, 's', num_of_files) + 2 - counter);
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}
static void mx_uid_yes(t_array *dir, int i, int num_of_files) {
    int size = 0;
    int counter = 0;

    mx_uid_to_name(dir->st[i]->st_uid);
    size = dir->st[i]->st_size;
    if (size == 0)
        counter = 1;
    while (size > 0) {
        counter++;
        size /= 10;
    }
    write(1, "       ", mx_count_max_sym(dir, 's', num_of_files) + 2 - counter);
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}



static void mx_gid_uid_no(t_array *dir, int i, int num_of_files) {
    int size = 0;
    int counter = 0;

    size = dir->st[i]->st_size;
    if (size == 0)
        counter = 1;
    while (size > 0) {
        counter++;
        size /= 10;
    }
    write(1, "       ", mx_count_max_sym(dir, 's', num_of_files) + 2 - counter);
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}


void mx_print_link_uid_gid_size(t_array *dir, int i, int num_of_files, t_var *variable) {
    mx_printint(dir->st[i]->st_nlink);
    mx_printstr(" ");
    if (mx_find_flag(variable->argc1, variable->args, 'o') == 0
        && mx_find_flag(variable->argc1, variable->args, 'g') == 0)
        mx_uid_gid_yes(dir, i, num_of_files);
    else if (mx_find_flag(variable->argc1, variable->args, 'o') == 0
        && mx_find_flag(variable->argc1, variable->args, 'g') == 1)
        mx_gid_yes(dir, i, num_of_files);
    else if (mx_find_flag(variable->argc1, variable->args, 'o') == 1
        && mx_find_flag(variable->argc1, variable->args, 'g') == 0)
            mx_uid_yes(dir, i, num_of_files);
    else if (mx_find_flag(variable->argc1, variable->args, 'o') == 1
        && mx_find_flag(variable->argc1, variable->args, 'g') == 1)
        mx_gid_uid_no(dir, i, num_of_files);


}
