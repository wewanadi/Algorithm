#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

int cut(std::vector<int> &stick,std::vector <int> &answer) {
    int table[stick.size()][stick.size()];

    for (int i = 0; i < stick.size(); i++)
        for (int j = 0; j < stick.size(); j++)
            table[i][j] = 0;

    //set [0,1] [1,2] [2,3] .... is the min-cut
    for (int i = 0; i < stick.size()-2 ;i++)
        table[i][i + 2] = stick[i + 2] - stick[i];

    //connunicate table[j][i+j] -> ex [0,4] is the min of [0,1]+[1,4] or [0,2]+[2,4] or [0,3]+[3,4] 
    //                          -> and then plus the cost of this cut = stick[i+j] - stick[j] 
    // [0,0] [0,1] [0,2] [0,3] [0,4]
    // [1,0] [1,1] [1,2] [1,3] [1,4]
    // [2,0] [2,1] [2,2] [2,3] [2,4]
    // [3,0] [3,1] [3,2] [3,3] [3,4]
    // [4,0] [4,1] [4,2] [4,3] [4,4]
    for (int i = 3; i < stick.size();i++)
        for (int j = 0,min=INT_MAX; j < stick.size()-i;j++) {
            for (int k = j + 1; k < i+j;k++)
                min = std::min(min, stick[i+j] - stick[j] + table[j][k] + table[k][i+j]);
            table[j][i+j] = min;
        }

    return table[0][stick.size()-1];
}


int main () {
    std::vector<int> stick = {0,4,5,7,8,10};
    std::vector<int> answer_set;

    printf("%d",cut(stick,answer_set));

    for (int i = answer_set.size()-1; i >=0 ;i--)
        printf("%d ", answer_set[i]);
}
