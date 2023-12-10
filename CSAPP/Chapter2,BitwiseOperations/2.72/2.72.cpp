//1.sizeof返回的数据类型为size_t，而size_t为unsigned类型，故整个表达式会被强转为无符号类型，总是大于等于0的，因此能够一直执行
#include<iostream>
#inlcude<stdlib.h>

void copy_int(int val,void *buf,int maxbytes){
    if(maxbytes-(int)sizeof(val)>=0){
        memcpy(buf, (void *)&val, sizeof(val));
    }
}