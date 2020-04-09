//Brutal_search of MAX_LIS
#include <stdio.h>
#include <vector>

int MAXLIS (std::vector<int> &list,int &max,int n,int value)    {
    max = std::max(max, value);
    if (n == list.size()-1)
        return max;
    if ( list[n] > value % 10 )
        MAXLIS(list, max, n + 1, value * 10 + list[n]);
    MAXLIS(list, max, n + 1, value);
    return max;
}


int main () {
    std::vector<int> list{6, 4, 3, 7, 9, 8};
    int max=0;

    printf ("%d",MAXLIS(list ,max,0,0));
    return 0;
}