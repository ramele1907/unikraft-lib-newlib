/* from musl */
#ifndef	_SYS_UN_H
#define	_SYS_UN_H

#include <sys/cdefs.h>

__BEGIN_DECLS

#define __NEED_sa_family_t
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_size_t
#endif


struct sockaddr_un {
	sa_family_t sun_family;
	char sun_path[108];
};

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
size_t strlen(const char *);
#define SUN_LEN(s) (2+strlen((s)->sun_path))
#endif

__END_DECLS

#endif
