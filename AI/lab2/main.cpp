#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#define size 3
using namespace std;
//�����ά�������洢���ݱ�ʾĳһ���ض�״̬
typedef int status[size][size];
struct SpringLink;

//����״̬ͼ�еĽ�����ݽṹ
typedef struct Node
{
    status data;              //������洢��״̬ ��һ��3*3����
    struct Node *parent;      //ָ����ĸ��׽��
    struct SpringLink *child; //ָ����ĺ�̽��
    struct Node *next;        //ָ��open����closed���еĺ�һ�����
    int fvalue;               //�����ܵ�·��
    int gvalue;               //����ʵ��·��
    int hvalue;               //���ĵ���Ŀ������ѳ̶�
} NNode, *PNode;

//����洢ָ�����̽���ָ��ĵ�ַ
typedef struct SpringLink
{
    struct Node *pointData;  //ָ�����ָ��
    struct SpringLink *next; //ָ���ֵڽ��
} SPLink, *PSPLink;

PNode open;
PNode closed;
// OPEN�������������ɶ�δ����Ľڵ㣬CLOSED���м�¼�ѷ��ʹ��Ľڵ�

//��ʼ״̬��Ŀ��״̬
/*
status startt = {1,3,0,8,2,4,7,6,5};���·��Ϊ2
status startt = {1,3,0,2,8,4,7,6,5};��������20000�Σ��ֶ�ֹͣ
status startt = {2,8,3,1,6,4,7,0,5};
status startt = {2,8,3,6,0,4,1,7,5}; //ʵ�鱨��
*/
int t = 0;                                   //��������,�൱������ʱ��
int count_extendnode = 0;                    //��չ���
int count_sumnode = 0;                       //���ɽڵ�
status startt = {2, 8, 3, 6, 0, 4, 1, 7, 5}; //ʵ�鱨��
status target = {1, 2, 3, 8, 0, 4, 7, 6, 5};
//��ʼ��һ��������
void initLink(PNode &Head)
{
    Head = (PNode)malloc(sizeof(NNode));
    Head->next = NULL;
}

//�ж������Ƿ�Ϊ��
bool isEmpty(PNode Head)
{
    if (Head->next == NULL)
        return true;
    else
        return false;
}

//���������ó�һ������
void popNode(PNode &Head, PNode &FNode)
{
    if (isEmpty(Head))
    {
        FNode = NULL;
        return;
    }
    FNode = Head->next;
    Head->next = Head->next->next;
    FNode->next = NULL;
}

//��������պ�̽������������µ��ӽ��
void addSpringNode(PNode &Head, PNode newData)
{
    PSPLink newNode = (PSPLink)malloc(sizeof(SPLink));
    newNode->pointData = newData;

    newNode->next = Head->child;
    Head->child = newNode;
}

//�ͷ�״̬ͼ�д�Ž���̽���ַ�Ŀռ�
void freeSpringLink(PSPLink &Head)
{
    PSPLink tmm;

    while (Head != NULL)
    {
        tmm = Head;
        Head = Head->next;
        free(tmm);
    }
}

//�ͷ�open����closed���е���Դ
void freeLink(PNode &Head)
{
    PNode tmn;

    tmn = Head;
    Head = Head->next;
    free(tmn);

    while (Head != NULL)
    {
        //�����ͷŴ�Ž���̽���ַ�Ŀռ�
        freeSpringLink(Head->child);
        tmn = Head;
        Head = Head->next;
        free(tmn);
    }
}

//����ͨ���������һ�����
void addNode(PNode &Head, PNode &newNode)
{
    newNode->next = Head->next;
    Head->next = newNode;
}

//��ǵݼ����е����������һ����㣨�Ѿ�����Ȩֵ��������
void addAscNode(PNode &Head, PNode &newNode)
{

    PNode P;
    PNode Q;

    P = Head->next;
    Q = Head;
    while (P != NULL && P->fvalue < newNode->fvalue)
    {
        Q = P;
        P = P->next;
    }
    //�����жϺ�λ��֮��������Ǽ򵥵Ĳ�����
    newNode->next = Q->next;
    Q->next = newNode;
}

/*
//������� h ֵ  f=g+h. ���ղ���λ�ĸ������м���
int computeHValue(PNode theNode)
{
    int num = 0;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(theNode->data[i][j] != target[i][j])
                num++;
        }
    }
    return num;
}
//������� h ֵ  f=g+h. ���ս��Ʋ���λ�ľ���ͽ��м���
int computeHValue(PNode theNode)
{
    int num = 0;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(theNode->data[i][j] != target[i][j]&&theNode->data[i][j] !=0){
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        if(theNode->data[i][j] == target[ii][jj]){
                            num+=abs(ii-i)+abs(jj-j);
                            break;
                        }
                    }
                }
            }

        }
    }
    return num;
}  */

//�������f��g��hֵ
void computeAllValue(PNode &theNode, PNode parentNode)
{
    if (parentNode == NULL)
        theNode->gvalue = 0;
    else
        theNode->gvalue = parentNode->gvalue + 1;

    //    theNode->hvalue = computeHValue(theNode);
    theNode->hvalue = 0;
    theNode->fvalue = theNode->gvalue + theNode->hvalue;
}

