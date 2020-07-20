#include "../inc/uls.h"

int mx_strcmp_ls(const char *s1_, const char *s2_) {
    const unsigned char *s1 = (const unsigned char*) s1_;
    const unsigned char *s2 = (const unsigned char*) s2_;
    
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return 0;
}
