
#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H

class MemoryAllocator
{
public:
    MemoryAllocator(size_t size);
    ~MemoryAllocator();

    void *allocate(size_t size);
    void deallocate(void *ptr);
    void displayMemoryUsage() const;

private:
    void *memoryPool;
    size_t totalSize;
    size_t usedSize;
};

#endif // MEMORYALLOCATOR_H