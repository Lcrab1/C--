#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *deleteDuplicates(ListNode *head)
{
    unordered_map<ListNode *, int> map;
    ListNode dummy(0, head);
    ListNode *cur = head;
    ListNode *prev = &dummy;
    while (cur->next != nullptr)
    {
        if (cur->val == cur->next->val)
        {
            map[prev]++;
        }
        else
        {
            prev = cur;
        }

        cur = cur->next;
    }
    for (auto pair : map)
    {
        prev = pair.first;
        while (pair.second >= 0)
        {
            cur = prev->next;
            prev->next = cur->next;
            cur = prev->next;
            pair.second--;
        }
    }
    return dummy.next;
}

int main()
{
    ListNode n1(3);
    ListNode n2(2, &n1);
    ListNode n3(1, &n2);
    ListNode n4(1, &n3);
    ListNode head(1, &n4);

    ListNode *res = deleteDuplicates(&head);
    system("pause");
}