#include "../inc/uls.h"
//соеденить в одну конструкцию функций

static void print_size(t_array *dir, int i) {
    if ((dir->st[i]->st_mode & S_IFMT) != S_IFCHR
        || (dir->st[i]->st_mode & S_IFMT) != S_IFBLK)

        mx_printint(dir->st[i]->st_size);
    else {
        mx_printstr("  ");
        mx_printint(MX_MAJOR(dir->st[i]->st_rdev));
        mx_printstr(",   ");
        mx_printint(MX_MINOR(dir->st[i]->st_rdev));
    }
}


static void mx_uid_gid_yes(t_array *dir, int i, int num_of_files, t_var *variable)
{
    char *name = mx_uid_to_name(dir, i);
    int len_name = mx_strlen(name);
    char *size = NULL;
    int delim = 0;

    mx_printstr(name);
    write(1, "                            ", variable->uid_delim - len_name);
    mx_strdel(&name);
    name = mx_gid_to_name(dir, i);
    len_name = mx_strlen(name);
    mx_printstr(name);
    write(1, "                            ", variable->gid_delim - len_name);
    for (int y = 0; y < num_of_files; y++) {
        size = mx_itoa(dir->st[y]->st_size);
        if (mx_strlen(size) > delim)
            delim = mx_strlen(size);
        mx_strdel(&size);
    }
    size = mx_itoa(dir->st[i]->st_size);
    for (int y = 0; y < delim - mx_strlen(size); y++) {
        mx_printstr(" ");
    }
    print_size(dir, i);
    mx_printstr(" ");
    mx_strdel(&name);
    mx_strdel(&size);
}

static void mx_gid_yes(t_array *dir, int i, int num_of_files, t_var *variable) {
    char *name = mx_gid_to_name(dir, i);
    int len_name = mx_strlen(name);
    char *size = NULL;
    int delim = 0;

    mx_printstr(name);
    write(1, "                            ", variable->gid_delim - len_name);
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
    print_size(dir, i);
    mx_printstr(" ");
    mx_strdel(&name);
    mx_strdel(&size);
}
static void mx_uid_yes(t_array *dir, int i, int num_of_files, t_var *variable) {
    char *name = mx_uid_to_name(dir, i);
    int len_name = mx_strlen(name);
    char *size = NULL;
    int delim = 0;

    mx_printstr(name);
    write(1, "                            ", variable->uid_delim - len_name);
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
    print_size(dir, i);
    mx_printstr(" ");
    mx_strdel(&name);
    mx_strdel(&size);
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
    print_size(dir, i);
    mx_printstr(" ");
    mx_strdel(&size);
}


void mx_print_link_uid_gid_size(t_array *dir, int i, int num_of_files, t_var *variable) {
    mx_printint(dir->st[i]->st_nlink);
    mx_printstr(" ");
    if (variable->flag_o == 0 && variable->flag_g == 0)
        mx_uid_gid_yes(dir, i, num_of_files, variable);
    else if (variable->flag_o == 0 && variable->flag_g == 1)
        mx_gid_yes(dir, i, num_of_files, variable);
    else if (variable->flag_o == 1 && variable->flag_g == 0)
            mx_uid_yes(dir, i, num_of_files, variable);
    else if (variable->flag_o == 1 && variable->flag_g == 1)
        mx_gid_uid_no(dir, i, num_of_files);
}
