#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#define N 7
#define ROOT -1
#define STRANGER -1
#define NONE -2
class EDGE  {
    public:
        int a, b, weight;
};

bool cmp(EDGE a,EDGE b)    {
    return a.weight < b.weight;
}

int find_root (const int (&table)[N],int now) {
    if (table[now] != now)
        return find_root(table,table[now]);
    else
        return now;
}

void kruskal (const std::vector<EDGE> &tr,std::vector<EDGE> &min_span_edge) {
    std::vector<EDGE> edge = tr;
    int table[N];
    
    std::sort(edge.begin(), edge.end(),cmp);
    for (int i = 0;i<N;i++)
        table[i] = i;

    for (int i = 0, n = N - 1; n > 0 && i < edge.size();i++)    {
        if (find_root(table, edge[i].a) != find_root(table, edge[i].b)){
                table[edge[i].b] = edge[i].a;
                n--;
                min_span_edge.push_back(edge[i]);
        }
    }
}

void construct (const std::vector<EDGE> &edge,std::vector<std::pair<int,int> > (&graph)[N])  {
    for (int i = 0; i < edge.size();i++)    {
        std::pair <int,int> tr;
        tr.first = edge[i].weight;
        tr.second = edge[i].b;
        graph[edge[i].a].push_back(tr);
        tr.second = edge[i].a;
        graph[edge[i].b].push_back(tr);
    }
}

void prim (const std::vector<EDGE> &tr,std::vector<int> &min_span_edge) {
    std::vector<std::pair <int,int> > graph[N];
    construct(tr, graph);

    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int> >,std::greater<std::pair<int, int> > > heap;
    int table[N];
    
    for (int i = 0;i<N;i++)
        table[i] = STRANGER;
    table[0] = NONE;
    
    for (int i = 0; i < graph[0].size();i++)
        heap.push(graph[0][i]);

    int n = 0;
    while (n < N-2 || heap.size())   {
        std::pair<int, int> tmp = heap.top();
        heap.pop();
        int now = tmp.second;
        if (table[now] == STRANGER) {
            table[now] = NONE;
            for (int i = 0; i < graph[now].size();i++)
                heap.push(graph[now][i]);
            n++;
            min_span_edge.push_back(tmp.first);
        }
    }
}

int main () {
    std::vector<EDGE> edge = {{0,1,2},{0,3,8},{0,4,14},{1,2,19},{1,4,25},{2,4,17},{2,5,5},{2,6,9},{3,4,21},{4,5,13},{5,6,1}};
    std::vector<EDGE> kruskal_min;
    std::vector<int> prim_min;

    kruskal(edge, kruskal_min);
    std::cout << "kruskal:";
    for (int i = 0; i < kruskal_min.size();i++)
        std::cout << kruskal_min[i].weight << " ";

    std::cout << "\nprim:";
    prim(edge, prim_min);
    for (int i = 0; i < prim_min.size();i++)
        std::cout << prim_min[i] << " " ;

        return 0;
}