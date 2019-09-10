#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

/*
 *ptr = NULL creates a pointer pointing to NULL
 &ptr gives the address of value NULL
 ptr gives 'NULL'0x0
 **current = &ptr creates a pointer pointing to *ptr
 *current gives 'NULL'0x0
 current gives the address of value NULL
*/

class Solution {
public:
	// O(n)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *ptr = NULL;
    	ListNode **current = &ptr;
    	// &((*current)->next) is the address of a new NULL
    	// *current indicates the nodes the pointer pointing towards
    	// current indicates the value stored in the current variable
    	while(l1 != NULL || l2 != NULL) {
            if(l1 == NULL) {
                *current = new ListNode(l2->val);
                l2 = l2->next;
            } else if(l2 == NULL) {
                *current = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                *current = new ListNode(l1->val + l2->val);
                l1 = l1->next;
                l2 = l2->next;
            }
    		current = &((*current)->next);
    	}
    	ListNode **tmp = &ptr;
    	while((*tmp) != NULL) {
    		if((*tmp)->val >= 10) {
        		(*tmp)->val = (*tmp)->val % 10;
                if((*tmp)->next == NULL){
                    (*tmp)->next = new ListNode(0);
                }
                (*tmp)->next->val = (*tmp)->next->val + 1;	
        	}
        	tmp = &((*tmp)->next);
    	}
    	return ptr;

    }

    // O(n)
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode *ptr = NULL;
    	ListNode **current = &ptr;
    	int sum = 0;

    	while(l1 != NULL || l2 != NULL || sum > 0) {
            if(l1 != NULL) {
            	sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
            	sum += l2->val;
                l2 = l2->next;
            }
            *current = new ListNode(sum % 10);
            sum /= 10;
    		current = &((*current)->next);
    	}
    	return ptr;
    }

    ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
    	ListNode *ptr = nullptr;
    	ListNode *current = nullptr;
        int sum = 0;

        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        while (l1 or l2 or sum) {
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(current) {
                current->next = new ListNode(sum % 10);
                current = current->next;
            }
            else {
                current = ptr = new ListNode(sum % 10);
            }
            sum /= 10;
        }
        return ptr;
    }
};

int main() {
	ListNode *sum;
	ListNode *sum2;
	ListNode *sum3;

	std::cout << "-----Case 1-----" << '\n';
	ListNode *a,*b,*c;
	a = new ListNode(2);
	b = new ListNode(4);
	c = new ListNode(3);
	a->next = b;
	b->next = c;

	ListNode *d,*e,*f;
	d = new ListNode(5);
	e = new ListNode(6);
	f = new ListNode(4);
	d->next = e;
	e->next = f;
	
	sum = Solution().addTwoNumbers(a, d);
	sum2 = Solution().addTwoNumbers2(a, d);
	sum3 = Solution().addTwoNumbers3(a, d);
	std::cout << "add 1: ";
	while(sum != NULL){
		std::cout << sum->val << ' ';
		sum = sum->next;
	}
	std::cout << "\nadd 2: ";
	while(sum2 != NULL){
		std::cout << sum2->val << ' ';
		sum2 = sum2->next;
	}
	std::cout << "\nadd 3: ";
	while(sum3 != NULL){
		std::cout << sum3->val << ' ';
		sum3 = sum3->next;
	}
	std::cout <<  '\n' << "-----Case 2-----" << '\n';
	ListNode *g, *h;
	g = new ListNode(9);
	h = new ListNode(9);

	sum = Solution().addTwoNumbers(g, h);
	sum2 = Solution().addTwoNumbers2(g, h);
	sum3 = Solution().addTwoNumbers3(g, h);
	std::cout << "add 1: ";
	while(sum != NULL){
		std::cout << sum->val << ' ';
		sum = sum->next;
	}
	std::cout << "\nadd 2: ";
	while(sum2 != NULL){
		std::cout << sum2->val << ' ';
		sum2 = sum2->next;
	}
	std::cout << "\nadd 3: ";
	while(sum3 != NULL){
		std::cout << sum3->val << ' ';
		sum3 = sum3->next;
	}

	std::cout << '\n' << "-----Case 3-----" << '\n';
	ListNode *i, *j, *k;
	i = new ListNode(1);
	j = new ListNode(9);
	i->next= j;
	k = new ListNode(9);

	sum = Solution().addTwoNumbers(i, k);
	sum2 = Solution().addTwoNumbers2(i, k);
	sum3 = Solution().addTwoNumbers3(i, k);
	std::cout << "add 1: ";
	while(sum != NULL){
		std::cout << sum->val << ' ';
		sum = sum->next;
	}
	std::cout << "\nadd 2: ";
	while(sum2 != NULL){
		std::cout << sum2->val << ' ';
		sum2 = sum2->next;
	}
	std::cout << "\nadd 3: ";
	while(sum3 != NULL){
		std::cout << sum3->val << ' ';
		sum3 = sum3->next;
	}
}