#include<iostream>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right || head == nullptr)
    {
        return head;
    }
    ListNode *cur = head;
    ListNode *pre = nullptr;
    ListNode *nxt = head->next;
    ListNode *first = nullptr; //寄存1
    int count = 1;             // left-1 first寄存cur right:last寄存cur->next
    bool flag = false;
    while (!flag && cur != nullptr && count < left)
    {
        if (count == left - 1)
        {
            first=cur;
            flag=true;
        }
            cur=cur->next;
            count++;
    }
        ListNode dummy(0);
        dummy.next=cur;
        nxt=cur->next;
        while(count<=right){
            cur->next=pre;
            pre=cur;
            cur=nxt;
            if(nxt!=nullptr){
            nxt=nxt->next;
            }

            count++;
        }
        first->next=pre;    
        dummy.next->next=cur;
        if(left!=1)
            return head;
        return pre;
    }

int main(){
    ListNode node1(3);
    ListNode node2(5);
    // ListNode node3(3);
    // ListNode node4(4);
    // ListNode node5(5);
    node1.next = &node2;
    // node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node5;
    // node5.next = nullptr;
    ListNode*res=reverseBetween(&node1, 1, 2);
    system("pause");
}