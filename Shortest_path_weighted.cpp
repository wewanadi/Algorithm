#include <iostream>
#include <vector>
#include <queue>
#define N 6
#define cost first
#define come second
#define goto second
#define STRANGER -2
#define START -1
class EDGE {
    public:
    int from, to, weight;
};

void construct (const std::vector<EDGE> &edge,std::vector<std::pair<int,int> > (&graph)[N])  {
    for (int i = 0; i < edge.size();i++)    {
        std::pair <int,int> tr;
        tr.cost = edge[i].weight;
        tr.goto = edge[i].to;
        graph[edge[i].from].push_back(tr);
    }
}

void dijkstra (std::vector<EDGE> &edge,int outset,std::vector<int> &dijkstra_path)    {
    std::pair<int,int> table[N];
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int> >,std::greater<std::pair<int, int> > >  min_heap;
    std::vector<std::pair <int,int> > graph[N];
    construct(edge, graph);

    for (int i = 0; i < N;i++) {
        table[i].cost = __INT_MAX__;
        table[i].come = STRANGER;
    }
    table[outset].cost = 0;
    table[outset].come = START;
    int cover_num = 0;

    min_heap.push({0,outset});
    while  (min_heap.size())  {
        std::pair<int,int> now = min_heap.top();
        min_heap.pop();
        for (int i = 0; i < graph[now.goto].size();i++)  {
            std::pair<int,int> to = graph[now.goto][i];
            if (table[to.goto].come == STRANGER)    cover_num++;
            if (table[to.goto].cost > table[now.goto].cost + to.cost)  {
                table[to.goto].cost = table[now.goto].cost + to.cost;
                table[to.goto].come = now.goto;
                min_heap.push({table[to.goto].cost,to.goto});
            }
        }
        if (cover_num==N)   break;
    }

    for (int i = 0; i < N;i++)
        dijkstra_path.push_back(table[i].cost);
}

void bellman_ford (std::vector<EDGE> &edge,int outset,std::vector<int> &table)    {
    for (int i = 0; i < N;i++)
        table.push_back(__INT_MAX__);

    table[outset] = 0;
    for (int i = 0; i < N - 1;i++)  {
        for (int j = 0; j < edge.size();j++)    {
            if (table[edge[j].from] != __INT_MAX__ && table[edge[j].to] > table[edge[j].from] + edge[j].weight )
                table[edge[j].to] = table[edge[j].from] + edge[j].weight;
        }
    }
}

void floyd_warshall (std::vector<EDGE> &edge,int table[N][N])   {
    for (int i = 0; i < N;i++)
        for (int j = 0; j < N;j++)
            table[i][j] = __INT16_MAX__;
    for (int i = 0; i < N;i++)
        table[i][i] = 0;

    for (int i = 0; i < edge.size(); i++)
        table[edge[i].from][edge[i].to] = edge[i].weight;

    for (int k = 0; k < N;k++)
        for (int i = 0; i < N;i++)
            for (int j = 0; j < N;j++)
                if (table[i][j] > table[i][k] + table[k][j])            //已知所有相鄰為 K步 的點的最佳解 -> 推所有相鄰為 K步 的點中的最佳解 
                    table[i][j] = table[i][k] + table[k][j];
}
    

int main () {
    std::vector<EDGE> edge = {{0,1,8},{0,5,1},{2,0,5},{2,3,2},{2,4,2},{1,0,3},{1,2,1},{3,2,6},{3,5,3},{3,1,4},{3,4,7},{5,3,2},{5,4,8}};
    std::vector<int> dijkstra_path, ballman_ford_path;
    int floyd_warshall_path[N][N];

    dijkstra(edge, 0, dijkstra_path);
    std::cout << "[dijkstra] start at 0 : ";
    for (int i = 0;i<N;i++)
        std::cout << dijkstra_path[i] << " ";
    std::cout << std::endl;

    bellman_ford(edge, 0, ballman_ford_path);
    std::cout << "[ballman_ford] start at 0 : ";
    for (int i = 0;i<N;i++)
        std::cout << ballman_ford_path[i] << " ";
    std::cout << std::endl;

    floyd_warshall(edge, floyd_warshall_path);
    std::cout << "[floyd_warshall] start at";
    for (int i = 0; i < N;i++) {
        std::cout << "\n " << i <<":";
        for (int j = 0; j < N ;j++)
            if (floyd_warshall_path[i][j] == __INT16_MAX__)
                std::cout << " X";
            else
                std::cout << " " << floyd_warshall_path[i][j];
    }

    return 0;
}