//my_alloc.h
#ifndef __MY_ALLOC_H
#define __MY_ALLOC_H

#include <stddef.h>

#define _GNU_SOURCE
#include <sys/mman.h>

#include <stdio.h>

void *my_alloc(size_t);
void clean(void *ptr);

#endif
