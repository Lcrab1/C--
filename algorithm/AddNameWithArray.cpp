#include <iostream>
#include <tchar.h>
using namespace std;
#define MAX 4
#pragma pack(4)

//定义节点
typedef struct _NODE_
{
    TCHAR *Name;
    int Length;
    int MaxLength;

    _NODE_()
    {
        memset(this, 0, sizeof(_NODE_));
        MaxLength = MAX;
        Name = new TCHAR[MaxLength];
    }
    ~_NODE_()
    {
        delete Name;
        memset(this, 0, sizeof(_NODE_));
    }

} NODE, *PNODE;

void AddNameWIthArray(PNODE Node)
{
    TCHAR v1;
    v1 = _gettchar();
    while (v1 != 0xA)
    {
        if (Node->Length + 1 == Node->Length) //为\0预留出空间
        {
            TCHAR *v5 = nullptr;
            Node->MaxLength += MAX;
            v5 = new TCHAR[Node->MaxLength];
            memcpy(v5, Node->Name, sizeof(Node->Name));
            delete Node->Name;
            Node->Name = v5;
        }

        Node->Name[Node->Length] = v1;
        Node->Length++;
        v1 = _gettchar();
    }
    Node->Name[Node->Length] = 0x00;
    _tprintf(_T("%s"), Node->Name);
}

int _tmain()
{
    NODE Node;
    AddNameWIthArray(&Node);
}