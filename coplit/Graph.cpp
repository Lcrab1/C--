#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

#define max 20
typedef struct EdgeNode //边表结点
{
    int adjvex;            //存储顶点对应的下标   存储的是一个位置，而非具体元素，为了以后改变数据方便操作
    struct EdgeNode *next; //链域指向下一个邻接点
    int weight;            //权值（问题中有权值再用）
} EdgeNode;
typedef struct VertexNode //顶点表结点
{
    string data;           //存放顶点信息
    EdgeNode *firstedge; //指向边表中第一个结点
} VertexNode;
typedef struct
{
    VertexNode adjlist[20];
    int n, e;
} GraphAdjlist;  //声明图的邻接表类型


int main() // A B C D E
{
    GraphAdjlist G;
    create1(&G);



    system("pause");
    return 0;
}
void create1(GraphAdjlist *G)
{
    EdgeNode *e;
    G->n = 6;  //顶点数
    G->e = 15; //边数

    G->adjlist[0].data = "Pe";
    G->adjlist[1].data = "N";
    G->adjlist[2].data = "Pa";
    G->adjlist[3].data = "L";
    G->adjlist[4].data = "T";
    G->adjlist[5].data = "Pe";
    for (int i = 0; i < G->n; i++)
    {
        G->adjlist[i].firstedge = NULL; //将边表置空
    }
    // Pe N 0 1 109
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 0;
    e->weight = 109;
    e->next = G->adjlist[1].firstedge;
    G->adjlist[1].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 1;
    e->weight = 109;
    e->next = G->adjlist[0].firstedge;
    G->adjlist[0].firstedge = e;
    //Pe Pa 0 2 82
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 0;
    e->weight = 82;
    e->next = G->adjlist[2].firstedge;
    G->adjlist[2].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 2;
    e->weight = 82;
    e->next = G->adjlist[0].firstedge;
    G->adjlist[0].firstedge = e;
    //Pe L 0 3 81
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 0;
    e->weight = 81;
    e->next = G->adjlist[3].firstedge;
    G->adjlist[3].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 3;
    e->weight = 81;
    e->next = G->adjlist[0].firstedge;
    G->adjlist[0].firstedge = e;

    //Pe T 0 4 21
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 0;
    e->weight = 21;
    e->next = G->adjlist[4].firstedge;
    G->adjlist[4].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 4;
    e->weight = 21;
    e->next = G->adjlist[0].firstedge;
    G->adjlist[0].firstedge = e;

    // Pe M 0 5 124
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 0;
    e->weight = 124;
    e->next = G->adjlist[5].firstedge;
    G->adjlist[5].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 5;
    e->weight = 124;
    e->next = G->adjlist[0].firstedge;
    G->adjlist[0].firstedge = e;

    // N Pa 1 2 58
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 1;
    e->weight = 58;
    e->next = G->adjlist[2].firstedge;
    G->adjlist[2].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 2;
    e->weight = 58;
    e->next = G->adjlist[1].firstedge;
    G->adjlist[1].firstedge = e;

    // N L 1 3 55
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 1;
    e->weight = 55;
    e->next = G->adjlist[3].firstedge;
    G->adjlist[3].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 3;
    e->weight = 55;
    e->next = G->adjlist[1].firstedge;
    G->adjlist[1].firstedge = e;

    //N T 1 4 108
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 1;
    e->weight = 108;
    e->next = G->adjlist[4].firstedge;
    G->adjlist[4].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 4;
    e->weight = 108;
    e->next = G->adjlist[1].firstedge;
    G->adjlist[1].firstedge = e;

    // N M 1 5 32
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 1;
    e->weight = 32;
    e->next = G->adjlist[5].firstedge;
    G->adjlist[5].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 5;
    e->weight = 32;
    e->next = G->adjlist[1].firstedge;
    G->adjlist[1].firstedge = e;

    // Pa L 2 3 3
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 2;
    e->weight = 3;
    e->next = G->adjlist[3].firstedge;
    G->adjlist[3].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 3;
    e->weight = 3;
    e->next = G->adjlist[2].firstedge;
    G->adjlist[2].firstedge = e;

    // Pa T 2 4 97
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 2;
    e->weight = 97;
    e->next = G->adjlist[4].firstedge;
    G->adjlist[4].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 4;
    e->weight = 97;
    e->next = G->adjlist[2].firstedge;
    G->adjlist[2].firstedge = e;

    // Pa T 2 5 92
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 2;
    e->weight = 92;
    e->next = G->adjlist[5].firstedge;
    G->adjlist[5].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 5;
    e->weight = 92;
    e->next = G->adjlist[2].firstedge;
    G->adjlist[2].firstedge = e;

    //L T 3 4 95
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 3;
    e->weight = 95;
    e->next = G->adjlist[4].firstedge;
    G->adjlist[4].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 4;
    e->weight = 95;
    e->next = G->adjlist[3].firstedge;
    G->adjlist[3].firstedge = e;

    // L M 3 5 89
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 3;
    e->weight = 89;
    e->next = G->adjlist[5].firstedge;
    G->adjlist[5].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 5;
    e->weight = 89;
    e->next = G->adjlist[3].firstedge;
    G->adjlist[3].firstedge = e;

    // T M 4 5 113
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = 4;
    e->weight = 113;
    e->next = G->adjlist[5].firstedge;
    G->adjlist[5].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应两个顶点
    e->adjvex = 5;
    e->weight = 113;
    e->next = G->adjlist[4].firstedge;
    G->adjlist[4].firstedge = e;

// Dijkstra算法求以 G->adjlist[0]为原点的最短路径
void Dijkstra(GraphAdjlist G, int start)
{
    int dist[20];
    int path[20];
    int i, j, k, min;
    for (i = 0; i < G.n; i++)
    {
        dist[i] = 99999;
        path[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    for (i = 1; i < G.n; i++)
    {
        min = 99999;
        for (j = 0; j < G.n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        visited[k] = 1;
        for (EdgeNode *e = G.adjlist[k].firstedge; e != NULL; e = e->next)
        {
            if (visited[e->adjvex] == 0 && dist[k] + e->weight < dist[e->adjvex])
            {
                dist[e->adjvex] = dist[k] + e->weight;
                path[e->adjvex] = k;
            }
        }
    }
    printf("Dijkstra算法生成的最短路径为：\n");
    for (i = 0; i < G.n; i++)
    {
        if (i != start)
        {
            printf("%s -> %s : %d\n", G.adjlist[start].data.c_str(), G.adjlist[i].data.c_str(), dist[i]);
        }
    }
}

int main() // A B C D E
{
    GraphAdjlist G;
    create1(&G);

    Prim(G, 0);
    Kruskal(G);
    Dijkstra(G, 0);
    Dijkstra(G, G.adjlist[0].firstedge->adjvex); //调用Dijkstra算法求以 G->adjlist[0]为原点的最短路径

    system("pause");
    return 0;
}
}