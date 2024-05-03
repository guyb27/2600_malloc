#include <criterion/criterion.h>

#include "include/my_alloc.h"
#include "include/my_alloc.private.h"

Test(simple, simple_map_01)
{
    // utilisation simple d'un mmap
    char *ptr = mmap((void*)(4096*100000), 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    cr_assert(ptr != NULL, "Failed to mmap");
}

Test(simple, simple_map_02)
{
    // utilisation simple d'un mmap
    char *ptr1 = (char*)my_alloc(12);
    cr_assert(ptr1 != NULL, "Failed to alloc ptr1");
    char *ptr2 = (char*)my_alloc(25);
    cr_assert(ptr2 != NULL, "Failed to alloc ptr2");
    //cr_assert(ptr1 != ptr2, "Failed to alloc ptr2 != ptr1");
    printf("ptr1: [%p]\nptr2: [%p]\nsizeof(struct chunk): [%lx]\n",
        &ptr1, &ptr2, sizeof(struct chunk)
    );
    cr_assert((size_t)ptr2 == (size_t)ptr1 + 12 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1+12+sizeof(struct chunk)); /* : %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 12 + (sizeof (struct chunk)); */
    char *ptr3 = (char*)my_alloc(55);
    cr_assert((size_t)ptr3 == (size_t)ptr2 + 25 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr3, (size_t)ptr2+25+sizeof(struct chunk));/*  : %lx - %lx", (size_t)ptr3, (size_t)ptr2 + 25 + (sizeof (struct chunk))); */
}

Test(simple, simple_map_03)
{
    // utilisation simple d'un mmap
    char *ptr1 = (char*)my_alloc(12);
    cr_assert(ptr1 != NULL, "Failed to alloc ptr1");
    char *ptr2 = (char*)my_alloc(25);
    cr_assert(ptr2 != NULL, "Failed to alloc ptr2");
    //cr_assert(ptr1 != ptr2, "Failed to alloc ptr2 != ptr1");
    printf("ptr1: [%p]\nptr2: [%p]\nsizeof(struct chunk): [%lx]\n",
        &ptr1, &ptr2, sizeof(struct chunk)
    );
    cr_assert((size_t)ptr2 == (size_t)ptr1 + 12 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1+12+sizeof(struct chunk)); /* : %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 12 + (sizeof (struct chunk)); */
    char *ptr3 = (char*)my_alloc(55);
    cr_assert((size_t)ptr3 == (size_t)ptr2 + 25 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr3, (size_t)ptr2+25+sizeof(struct chunk));/*  : %lx - %lx", (size_t)ptr3, (size_t)ptr2 + 25 + (sizeof (struct chunk))); */
    printf("clean ptr2\n");
    clean(ptr2);
    printf("clean ptr3\n");
    clean(ptr3);
    struct chunk *t = (struct chunk*)((size_t)ptr2 - sizeof(struct chunk));
    printf("t: %lu\n", t->size);
    cr_assert((size_t)t->size==25+55+3940+2*sizeof(struct chunk), "Failed to clean");

}

Test(simple, simple_map_04)
{
    // utilisation simple d'un mmap
    char *ptr1 = (char*)my_alloc(12);
    cr_assert(ptr1 != NULL, "Failed to alloc ptr1");
    char *ptr2 = (char*)my_alloc(25);
    cr_assert(ptr2 != NULL, "Failed to alloc ptr2");
    //cr_assert(ptr1 != ptr2, "Failed to alloc ptr2 != ptr1");
    printf("ptr1: [%p]\nptr2: [%p]\nsizeof(struct chunk): [%lx]\n",
        &ptr1, &ptr2, sizeof(struct chunk)
    );
    cr_assert((size_t)ptr2 == (size_t)ptr1 + 12 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1+12+sizeof(struct chunk)); /* : %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 12 + (sizeof (struct chunk)); */
    char *ptr3 = (char*)my_alloc(55);
    cr_assert((size_t)ptr3 == (size_t)ptr2 + 25 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr3, (size_t)ptr2+25+sizeof(struct chunk));/*  : %lx - %lx", (size_t)ptr3, (size_t)ptr2 + 25 + (sizeof (struct chunk))); */
    printf("clean ptr1\n");
    clean(ptr1);
    printf("clean ptr2\n");
    clean(ptr2);
    struct chunk *t = (struct chunk*)((size_t)ptr1 - sizeof(struct chunk));
    printf("t: %lu\n", t->size);
    cr_assert((size_t)t->size==12+25+sizeof(struct chunk), "Failed to clean");

}
/*
Test(simple, simple_map_05)
{
    // utilisation simple d'un mmap
    char *ptr1 = (char*)my_alloc(8192);
    cr_assert(ptr1 != NULL, "Failed to alloc ptr1");
    char *ptr2 = (char*)my_alloc(25);
    cr_assert(ptr2 != NULL, "Failed to alloc ptr2");
    //cr_assert(ptr1 != ptr2, "Failed to alloc ptr2 != ptr1");
    printf("ptr1: [%p]\nptr2: [%p]\nsizeof(struct chunk): [%lx]\n",
        &ptr1, &ptr2, sizeof(struct chunk)
    );
    cr_assert((size_t)ptr2 == (size_t)ptr1 + 12 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1+12+sizeof(struct chunk)); // : %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 12 + (sizeof (struct chunk));
    char *ptr3 = (char*)my_alloc(55);
    cr_assert((size_t)ptr3 == (size_t)ptr2 + 25 + sizeof(struct chunk),
        "Failed to alloc: %lx - %lx", (size_t)ptr3, (size_t)ptr2+25+sizeof(struct chunk));//  : %lx - %lx", (size_t)ptr3, (size_t)ptr2 + 25 + (sizeof (struct chunk)));
    printf("clean ptr1\n");
    clean(ptr1);
    printf("clean ptr2\n");
    clean(ptr2);
    struct chunk *t = (struct chunk*)((size_t)ptr1 - sizeof(struct chunk));
    printf("t: %lu\n", t->size);
    cr_assert((size_t)t->size==12+25+sizeof(struct chunk), "Failed to clean");

}
*/

Test(simple, simple_map_05)
{
    // utilisation simple d'un mmap
    char *ptr1 = (char*)my_alloc(8192);
    cr_assert(ptr1 != NULL, "Failed to alloc ptr1");
}

//test.c
/*
#include <criterion/criterion.h>
#include <sys/mman.h>
#include ""

Test(simple, simple_map_01)
{
    //utilisation simple d un mmap
    char *ptr=mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    cr_Assert(ptr != NULL, "Failed to mmap")
}


Test(simple, simple_map_02)
{
    char *ptr1 = alloc(12);
    cr_Assert(ptr1 != NULL, "Failed to alloc");
    char *ptr2 = alloc(25);
    cr_Assert(ptr2 != NULL, "Failed to alloc");
    cr_Assert((size_t)ptr2 ==(size_t)ptr1 + 12 + (sizeof(struct chunk)),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 12 + (sizeof(struct chunk)));
        
    
    char *ptr3 = alloc(25);
    cr_Assert(ptr2 != NULL, "Failed to alloc");
    cr_Assert((size_t)ptr2 ==(size_t)ptr1 + 25 + (sizeof(struct chunk)),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 25 + (sizeof(struct chunk)));
}
*/
//clean()//libere la memoire
//alloc(8192)
//(Test)-> utiliser la fonction mremap()