#include<iostream>
using namespace std;
#include<cstring>



void* another_calloc(size_t nmemb,size_t size){
    int mask = -1;
    //此处的乘法可能会溢出
    size_t buf_size = nmemb * size;
    int flag = nmemb & mask && size & mask;
    void *ret = nullptr;
    //若 nmemb或size为0，则calloc返回nullptr
    !flag && (ret=nullptr);
    //若nmemb和size均不为0,则执行分配
    //判断是否溢出，若溢出则不会继续执行之后的操作
    flag && (buf_size / size == nmemb) && (ret = malloc(buf_size)) && memset(ret, 0, buf_size);

    return ret;

}

void* another_calloc1(size_t nmemb,size_t size){
  
    if(nmemb==0||size==0){
        return nullptr;
    }
    size_t buf_size = nmemb * size;
    void *ptr=nullptr;
    if(buf_size/size==nmemb){   //判断是否溢出
                                // malloc()分配的是总字节数
        // void* malloc(size_t size);
        ptr=malloc(buf_size);
        if(ptr!=nullptr){
            //memset初始化的数量也是总字节数
            //void *memset(void*s,int c,size_t n)
            memset(ptr, 0, buf_size);
        }
        return ptr;
    }
    return ptr;
}

int main(){
    void *p;
    p = another_calloc(0x1234, 1);
    free(p);
    system("pause");
}