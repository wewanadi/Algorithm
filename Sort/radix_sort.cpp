#include <stdio.h>
#include <vector>
#include <iostream> 
#define radixnumber 10
#define digit 10

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void radix_sort(std::vector<int> &arr) {
    std::vector<int> table[radixnumber];
    int radix = 1;
    int now,rond=0;

    while (rond<digit) {
        for (int i = 0; i < arr.size(); i++) {
            now = (arr[i] / radix)%radixnumber;
            table[now].push_back(arr[i]);
        }

        arr.clear();
        for (int i = 0; i < radixnumber; i++)   {
            arr.insert(arr.end(),table[i].begin(),table[i].end());
            table[i].clear();
        }
        radix *= radixnumber;
        rond++;
    }
}

int main () {
    int arr[] = {123,132,4543,5123,2341,6402,4739,123,5710,1927,4321};
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));
    
    std::cout << "original:\n";
    PrintArray(array);

    radix_sort(array);
    std::cout << "sorted:\n";
    PrintArray(array);   

    return 0;
}
