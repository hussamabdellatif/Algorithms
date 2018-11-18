// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

#include<cstdio>

class MinStack {
public:
    /** initialize your data structure here. */
    struct ListNode {
      int size;
      int val;
      ListNode *next;
      ListNode *before;
      int min;
      ListNode *end;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode() : size(0),min(0),val(0),before(NULL),end(NULL), next(NULL) {}
    };

    ListNode* head = new ListNode();
    int size =0;
    MinStack() {

    }

    void push(int x) {
        if(!size){
            if(!head) head = new ListNode();
            size++;
            head->val = x;
            head->min = x;
            return;
        }
        if(head && size == 1){
            size++;
            ListNode* post_head = new ListNode();
            post_head->val = x;
            post_head->min = (x<head->min) ? x:head->min;
            post_head->before = head;
            head->end = post_head;
            head->next = post_head;
            return;
        }
        size++;
        ListNode* inter = new ListNode();
        inter->val = x;
        inter->before = head->end;
        inter->min = (x < inter->before->min) ? x:inter->before->min;
        head->end->next = inter;
        head->end = inter;
        return;
    }

    void pop() {
        if(!size) return;
        if(size == 1){
            head = NULL;
            size--;
            return;
        }

        ListNode* temp = head->end->before;
        temp->next = NULL;
        head->end = temp;
        size--;
        return;
    }

    int top() {
        if(!size) return 0;
        if(size ==1)return head->val;
        return head->end->val;
    }

    int getMin() {
        if(!size) return 0;
        if(size == 1) return head->val;
        return head->end->min;
    }
};
