#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#include <sys/cdefs.h>

__BEGIN_DECLS
typedef uint32_t sem_t;

#ifdef __UK_SEMAPHORE_H__
#include <uk/semaphore.h>
#endif /*  __UK_SEMAPHORE_H__ */


__END_DECLS
#endif /*  _SEMAPHORE_H_  */