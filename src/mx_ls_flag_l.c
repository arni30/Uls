#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir) {
    acl_t type = NULL;
    // ssize_t r = 0;
    // char *linkname = malloc((dir->st[1]->st_size + 1));
    //char *acl_text = malloc(sizeof(char*));
    //ssize_t *len = NULL;

    for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
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

        mx_printstr("LICENSE [");
        mx_printint(i);
        mx_printstr("]: ");
        type = acl_get_file(dir->names[i], ACL_TYPE_ACCESS);
        //printf("%s", acl_to_text (type, NULL));
        mx_printstr(acl_to_text (type, NULL));
        mx_printstr("       ");

        mx_printstr("\n");
    }
}
