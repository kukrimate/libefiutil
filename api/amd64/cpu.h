/*
 * EFI CPU specific definitions for AMD64
 */

#ifndef __AMD64_CPU_H
#define __AMD64_CPU_H

/* Fixed width types */
#include <stdint.h>

/* Native width type */
typedef int64_t intn_t;
typedef uint64_t uintn_t;

/* Size type */
typedef uint64_t size_t;

/* Native max bit */
#define MAX_BIT ((uintn_t) 1 << 64)

/* EFI function calling convention */
#if defined __GNUC__ && !defined _WIN32
#define efi_func __attribute__((ms_abi))
#else
#define efi_func
#endif

#endif
