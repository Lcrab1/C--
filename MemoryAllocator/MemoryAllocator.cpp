
#include "MemoryAllocator.h"
#include <iostream>
#include <cstring>

MemoryAllocator::MemoryAllocator(size_t size) {
    memoryPool = malloc(size);
    totalSize = size;
    usedSize = 0;
}

MemoryAllocator::~MemoryAllocator() {
    free(memoryPool);
}

void* MemoryAllocator::allocate(size_t size) {
    if (usedSize + size > totalSize) {
        std::cerr << "Not enough memory!" << std::endl;
        return nullptr;
    }
    void* ptr = static_cast<char*>(memoryPool) + usedSize;
    usedSize += size;
    return ptr;
}

void MemoryAllocator::deallocate(void* ptr) {
    // For simplicity, this example does not implement deallocation.
    // In a real allocator, you would need to manage free blocks.
}

void MemoryAllocator::displayMemoryUsage() const {
    std::cout << "Total size: " << totalSize << " bytes" << std::endl;
    std::cout << "Used size: " << usedSize << " bytes" << std::endl;
}