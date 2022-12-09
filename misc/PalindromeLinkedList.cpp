#include "stdio.h"
  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return false;
        ListNode* prevCurr = nullptr, *head1 = nullptr;
        ListNode * current1 = nullptr;
        for(ListNode * current = head; current; current = current->next)
        {
            current1 = new ListNode(current->val);
            if(prevCurr)
                current1->next = prevCurr;
            prevCurr = current1;
        }
        head1 = current1;
        ListNode * iter = head1;
        for(ListNode * current = head; current; current = current->next)
        {
            if(current && !iter)
                return false;
            if(iter->val != current->val)
                return false;
        }
        ListNode * next = nullptr;
        for(ListNode * iter = head1; iter; iter = next)
            {
                next = iter->next;
			    delete iter;
            }
        return true;
    }
};

int main(int argc, char** argv)
{
    ListNode * head = new ListNode(1);
    ListNode * one = new ListNode(2);
    ListNode * two = new ListNode(2);
    ListNode * three = new ListNode(1);
    head->next = one;
    one->next = two;
    two->next = three;
    Solution Sol;
    bool ret = Sol.isPalindrome(head);
    printf("%d\n",static_cast<int>(ret) );
    return static_cast<int>(ret);
}