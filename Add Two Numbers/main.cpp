#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int xremainder = 0;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(l1 && l2)
        {
            xremainder = (l1->val + l2->val + carry) % 10;

            ListNode *node = new ListNode(xremainder);

            carry = (l1->val + l2->val + carry) / 10;

            if(head == NULL)
                head = node;

            if(tail == NULL)
            {
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            xremainder = (l1->val + carry) % 10;

            ListNode *node = new ListNode(xremainder);

            carry = (l1->val + carry) / 10;

            tail->next = node;
            tail = node;

            l1 = l1->next;
        }

        while(l2)
        {
            xremainder = (l2->val + carry) % 10;

            ListNode *node = new ListNode(xremainder);

            carry = (l2->val + carry) / 10;

            tail->next = node;
            tail = node;

            l2 = l2->next;
        }

        if(carry)
        {
            ListNode *node = new ListNode(carry);
            tail->next = node;
        }

        return head;
    }
};


int main()
{
    Solution slu;
    ListNode *l1 = NULL, *l2 = NULL, *p = NULL, *rst;

    srand((unsigned)time(0));
    int limit1 = rand() % 10;
    int limit2 = rand() % 10;

    for(int i=0; i < limit1; i++)
    {
        ListNode *node = new ListNode(rand() % 10);
        if(l1 == NULL)
            l1 = node;

        if(p == NULL)
        {
            p = node;
        }
        else
        {
            p->next = node;
            p = node;
        }
    }

    p = NULL;

    for(int i=0; i < limit2; i++)
    {
        ListNode *node = new ListNode(rand() % 10);
        if(l2 == NULL)
            l2 = node;

        if(p == NULL)
        {
            p = node;
        }
        else
        {
            p->next = node;
            p = node;
        }
    }

    rst = slu.addTwoNumbers(l1, l2);

    cout<< "l1:"<< endl;
    while(l1)
    {
        cout << l1->val<< "\t";
        l1 = l1->next;
    }

    cout<< endl<< "l2:"<< endl;
    while(l2)
    {
        cout << l2->val<< "\t";
        l2 = l2->next;
    }

    cout<< endl<< "result:"<< endl;
    while(rst)
    {
        cout << rst->val<< "\t";
        rst = rst->next;
    }

    return 0;
}
