#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

void knapsack(std::vector<int> &c,std::vector <int> &w,int max_weight,std::vector <int> &answer) {
    int table[c.size() + 1][max_weight + 1];

    for (int i = 0; i < c.size() + 1;i++)
        for (int j = 0; j <= max_weight ;j++)
            table[i][j] = 0;

    //determine every subject from [0 -> max_weight]
    for (int i = 0; i < c.size(); i++) 
        for (int j = 0; j <= max_weight ;j++)
            if (j<w[i])     //if the weight isn't bigger than j -> take the best case before -> the upper one 
                table[i + 1][j] = table[i][j]; 
            else            //even if the weight is bigger but might not be the best cost
                table[i + 1][j] = std::max(table[i][j], table[i][j - w[i]] + c[i]);

    //backtrace -> two case (1)didn't count this item -> up (2)count -> up and go-left w[i] 
    //count happened only when table[i-1][j-w[i-1]] == table[i][j] - c[i-1]
    for (int i = c.size(),j = max_weight;j>=0,i>=0;i--){
        int from = table[i][j] - c[i - 1];
        int j_point = j - w[i - 1];
        if (from >= 0 && j_point >= 0 && from == table[i - 1][j - w[i - 1]])    {
            answer.push_back(i);
            j = j - w[i-1];
            }
        }
}


int main () {
    std::vector<int> cost = {3,4,5,6};
    std::vector<int> weight = {2,3,4,5};
    std::vector<int> answer_set;
    int max_weight = 5;

    knapsack(cost, weight,max_weight,answer_set);

    for (int i = answer_set.size()-1; i >=0 ;i--)
        printf("%d ", answer_set[i]);
}
