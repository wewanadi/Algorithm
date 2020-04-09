#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0xff
void PrintArray(std::vector<int> &array);

void selection_sort (std::vector<int> &arr,int size) {
    int min=MAX,index;
    for (int i = 0; i < size; i++,min=MAX)  {
        for (int j = i; j < size; j++)    {
            if (arr[j]<min)   {
                min = arr[j];
                index = j;
            }
        }
        std::swap(arr[i], arr[index]);
    }
}

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main () {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));

    std::cout << "original:\n";
    PrintArray(array);

    printf("[%d]", sizeof(arr) / 4);

    selection_sort(array,sizeof(arr)/4);
    std::cout << "sorted:\n";
    PrintArray(array);

    return 0;
}
