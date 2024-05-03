//my_alloc.private.h
#ifndef __MY_ALLOC_PRIVATE_H
#define __MY_ALLOC_PRIVATE_H
#include "my_alloc.h"
#include <stddef.h>

enum chunk_type
{
    FREE=0,
    BUSY=1
};

struct chunk
{
    size_t size;
    enum chunk_type flags;
};

struct chunk *init_heap();
struct chunk *get_free_chunk(size_t s);

#endif