//��ʼ�������������㷨��ʼ����������
void initial()
{
    //��ʼ��open�Լ�closed��
    initLink(open);
    initLink(closed);

    //��ʼ����ʼ��㣬���ʼ���ĸ��ڵ�Ϊ�ս��
    PNode NULLNode = NULL;
    PNode Start = (PNode)malloc(sizeof(NNode));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Start->data[i][j] = startt[i][j];
        }
    }
    Start->parent = NULL;
    Start->child = NULL;
    Start->next = NULL;
    computeAllValue(Start, NULLNode);

    //��ʼ������open��
    addAscNode(open, Start);
}

//��B�ڵ��״̬��ֵ��A���
void statusAEB(PNode &ANode, PNode BNode)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ANode->data[i][j] = BNode->data[i][j];
        }
    }
}

//��������Ƿ�����ͬ��״̬
bool hasSameStatus(PNode ANode, PNode BNode)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ANode->data[i][j] != BNode->data[i][j])
                return false;
        }
    }
    return true;
}

//����������Ƚ���Ƿ�����ͬ��״̬
bool hasAnceSameStatus(PNode OrigiNode, PNode AnceNode)
{
    while (AnceNode != NULL)
    {
        if (hasSameStatus(OrigiNode, AnceNode))
            return true;
        AnceNode = AnceNode->parent;
    }
    return false;
}

//ȡ�÷����пյĸ��ӵ�λ��
void getPosition(PNode theNode, int &row, int &col)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (theNode->data[i][j] == 0)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

//�����������ֵ�ֵ
void changeAB(int &A, int &B)
{
    int C;
    C = B;
    B = A;
    A = C;
}

//�����Ӧ��״̬�Ƿ���ĳһ��������
bool inLink(PNode spciNode, PNode theLink, PNode &theNodeLink, PNode &preNode)
{
    preNode = theLink;
    theLink = theLink->next;

    while (theLink != NULL)
    {
        if (hasSameStatus(spciNode, theLink))
        {
            theNodeLink = theLink;
            return true;
        }
        preNode = theLink;
        theLink = theLink->next;
    }
    return false;
}

//�������ĺ�̽��(������״̬��ͬ)����
void SpringLink(PNode theNode, PNode &spring)
{
    int row;
    int col;

    getPosition(theNode, row, col);

    //�յĸ����ұߵĸ��������ƶ�
    if (col != 2)
    {
        PNode rlNewNode = (PNode)malloc(sizeof(NNode));
        statusAEB(rlNewNode, theNode);
        changeAB(rlNewNode->data[row][col], rlNewNode->data[row][col + 1]);
        if (hasAnceSameStatus(rlNewNode, theNode->parent))
        {
            free(rlNewNode); //�븸����ͬ�����������
        }
        else
        {
            rlNewNode->parent = theNode;
            rlNewNode->child = NULL;
            rlNewNode->next = NULL;
            computeAllValue(rlNewNode, theNode);
            //�����������̽������
            addNode(spring, rlNewNode);
        }
    }
    //�յĸ�����ߵĸ��������ƶ�
    if (col != 0)
    {
        PNode lrNewNode = (PNode)malloc(sizeof(NNode));
        statusAEB(lrNewNode, theNode);
        changeAB(lrNewNode->data[row][col], lrNewNode->data[row][col - 1]);
        if (hasAnceSameStatus(lrNewNode, theNode->parent))
        {
            free(lrNewNode); //�븸����ͬ�����������
        }
        else
        {
            lrNewNode->parent = theNode;
            lrNewNode->child = NULL;
            lrNewNode->next = NULL;
            computeAllValue(lrNewNode, theNode);
            //�����������̽������
            addNode(spring, lrNewNode);
        }
    }
    //�յĸ����ϱߵĸ��������ƶ�
    if (row != 0)
    {
        PNode udNewNode = (PNode)malloc(sizeof(NNode));
        statusAEB(udNewNode, theNode);
        changeAB(udNewNode->data[row][col], udNewNode->data[row - 1][col]);
        if (hasAnceSameStatus(udNewNode, theNode->parent))
        {
            free(udNewNode); //�븸����ͬ�����������
        }
        else
        {
            udNewNode->parent = theNode;
            udNewNode->child = NULL;
            udNewNode->next = NULL;
            computeAllValue(udNewNode, theNode);
            //�����������̽������
            addNode(spring, udNewNode);
        }
    }
    //�յĸ����±ߵĸ��������ƶ�
    if (row != 2)
    {
        PNode duNewNode = (PNode)malloc(sizeof(NNode));
        statusAEB(duNewNode, theNode);
        changeAB(duNewNode->data[row][col], duNewNode->data[row + 1][col]);
        if (hasAnceSameStatus(duNewNode, theNode->parent))
        {
            free(duNewNode); //�븸����ͬ�����������
        }
        else
        {
            duNewNode->parent = theNode;
            duNewNode->child = NULL;
            duNewNode->next = NULL;
            computeAllValue(duNewNode, theNode);
            //�����������̽������
            addNode(spring, duNewNode);
        }
    }
}

