#include<iostream>

using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   int overflow = 0;
        ListNode* res = nullptr;
        ListNode* lastNode = nullptr;
        while(l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + overflow;
            overflow = sum/10;
            int remainder = sum%10;

            ListNode* node = new ListNode(remainder);
            if(res == nullptr) {
                res = node;
                lastNode = node;
            } else {
                lastNode->next = node;
                lastNode = lastNode->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 != nullptr) {
            while(l1 != nullptr) {
                int sum = l1->val+overflow;
                overflow = sum/10;
                int remainder = sum%10;
                ListNode* nn = new ListNode(remainder);
                lastNode->next = nn;
                lastNode = lastNode->next;
                l1 = l1->next;
            }

            if(overflow > 0) {
                ListNode* nn = new ListNode(overflow);
                lastNode->next = nn;
            }
        }   
    
        if(l2 != nullptr) {
            while(l2 != nullptr) {
                int sum = l2->val+overflow;
                overflow = sum/10;
                int remainder = sum%10;
                ListNode* nn = new ListNode(remainder);
                lastNode->next = nn;
                lastNode = lastNode->next;
                l2 = l2->next;
            }

            if(overflow > 0) {
                ListNode* nn = new ListNode(overflow);
                lastNode->next = nn;
            }

        }
        return res;
}

ListNode* addTwoNumbersOPT(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* back = res;
    int overflow = 0;

    while(l1 || nullptr && l2 || nullptr || overflow !=0) {
        int val1 = l1 == nullptr ? 0 : l1->val;
        int val2 = l2 == nullptr ? 0 : l2->val;
        int sum = val1+val2+overflow;
        overflow = sum/10;
        int rem = sum%10;

        ListNode* nn = new ListNode(rem);
        back->next = nn;
        back = back->next;
        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
    }
    return res->next;
}

