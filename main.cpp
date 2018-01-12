//
//  main.cpp
//  LeetCode147_InsertionSortList
//
//  Created by Rui on 1/11/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1); //create a new listnode to store the sorted nodes
        ListNode *cur = dummy;
        
        while(head)//go through the head
        {
            ListNode *next = head->next;
            cur = dummy;
            while(cur->next && cur->next->val <= head->val) //compare the current node with the last node put into the dummy
                cur = cur->next;
            
            head->next = cur->next; //replace the node
            cur->next = head;
            head = next;
        }
        
        return dummy->next;
    }
};

