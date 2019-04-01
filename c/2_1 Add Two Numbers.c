/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /* test case all pasted, Runtime: 16 ms*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = l1; // new list used the l1.
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    
    int val; 
    while(p1 && p2)
    {
        /* add value form p1 and p2 */
        val = p1->val + p2->val;
        /* some issus */
        // p1 and p2 all in the end and add more than 9
        if((p1->next == NULL) && (p2->next == NULL) && (val > 9))
        {
            p1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p1->next->next = NULL;
            p1->next->val = 0;
        }
        // just p1 in the end but not p2
        else if((p1->next == NULL) && (p2->next != NULL))
        {
            //printf("case 2\n");
            p1->next = p2->next;
            p2->next = NULL;
        }
        // just p2 in the end, do nothing.
                
        p1->val = val;
        
        p1 = p1->next;        
        p2 = p2->next;
        
    }
    // if have some nodes value more than 10, fix it.
    p1 = head;
    while(p1)
    {
        if(p1->val > 9)
        {
            if(NULL == p1->next)
            {
                p1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                p1->next->next = NULL;
                p1->next->val = 0;
            }
            p1->next->val = p1->next->val + (p1->val / 10);
            p1->val = (p1->val % 10);
        }
        p1 = p1->next;
    }
    
    return head;
}
