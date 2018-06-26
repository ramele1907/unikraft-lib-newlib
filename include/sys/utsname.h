/* libc/sys/linux/sys/utsname.h - System identification */

/* Written 2000 by Werner Almesberger */


#ifndef _SYS_UTSNAME_H
#define _SYS_UTSNAME_H

#include <sys/cdefs.h>

__BEGIN_DECLS

#define __UTSNAMELEN 65	/* synchronize with kernel */

struct utsname {
    char sysname[__UTSNAMELEN];
    char nodename[__UTSNAMELEN];
    char release[__UTSNAMELEN];
    char version[__UTSNAMELEN];
    char machine[__UTSNAMELEN];
    char domainname[__UTSNAMELEN];
};


int uname(struct utsname *name);

__END_DECLS

#endif