/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode *temp = head;
    while(head!=NULL && head->val==val)
    head=head->next;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->val==val){
        temp->next=temp->next->next;
    }
    else 
    temp=temp->next;
    }
    return head;
    
}
