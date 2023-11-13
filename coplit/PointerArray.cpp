#include <iostream>
#include <tchar.h>
using namespace std;

//
//[] [] [] [] [] [] [] [] 
//
typedef struct _DATA_
{
	TCHAR v1[20];
	int   v2;
}DATA,*PDATA;

typedef struct _NODE_
{

	DATA  Data;
	_NODE_* Flink;
	_NODE_* Blink;
}NODE, * PNODE;

typedef struct _LIST_
{
	PNODE Head;
	PNODE Tail;
}LIST,*PLIST;

void CreateLinkList(PLIST List, const DATA* Data);
void FindData(const PLIST List, const PDATA Data);
void TravelLinkList(const PLIST List);
int _tmain()
{
	LIST List = { 0 };   //
	DATA Data[] = { {_T("123"),1},{_T("123"),2},{_T("133"),3},{_T("113"),4},{_T("123"),5} };
	int i = 0;
	for (i=0;i<sizeof(Data)/sizeof(Data[0]);i++)
	{
		CreateLinkList(&List, &Data[i]);
	}

	//
	//reverse 
	FindData(&List, &Data[0]);

	TravelLinkList(&List);
	system("pause");
}
void FindData(const PLIST List,const PDATA Data)
{

	PNODE cur = List->Head;
	int i = 0;
	// MaxLenght
	//  Length
	// pNode** [][][][]
	//这段代码的作用是在链表中查找与给定数据相同的节点，得到与数据相同节点的个数，从而知道要创建的新数组的规模
	while (cur != NULL)
	{

		if (memcmp(cur->Data.v1, Data->v1, 20 * sizeof(TCHAR)) == 0)
		{
			i++;
		}

		cur = cur->Flink;
	}
	//指针数组v5，每个元素存储了一个一维指针PNODE
	PNODE* v5 = new PNODE[i];


	int v7 = 0;	//count 存入元素的个数
	i = 0;
	cur = List->Head;

	//将与给定数据相同的节点地址依次存入指针数组中
	while (cur != NULL)
	{

		if (memcmp(cur->Data.v1, Data->v1, 20 * sizeof(TCHAR)) == 0)
		{
			v5[i] = cur; //指针数组
			i++;
			v7++;
		}

		cur = cur->Flink;
	}

	
	for (i=0;i<v7;i++)
	{
		_tprintf(_T("%s\r\n"), v5[i]->Data.v1);
	}
	
	//输入要删除第几个元素
	int Position = 0;
	_tscanf(_T("%d"), &Position);  //0 1 2     1  2  3
	//头节点时
	if (v5[Position-1] == List->Head)
	{
		List->Head = List->Head->Flink;
		List->Head->Blink = NULL;
	}
	//尾节点时
	else if (v5[Position - 1] == List->Tail)
	{
		List->Tail = List->Tail->Blink;
		List->Tail->Flink = NULL;
	}
	//中间节点时
	else
	{
		v5[Position - 1]->Blink->Flink = v5[Position - 1]->Flink;
		v5[Position - 1]->Flink->Blink = v5[Position - 1]->Blink;
	}
	//释放掉删除元素的空间
	delete v5[Position - 1];
	//释放临时变量v5
	delete v5;

}
void CreateLinkList(PLIST List,const DATA* Data)
{
	PNODE Node = new NODE;
	memset(Node, 0, sizeof(NODE));
	Node->Data = *Data;

	if (List->Head==NULL)
	{
		List->Head = Node;
		List->Tail = Node;
	}
	else
	{
		List->Tail->Flink = Node;
		Node->Blink = List->Tail;
		List->Tail = Node;



		//前驱
	}
}

//输出删除变量后的元素
void TravelLinkList(const PLIST List)
{
	PNODE v1 = List->Head;
	
	while (v1 != NULL)
	{

		_tprintf(_T("%s "), v1->Data.v1);
		_tprintf(_T("%d\r\n"), v1->Data.v2);
		v1 = v1->Flink;
	}
}