//test.c

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
    cr_Assert(ptr1 != NULL, "Failed to alloc ptr1");
    char *ptr2 = alloc(25);
    cr_Assert(ptr2 != NULL, "Failed to alloc");
    cr_Assert((size_t)ptr2 ==(size_t)ptr1 + 12 + (sizeof(struct chunk)),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 12 + (sizeof(struct chunk)));
        
    
    char *ptr3 = alloc(25);
    cr_Assert(ptr2 != NULL, "Failed to alloc");
    cr_Assert((size_t)ptr2 ==(size_t)ptr1 + 25 + (sizeof(struct chunk)),
        "Failed to alloc: %lx - %lx", (size_t)ptr2, (size_t)ptr1 + 25 + (sizeof(struct chunk)));
}

//clean()//libere la memoire
//alloc(8192)
//(Test)-> utiliser la fonction mremap()