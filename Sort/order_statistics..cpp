#include <stdio.h>
#include <vector>
#include <iostream> 
#define radixnumber 10

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
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

int order_statistics(std::vector<int> &arr,int front,int end,int index) {
    if (front ==end)    
        return arr[front];
    
    int pivot = quick_sort_partition(arr, front, end);
    int now = pivot - front + 1;

    if (now==index)
        return arr[pivot];
    
    if (now>index)      
        return order_statistics(arr, front, pivot - 1, index);
    else
        return order_statistics(arr, pivot + 1, end, index-now);
}

int main () {
    int arr[] = {1,9,2,8,3,7,4,6,5,0};
    int number;
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));
    
    std::cout << "original:\n";
    PrintArray(array);
    std::cout << "?'small:";
    std::cin >> number;
    int ans = order_statistics(array,0,array.size()-1,number);
    std::cout << "\n" << number << "'small:" << ans << "\n";
    
    return 0;
}
