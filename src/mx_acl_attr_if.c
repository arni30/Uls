#include "../inc/uls.h"

int mx_acl_attr_if(int mode, char *str, char *curentFile){
    size_t size = 1024;
    char name[size];
    size_t size1 = 0;
    acl_t acl;
    int flag = 0;

    size1 = listxattr(curentFile, name,  size ,XATTR_SHOWCOMPRESSION);
    acl = acl_get_file(curentFile, ACL_TYPE_EXTENDED);
    if (size1 < 0)
        exit(1);
    if((S_IFMT & mode) == S_IFDIR)
        str[0]='d';
    if((S_IFMT & mode) == S_IFCHR)
        str[0]='c';
    if((S_IFMT & mode) == S_IFBLK)
        str[0]='b';
    if(size1 != 0) {
        str[10] = '@';
        flag = 1;
    }
    if(acl != NULL) {
        str[10] = '+';
        flag = 1;
    }
    acl_free(acl);
    return flag;
}
