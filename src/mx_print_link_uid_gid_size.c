#include "../inc/uls.h"

//соеденить в одну конструкцию функций

int mx_count_l_delim(int num_of_files, t_array *dir, int cur_name, char *to_name(t_array *dir, int n)) {
    int delim = 0;

    for (int i = 0; i < num_of_files; i++) {
        if(mx_strlen(to_name(dir, i)) > delim)
            delim = mx_strlen(to_name(dir, i));
    }
    delim = delim - cur_name + 2;
    return delim;
}

static void mx_uid_gid_yes(t_array *dir, int i, int num_of_files) {
    char *name = mx_uid_to_name(dir, i);
    int len_name = mx_strlen(name);
    char *size = NULL;
    int delim = 0;

    mx_printstr(name);
    for (int i = 0; i < mx_count_l_delim(num_of_files, dir, len_name, mx_uid_to_name); i++) {
        mx_printstr(" ");
    }
    name = mx_gid_to_name(dir, i);
    len_name = mx_strlen(name);
    mx_printstr(name);
    for (int i = 0; i < mx_count_l_delim(num_of_files, dir, len_name, mx_gid_to_name); i++) {
        mx_printstr(" ");
    }
    for (int y = 0; y < num_of_files; y++) {
        size = mx_itoa(dir->st[y]->st_size);
        if(mx_strlen(size) > delim)
            delim = mx_strlen(size);
        mx_strdel(&size);
    }
    size = mx_itoa(dir->st[i]->st_size);
    for (int y = 0; y < delim - mx_strlen(size); y++) {
        mx_printstr(" ");
    }
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
    mx_strdel(&size);
}

static void mx_gid_yes(t_array *dir, int i, int num_of_files) {
    char *name = mx_gid_to_name(dir, i);
    int len_name = mx_strlen(name);
    char *size = NULL;
    int delim = 0;

    mx_printstr(name);
    for (int i = 0; i < mx_count_l_delim(num_of_files, dir, len_name, mx_gid_to_name); i++) {
        mx_printstr(" ");
    }
    for (int y = 0; y < num_of_files; y++) {
        size = mx_itoa(dir->st[y]->st_size);
        if(mx_strlen(size) > delim)
            delim = mx_strlen(size);
        mx_strdel(&size);
    }
    size = mx_itoa(dir->st[i]->st_size);
    for (int y = 0; y < delim - mx_strlen(size); y++) {
        mx_printstr(" ");
    }
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}
static void mx_uid_yes(t_array *dir, int i, int num_of_files) {
    char *name = mx_uid_to_name(dir, i);
    int len_name = mx_strlen(name);
    char *size = NULL;
    int delim = 0;

    mx_printstr(name);
    for (int i = 0; i < mx_count_l_delim(num_of_files, dir, len_name, mx_uid_to_name); i++) {
        mx_printstr(" ");
    }
    for (int y = 0; y < num_of_files; y++) {
        size = mx_itoa(dir->st[y]->st_size);
        if(mx_strlen(size) > delim)
            delim = mx_strlen(size);
        mx_strdel(&size);
    }
    size = mx_itoa(dir->st[i]->st_size);
    for (int y = 0; y < delim - mx_strlen(size); y++) {
        mx_printstr(" ");
    }
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}



static void mx_gid_uid_no(t_array *dir, int i, int num_of_files) {
    char *size = NULL;
    int delim = 0;

    for (int y = 0; y < num_of_files; y++) {
        size = mx_itoa(dir->st[y]->st_size);
        if(mx_strlen(size) > delim)
            delim = mx_strlen(size);
        mx_strdel(&size);
    }
    size = mx_itoa(dir->st[i]->st_size);
    for (int y = 0; y < delim - mx_strlen(size) + 2; y++) {
        mx_printstr(" ");
    }
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
