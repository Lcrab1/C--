
#include "MemoryAllocator.h"
#include <iostream>

int main() {
    MemoryAllocator allocator(1024); // 1 KB memory pool

    void* ptr1 = allocator.allocate(256);
    void* ptr2 = allocator.allocate(128);
    allocator.displayMemoryUsage();

    allocator.deallocate(ptr1);
    allocator.deallocate(ptr2);
    allocator.displayMemoryUsage();

    return 0;
}