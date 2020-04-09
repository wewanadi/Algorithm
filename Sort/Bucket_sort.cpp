#include <stdio.h>
#include <vector>
#include <iostream> 
#define bucket 10

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void bucket_sort(std::vector<int> &arr) {

}

int main () {
    int arr[] = {123,132,4543,5123,2341,6402,4739,123,5710,1927,4321};
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));
    
    std::cout << "original:\n";
    PrintArray(array);

    bucket_sort(array);
    std::cout << "sorted:\n";
    PrintArray(array);   

    return 0;
}
