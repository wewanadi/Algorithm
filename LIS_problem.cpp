#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

void LIS(std::vector<int> &array, std::vector<int> &lis) {
    int table[array.size()];
    
    for (int i = 0; i < array.size();i++)
        table[i] = 1;

    for (int i = 0; i < array.size();i++) {
        for (int j = i+1; j < array.size();j++)
            if (array[i] < array[j])
                table[j]=std::max(table[j],table[i]+1);
    }

    int n=0;
    for (int i=0;i<array.size();i++)
        n = std::max(n, table[i]);

    std::stack <int> tmp;
    for (int i = array.size(); i >= 0;i--){
        if (table[i]==n)    {
            tmp.push(array[i]);
            n--;
        }
    }
    while (tmp.size())  {
        lis.push_back(tmp.top());
        tmp.pop();
    }
}

int LISlength(std::vector<int> &array) {
    std::vector<int> table{array[0]};

    for (int i = 1; i < array.size();i++)  {
        int n = array[i];
        if ( n > table.back() )  //Non-strictly Increasing is >=
            table.push_back(n);
        else
            *std::lower_bound(table.begin(), table.end(), n) = n;
    }
    return table.size();
}



int main () {
    std::vector<int> array {5,6,7,8,9,1,2,3,4,5,5,5,5,5,6};
    std::vector<int> lis;

    LISlength(array);
    LIS(array, lis);
    printf("[%d]", LISlength(array));
    for (int i = 0; i < lis.size(); i++)
        printf("%d ", lis[i]);
}