#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXSIZE 100 //最大顶点数

typedef struct ArcNode
{               //边节点信息
    int adjvex; //该边所指向的头结点（顶点）的位置（数组下标）
    ArcNode *nextarc;
} ArcNode;

typedef struct
{ //头结点信息
    int data;
    ArcNode *firstarc; //指向第一条依附于该顶点的边节点的指针
} VNode, AdjList[MAXSIZE];

typedef struct
{                       //邻接表
    AdjList vertices;   //存放头结点表的数组
    int vexnum, arcnum; //头结点数（顶点数）    边（弧）数
} ALGraph;

int LocateVex(ALGraph G, int v1)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v1)
            return i;
    }
    return 0;
}
// 邻接表法创建无向图
void CreatUDG(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum; //输入图的顶点数和边数

    for (int i = 0; i < G.vexnum; i++)
    { //输入各点。构造头结点表
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL; //初始化头结点的指针域为空
    }
    cout << 'l' << endl;
    for (int k = 0; k < G.arcnum; k++)
    { //输入各边。构造边表
        int v1, v2;
        cin >> v1 >> v2; //输入某条边所连接的两个顶点v1,v2

        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2); //查询顶点v1,v2在G的 保存头结点表 的那个数组vertices中的位置（下标）

        ArcNode *p = new ArcNode; //创建一个边节点 （此处为何用指针变量呢？？因为头结点信息那个结构体的firstarc就是指针类型变量）
        p->adjvex = j;            //该边节点 指向的 头结点 在数组vertices中的下标为 j
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p; //将边节点 p 挂在对于 头结点 上（单链表的：头插法）

        //如果是有向图：下面的可以省略
        ArcNode *q = new ArcNode;
        q->adjvex = i;
        q->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = q;
    }
    cout << 'k' << endl;
}
int main()
{
    ALGraph G;
    CreatUDG(G);
    cout << 'l';
}
