#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir) {
    //acl_type_t **type = NULL;
    // ssize_t *r = NULL;
    // char **linkname = NULL;

    for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
        //linkname[i] = (char*)malloc((dir->st[i]->st_size + 1) * sizeof(char));
        //type = malloc(sizeof(type));
        mx_printstr("USER ID [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printstr(mx_uid_to_name(dir->st[i]->st_uid));
        mx_printstr("       ");

        mx_printstr("GROUP ID [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printint(dir->st[i]->st_gid);
        mx_printstr("       ");

        mx_printstr("LINKS [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printint(dir->st[i]->st_nlink);
        mx_printstr("       ");

        //r[i] = readlink("/", linkname[i], dir->st[i]->st_size + 1);
        mx_printstr("LICENSE [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printint(dir->st[i]->st_mode);
        //acl_get_file(dir->names[i], *type[i]);
        mx_printstr("       ");

        mx_printstr("\n");
    }
}
