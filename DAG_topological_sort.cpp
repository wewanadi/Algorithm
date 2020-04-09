#include <vector>
#include <iostream>
#include <queue>
#define from first
#define to second
#define in_degree first
#define vertix second
#define N 15

void construct (std::vector<std::pair<int, int>> &edge,std::vector<int> (&graph)[N])   {
    for (int i = 0; i < edge.size();i++)
        graph[edge[i].from].push_back(edge[i].to);
}

void topological_sort(std::vector<std::pair<int, int>> &edge,int start,std::vector<int> &DAG) {
    std::vector<int> graph[N];
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int> >,std::greater<std::pair<int, int> > > min_heap;
    construct(edge, graph);
    int in_degree[N];

    for (int i = 0; i < N;i++)
        in_degree[i]=0;

    for (int i = 0; i < edge.size(); i++)
        in_degree[edge[i].to]++;

    for (int i = 0; i < N;i++)
        min_heap.push({in_degree[i],i});

    while (!min_heap.top().in_degree) {
        std::pair<int, int> tmp = min_heap.top();
        min_heap.pop();
        for (int i = 0; i < graph[tmp.vertix].size();i++) {
            in_degree[graph[tmp.vertix][i]]--;
            min_heap.push({in_degree[graph[tmp.vertix][i]], graph[tmp.vertix][i]});
        }
        DAG.push_back(tmp.vertix);
    }
}

int main () {
    std::vector<std::pair<int, int>> edge = {{0,2}, {1,2}, {2,7}, {2,6}, {3,4}, {4,5}, {5,6}, {5,14}, {6,8}, {6,9}, {6,11}, {6,12}, {7,8}, {9,10}, {12,13} };
    std::vector<int> DAG;

    topological_sort(edge, 0, DAG);

    std::cout << " DAG:";
    for (int i = 0; i < N;i++)
        std::cout << DAG[i] << " ";
    return 0;
}