#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

void LCSlength(std::vector<int> &array1, std::vector<int> &array2, std::vector<int> &lcs) {
    int table[array1.size()+1][array2.size()+1];
    std::stack<int> tmp;

    //initialize table
    for (int i = 0; i <= array1.size();i++)
        for (int j = 0; j <= array2.size();j++)
            table[i][j] = 0;

    //set the table -> dp finding the i'th best case in array1 compare with every array2  
    for (int i = 1; i <= array1.size();i++)
        for (int j = 1; j <= array2.size();j++)
            if (array1[i-1]==array2[j-1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);

    //back trace -> only if table[i][j] = table[i-1][j-1]-1 ,means that we chose table[i][j] -> equal to array1[i-1] or array2[j-1]
    for (int i = array1.size(); i > 0;)
        for (int j = array2.size(); j > 0;)
            if (table[i][j]==table[i-1][j-1]) {
                i--;
                j--;
            }
            else if (table[i][j]==table[i-1][j])
                i--;
            else if (table[i][j]==table[i][j-1])
                j--;
            else {
                i--;
                j--;
                tmp.push(array1[i]);
            }
    //trans the back trace from stack to vector
    while (tmp.size())  {
        lcs.push_back(tmp.top());
        tmp.pop();
    }

    //print the table
    for (int i = 0; i <= array1.size(); i++){
        for (int j = 0; j <= array2.size(); j++)
            printf("%d  ", table[i][j]);
        printf("\n");
    }
}

void print(std::vector<int> &arr) {
    for (int i = 0; i < arr.size();i++)
        printf("%d ", arr[i]);
}

int main () {
    std::vector<int> array1 = {2,4,3,1,1,2,3,2};
    std::vector<int> array2 = {1,2,3,2,1,2};
    std::vector<int> lcs;

    LCSlength(array1, array2,lcs);

    print(lcs);
}
