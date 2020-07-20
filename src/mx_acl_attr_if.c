#include "../inc/uls.h"

void mx_licens_ifmt(int mode, char *str) {
    if ((S_IFMT & mode) == S_IFDIR)
        str[0]='d';
    else if ((S_IFMT & mode) == S_IFCHR)
        str[0]='c';
    else if ((S_IFMT & mode) == S_IFBLK)
        str[0]='b';
    else if ((S_IFMT & mode) == S_IFSOCK)
        str[0] = 's';
    else if ((S_IFMT & mode) == S_IFIFO)
        str[0] = 'p';
    else if ((S_IFMT & mode) == S_IFLNK)
        str[0] = 'l';
}

void mx_acl_attr_if(int mode, char *str, char *curentFile, char *name) {
    size_t xattr = 0;
    acl_t acl;

    xattr = listxattr(curentFile, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(curentFile, ACL_TYPE_EXTENDED);
    mx_licens_ifmt(mode, str);
    if(mx_strcmp(name, "dojo") != 0 && mx_strcmp(name, "sudo") != 0
        && mx_strcmp(curentFile, "/dev/null") != 0) {
        if (mx_strcmp(name, "App Store.app") == 0 && xattr > 0 && acl != NULL)
            str[10] = '+';
        else if (xattr > 0)
            str[10] = '@';
        else if (acl != NULL)
            str[10] = '+';
        acl_free(acl);
    }
}
