#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int tmp=a;
    a=b;
    b=tmp;
}
/**
  * @arr 待排序的数组
  * @begin 需要partition的起始下标
  * @end 需要partition的末尾下标
  * @return 返回pivot所在位置下标
  */
int partition(int * arr, int begin, int end) {
    int pivot=arr[begin];
    swap(arr[begin],arr[end]);

    int low=begin, high=end;
    while(low < high){
        while(low<high && arr[low]<=pivot) low++;
        // 如果没有等号，arr[low]==arr[high]时死循环
        // 算法不稳定，可能改变相等值相对顺序
        while(low<high && arr[high]>=pivot) high--;
        if(low<high) swap(arr[low], arr[high]);
    }
    // 因为 low 先走，此时arr[low]值大于等于 pivot 值
    swap(arr[low], arr[end]);
    return low;
}

void quicksort(int *arr,int begin,int end){
    if(begin < end){
        int p=partition(arr,begin,end);
        quicksort(arr,begin,p-1);
        // +1 -1 将p处孤立出来
        quicksort(arr,p+1,end);
    }
}

int main(){
    int arr[8]{13,5,7,3,8,4,5,3};
    quicksort(arr,0,7);
    for (int i=0;i<8;i++) cout << arr[i] << endl;
    return 0;
}
