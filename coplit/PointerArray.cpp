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
	//��δ�����������������в��������������ͬ�Ľڵ㣬�õ���������ͬ�ڵ�ĸ������Ӷ�֪��Ҫ������������Ĺ�ģ
	while (cur != NULL)
	{

		if (memcmp(cur->Data.v1, Data->v1, 20 * sizeof(TCHAR)) == 0)
		{
			i++;
		}

		cur = cur->Flink;
	}
	//ָ������v5��ÿ��Ԫ�ش洢��һ��һάָ��PNODE
	PNODE* v5 = new PNODE[i];


	int v7 = 0;	//count ����Ԫ�صĸ���
	i = 0;
	cur = List->Head;

	//�������������ͬ�Ľڵ��ַ���δ���ָ��������
	while (cur != NULL)
	{

		if (memcmp(cur->Data.v1, Data->v1, 20 * sizeof(TCHAR)) == 0)
		{
			v5[i] = cur; //ָ������
			i++;
			v7++;
		}

		cur = cur->Flink;
	}

	
	for (i=0;i<v7;i++)
	{
		_tprintf(_T("%s\r\n"), v5[i]->Data.v1);
	}
	
	//����Ҫɾ���ڼ���Ԫ��
	int Position = 0;
	_tscanf(_T("%d"), &Position);  //0 1 2     1  2  3
	//ͷ�ڵ�ʱ
	if (v5[Position-1] == List->Head)
	{
		List->Head = List->Head->Flink;
		List->Head->Blink = NULL;
	}
	//β�ڵ�ʱ
	else if (v5[Position - 1] == List->Tail)
	{
		List->Tail = List->Tail->Blink;
		List->Tail->Flink = NULL;
	}
	//�м�ڵ�ʱ
	else
	{
		v5[Position - 1]->Blink->Flink = v5[Position - 1]->Flink;
		v5[Position - 1]->Flink->Blink = v5[Position - 1]->Blink;
	}
	//�ͷŵ�ɾ��Ԫ�صĿռ�
	delete v5[Position - 1];
	//�ͷ���ʱ����v5
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



		//ǰ��
	}
}

//���ɾ���������Ԫ��
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