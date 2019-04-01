/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    struct ListNode* p_A = l1;
    struct ListNode* p_B = l2;
    struct ListNode* p_head = NULL;
    struct ListNode* p_T = NULL;
    
    if(p_A->val < p_B->val){
        p_head = p_A;
        p_T = p_A;
        p_A = p_A -> next;
    }else{
        p_head = p_B;
        p_T = p_B;
        p_B = p_B -> next;
    }
    
    while(p_A && p_B){
        if(p_A->val < p_B->val){
            p_T -> next = p_A;
            p_T = p_T -> next;
            p_A = p_A -> next;
        }else{
            p_T -> next = p_B;
            p_T = p_T -> next;
            p_B = p_B -> next;
        }
    }
    if(p_A != NULL){
        p_T -> next = p_A;
    }
    if(p_B != NULL){
        p_T -> next = p_B;
    }
    return p_head;
}
