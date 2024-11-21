#include<iostream>
using namespace std;

void Swap(int*arr,int pos1,int pos2){
    if(arr[pos1]!=arr[pos2]){
        arr[pos1] ^= arr[pos2];
        arr[pos2] ^= arr[pos1];
        arr[pos1] ^= arr[pos2];
    }
}

void quickSort(int*arr,int L,int R){
    if(L<R){
        //随机得到一个0-10的位置，并和最后一个位置的数字做交换，此时最后一个位置存放的是随机数
        Swap(arr, L + rand() % (R - L + 1), R);
        //用一个数组来接收partition的值，这个数组只需要两个元素，用来接收=区间的左下标和=区间的右下标
        int *equal = Partition(arr, L, R);
        quickSort(arr,L, equal[0] - 1);
        quickSort(arr, equal[1] + 1, R);
        delete equal;
    }

}

int *Partition(int*arr,int L,int R){
    int less = L - 1;
    int more = R;
    //遍历从L到more的所有元素
    while(L<more){
        //如果L指向的元素小于R指向的元素，L指向的值和小于区间后的值做交换
        if(arr[L]<arr[R]){
            Swap(arr, ++less, L++);
        }
        //如果L指向的元素大于R指向的元素，L指向的值和大于区间后的值做交换
        else if(arr[L]>arr[R]){
            Swap(arr, --more, L);//此时L不变，因为交换到L位置的数字还没有做比较
        }
        else{
            //L指向的元素等于R指向的元素，仅仅让L向后移动即可
            L++;
        }
    }
    //将选中的数放入大于区，即将R指向的数据和more指向的数据做交换
    Swap(arr, more, R);
    //用result数组来保存等于区间的左右边界
    int *result = new int[2];
    result[0] = less + 1;
    result[1] = more;
    return result;
}