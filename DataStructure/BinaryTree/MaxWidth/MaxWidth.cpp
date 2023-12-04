#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

typedef struct _NODE_
{
    int value;
    _NODE_ *leftChild;
    _NODE_ *rightChild;
} NODE, *PNODE;

int getMaxWidth(NODE* head){
    if(head==nullptr){
        return 0;
    }
    queue<NODE *> *Q = new queue<NODE *>;
    Q->push(head);
    unordered_map<NODE *, int> *levelMap = new unordered_map<NODE *, int>;
    levelMap->emplace(head, 1);
    int curLevel = 1;
    int curLevelNodes = 0;
    int max = 0;
    while(!Q->empty()){
        head = Q->front();
        Q->pop();
        int curNodeLevel = levelMap->at(head);
        if(curNodeLevel==curLevel){
            curLevelNodes++;
        }else{
            max = curLevelNodes > max ? curLevelNodes : max;
            curLevel++;
            curLevelNodes = 1;
        }

        if(head->leftChild!=nullptr){
            Q->push(head->leftChild);
            levelMap->emplace(head->leftChild, curNodeLevel + 1);
        }
        if(head->rightChild!=nullptr){
            Q->push(head->rightChild);
            levelMap->emplace(head->rightChild, curNodeLevel + 1);
        }
    }
}
int main(){
    system("pause");
}