//�����������״̬
void outputStatus(PNode stat)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << stat->data[i][j] << " ";
        }
        cout << endl;
    }
}

//�����ѵ�·��
void outputBestRoad(PNode goal)
{
    int deepnum = goal->gvalue;

    if (goal->parent != NULL)
    {
        outputBestRoad(goal->parent);
    }
    cout << "��" << deepnum-- << "���״̬��" << endl;
    outputStatus(goal);
}

void AStar()
{

    PNode tmpNode;  //ָ���open�����ó����ŵ�closed���еĽ���ָ��
    PNode spring;   // tmpNode�ĺ�̽����
    PNode tmpLNode; // tmpNode��ĳһ����̽��
    PNode tmpChartNode;

    PNode thePreNode;     //ָ��Ҫ��closed�����Ƶ�open���еĽ���ǰһ������ָ��
    bool getGoal = false; //��ʶ�Ƿ�ﵽĿ��״̬
    long numcount = 1;    //��¼��open�����ó��������

    initial();        //�Ժ������г�ʼ��
    initLink(spring); //�Ժ������ĳ�ʼ��
    tmpChartNode = NULL;
    // Target.data=target;
    cout << "1" << endl;
    PNode Target = (PNode)malloc(sizeof(NNode));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Target->data[i][j] = target[i][j];
        }
    }
    cout << "1" << endl;
    cout << "��open�����ó��Ľ���״̬����Ӧ��ֵ" << endl;

    while (!isEmpty(open))
    {
        t++;
        //��open�����ó�fֵ��С��Ԫ��,�����ó���Ԫ�ط���closed����
        popNode(open, tmpNode);
        addNode(closed, tmpNode);
        count_extendnode = count_extendnode + 1;

        cout << "��" << numcount++ << "��״̬�ǣ�" << endl;
        outputStatus(tmpNode);
        cout << "��fֵΪ��" << tmpNode->fvalue << endl;
        cout << "��gֵΪ��" << tmpNode->gvalue << endl;
        cout << "��hֵΪ��" << tmpNode->hvalue << endl;

        /* //����ó���Ԫ����Ŀ��״̬������ѭ��
         if(computeHValue(tmpNode) == 0)
         {  count_extendnode=count_extendnode-1;
             getGoal = true;
             break;
         }*/
        //����ó���Ԫ����Ŀ��״̬������ѭ��
        if (hasSameStatus(tmpNode, Target) == true)
        {
            count_extendnode = count_extendnode - 1;
            getGoal = true;
            break;
        }

        //������ǰ�����ĺ��(�����Ȳ�ͬ)����б������ĺ�̽���parent����ָ��ǰ���Ľ��
        SpringLink(tmpNode, spring);

        //���������ĺ�̽������
        while (!isEmpty(spring))
        {
            popNode(spring, tmpLNode);
            //״̬��open�����Ѿ����ڣ�thePreNode���������ﲢ��������
            if (inLink(tmpLNode, open, tmpChartNode, thePreNode))
            {
                addSpringNode(tmpNode, tmpChartNode);
                if (tmpLNode->gvalue < tmpChartNode->gvalue)
                {
                    tmpChartNode->parent = tmpLNode->parent;
                    tmpChartNode->gvalue = tmpLNode->gvalue;
                    tmpChartNode->fvalue = tmpLNode->fvalue;
                }
                free(tmpLNode);
            }
            //״̬��closed�����Ѿ�����
            else if (inLink(tmpLNode, closed, tmpChartNode, thePreNode))
            {
                addSpringNode(tmpNode, tmpChartNode);
                if (tmpLNode->gvalue < tmpChartNode->gvalue)
                {
                    PNode commu;
                    tmpChartNode->parent = tmpLNode->parent;
                    tmpChartNode->gvalue = tmpLNode->gvalue;
                    tmpChartNode->fvalue = tmpLNode->fvalue;
                    freeSpringLink(tmpChartNode->child);
                    tmpChartNode->child = NULL;
                    popNode(thePreNode, commu);
                    addAscNode(open, commu);
                }
                free(tmpLNode);
            }
            //�µ�״̬����״̬�Ȳ���open����Ҳ����closed����
            else
            {
                addSpringNode(tmpNode, tmpLNode);
                addAscNode(open, tmpLNode);
                count_sumnode += 1; //���ɽڵ�
            }
        }
    }

    //Ŀ��ɴ�Ļ��������ѵ�·��
    if (getGoal)
    {
        cout << endl;
        cout << "���·������Ϊ��" << tmpNode->gvalue << endl;
        cout << "���·��Ϊ��" << endl;
        outputBestRoad(tmpNode);
    }

    //�ͷŽ����ռ���ڴ�
    freeLink(open);
    freeLink(closed);
    //    getch();
}

int main()
{
    double start = GetTickCount();
    AStar();
    printf("���ɽڵ���Ŀ��%d\n", count_sumnode);
    printf("��չ�ڵ���Ŀ��%d\n", count_extendnode);
    printf("����ʱ�䣺%f\n", GetTickCount() - start);
    system("pause");
}
