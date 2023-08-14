### Merge Two Sorted Lists

Naive : 
create a new list by Using merge sort method.
```
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode *temp = ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }    
            temp = temp->next;
        }
        while(l1!=NULL){
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2!=NULL){
            temp->next = new ListNode(l2->val);
            l2 = l2->next;
            temp = temp->next;
        }
        return ans->next;
    }

```

Optimal : 
```
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val) swap(l1,l2);
        ListNode* res = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp = NULL;
            while( l1!=NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return res;
    }
```
