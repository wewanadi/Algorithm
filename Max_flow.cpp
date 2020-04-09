#include <iostream>
#include <vector>
#include <stack>
#define STRANGER -2
#define START -1
#define comefrom first
#define flux second
#define N 6
class EDGE {
    public:
    int from, to, weight;
};
class GRAPH {
    public:
        int to, weight, back_mark;
};

void construct (std::vector<EDGE> &edge,std::vector<GRAPH> (&graph)[N]) {
    for (int i = 0; i < edge.size();i++)    {
        graph[edge[i].from].push_back({edge[i].to,edge[i].weight,(int)graph[edge[i].to].size()});
        graph[edge[i].to].push_back({edge[i].from,0,(int)graph[edge[i].from].size()-1});
    }
}

int max_flow(std::vector<EDGE> &edge,int sourse,int sink)  {
    std::vector<GRAPH> graph[N];
    construct(edge,graph);
    for (int i = 0; i < N;i++) 
        for (int j = 0; j < graph[i].size();j++)
            printf("[%d][%d] %d %d %d\n",i,j, graph[i][j].to, graph[i][j].weight, graph[i][j].back_mark);

    std::stack<int> flow;
    
    std::pair <int,int> union_find[N];
    for (int i = 0; i < N;i++) {
        union_find[i].comefrom = STRANGER;
        union_find[i].flux = __INT_MAX__;
    }
    union_find[sourse].comefrom = START;
    flow.push(sourse);

    while (flow.size() && union_find[sink].comefrom==STRANGER )  {
        int now = flow.top();
        flow.pop();
        for (int i = graph[now].size()-1; i >= 0;i--)
            if (union_find[graph[now][i].to].comefrom==STRANGER) {
                union_find[graph[now][i].to].comefrom = now;
                union_find[graph[now][i].to].flux = std::min(union_find[now].flux, graph[now][i].weight);
                flow.push(graph[now][i].to);
            }
    }

    int now = sink;
    while (now!=START) {
        now = union_find[now].comefrom;
        graph[now][]
    }
}

int main () {
    std::vector<EDGE> edge = {{0,1,10},{0,3,10},{1,2,8},{1,3,2},{1,4,4},{2,4,6},{2,5,10},{3,2,9},{4,5,10}};
    max_flow(edge,0,5);

    return 0;
}