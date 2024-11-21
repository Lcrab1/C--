#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
static char *mem_heap;
static char *mem_brk;
static char *mem_max_addr;
#define MAX_HEAP 1024 * 1024 // Define MAX_HEAP as 1MB

/*1.初始化内存系统模型*/
void mem_init(void)
{
    mem_heap = (char *)malloc(MAX_HEAP);
    mem_brk = (char *)mem_heap;
    mem_max_addr = (char *)(mem_heap + MAX_HEAP);
}

void *mem_sbrk(int incr)
{
    char *old_brk = mem_brk;
    if ((incr < 0) || (mem_brk + incr) > mem_brk)
    {
        errno = ENOMEM;
        //可以指定输出的文件流
        fprintf(stderr, "ERROR:mem_sbrk failed. Ran out of memory...\n");
        return (void *)-1;
    }
    mem_brk += incr;
    return (void *)old_brk;
}

/*2.操作空闲链表的基本常数和宏*/
#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1 << 12)
#define MAX(x, y) ((x) > (y) ? (x) : (y)) //宏定义中用括号包裹参数是为了确保宏在各种情况下都能正确地计算 避免出现运算符优先级造成的错误

/// size是 8字节对齐的
#define PACK(size, alloc) ((size) | (alloc))

/*向内存p中读写一个值*/
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

/*从地址p中读出 size 和 alloc 的值*/
#define GET_SIZE(p) (GET(p) & ~(0x7))
#define GET_ALLOC(p) (GET(p) & 0x1)

/*根据块指针bp，计算该块的头部和脚部的地址*/
#define HDRP(bp)    ((char*)(bp) - WSIZE)  //按照char*移动，移动4字节
#define FTRP(bp)    ((char*)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)
//#define FTRP(bp) ((char *)(bp) - WSIZE + GET_SIZE(HDRP(bp)) - WSIZE)

/*根据块指针bp，计算下一个块和之前块的地址*/
#define NEXT_BLKP(bp)   ((char*)(bp) + GET_SIZE(((char*)(bp) - WSIZE)))

#define PREV_BLKP(bp)   ((char*)(bp) - GET_SIZE(((char*)(bp) - DSIZE)))

/*3.创建初始空闲链表*/
