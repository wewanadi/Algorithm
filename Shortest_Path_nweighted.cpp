//Undirected graph
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define N 10
#define NOT_VISIT -1

void construct(const std::vector<std::pair<int, int> > &edge, std::vector<int> (&neighbor)[N])    {
    for (int i = 0; i < edge.size();i++)    {
        neighbor[edge[i].first].push_back(edge[i].second);
        neighbor[edge[i].second].push_back(edge[i].first);
    }
}

void Breadth_first_search ( std::vector<int> (&neighbor)[N], int (&bfs)[N],int outset)   {
    for (int i=0;i<N;i++)
        bfs[i] = NOT_VISIT;
    bfs[outset] = 0;
    std::queue<int> flow;

    flow.push(outset);
    while (flow.size()) {
        int now= flow.front();
        for (int i = 0; i < neighbor[now].size();i++)   {
            int to = neighbor[now][i];
            if (bfs[to] == NOT_VISIT) {
            bfs[to] = bfs[now] + 1;
            flow.push(to);
            }
        }
        flow.pop();
    }
}

void DFS_visit (const std::vector<int> (&neighbor)[N], int (&dfs)[N],int now)   {
    for (int i = 0; i < neighbor[now].size();i++)   {
        int to = neighbor[now][i];
        if (dfs[to]==NOT_VISIT || dfs[to] > dfs[now]+1)    {
            dfs[to] = dfs[now] + 1;
            DFS_visit(neighbor, dfs, to);
        }
    }
}

void Depth_first_search (const std::vector<int> (&neighbor)[N], int (&dfs)[N],int outset)   {
    for (int i = 0; i < N;i++)
        dfs[i] = NOT_VISIT;
    dfs[outset] = 0;
    DFS_visit(neighbor, dfs ,outset);
}

int main () {
    std::vector<std::pair<int, int> > edge = {{0,1},{0,2},{1,3},{2,4},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9}} ;
    std::vector<int> neighbor[N];
    int bfs[N],dfs[N];

    construct(edge, neighbor);
    Breadth_first_search(neighbor, bfs, 0);
    Depth_first_search(neighbor, dfs, 0);

    for (int i = 0; i < N;i++)
        std::cout << bfs[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < N;i++)
        std::cout << dfs[i] << " ";
}