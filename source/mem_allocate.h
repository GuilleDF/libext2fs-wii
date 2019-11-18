#ifndef _MEM_ALLOCATE_H
#define _MEM_ALLOCATE_H

#include <malloc.h>

#if (defined(INCLUDE_INLINE_FUNCS) || !defined(NO_INLINE_FUNCS))
#ifdef INCLUDE_INLINE_FUNCS
#define _INLINE_ extern
#else
#ifdef __GNUC__
#define _INLINE_ extern __inline__
#else				/* For Watcom C */
#define _INLINE_ extern inline
#endif /* __GNUC__ */
#endif /* INCLUDE_INLINE_FUNCS */

_INLINE_ void* mem_alloc (size_t size) {
    return malloc(size);
}

_INLINE_ void* mem_calloc (size_t count, size_t size) {
    return calloc(count, size);
}

_INLINE_ void* mem_realloc (void *p, size_t size) {
    return realloc(p, size);
}

_INLINE_ void* mem_align (size_t a, size_t size) {
    #ifdef __wii__
    return memalign(a, size);
    #else
    return malloc(size);
    #endif
}

_INLINE_ void mem_free (void* mem) {
    free(mem);
}

#endif /* (defined(INCLUDE_INLINE_FUNCS) || !defined(NO_INLINE_FUNCS)) */

#endif /* _MEM_ALLOCATE_H */
