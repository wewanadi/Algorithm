#include <stdio.h>
#include <vector>
#include <iostream> 
#define radixnumber 10
#define MAX 0xff

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int median_of_median (std::vector<int> &arr,int front,int end)  {
    int size = end - front + 1;
    int min=MAX, index;
    std::vector<int> median;
    for (int i = 0; i < size; i+=5){
        for (int j = 0; j < 3; j++,min=MAX)
            for (int k = j; j < 5; k++)
                if (arr[front+i+j]<min) {
                    min = arr[front + i + j];
                    index = front + i + j;
                }
                median.push_back();
        }


}

int quick_sort_partition(std::vector<int> &arr,int front,int end) {
    //std::swap(arr[front+rand() % (front - end)], arr[end]);

    int last_small=front;
    for (int i = front; i < end;i++)    {
        if (arr[i]<arr[end]) {
            std::swap(arr[last_small], arr[i]);
            last_small++;
        }
    }
    std::swap(arr[last_small], arr[end]);
    return last_small;
}

void quick_sort(std::vector<int> &arr,int front,int end) {
    if (front<end) { 
        int pivot = quick_sort_partition(arr, front, end);
        quick_sort(arr, front, pivot-1);
        quick_sort(arr, pivot + 1, end);
    }
}

int main () {
    int arr[] = {1,6,4,7,2,3,6,1,2,7,5,3,2,3,8,2,3,1};
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));
    
    std::cout << "original:\n";
    PrintArray(array);
    quick_sort(array,0,array.size()-1);
    std::cout << "sorted:\n";
    PrintArray(array);   

    return 0;
}
