/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Ex :
  i/p : 1 -> 2 -> 3 -> 4 -> 5
  
  o/p :5 -> 4 -> 3-> 2 -> 1
  */


// We will have 3 pointers (prev, curr, and next)
    //This visualization will explain it (p is previous, c is current, and n is next):
    //     1 -> 2 -> 3 ->
    // p  c,n
    //     1 -> 2 -> 3 ->
    // p   c    n
    //  <- 1    2 -> 3 ->
    // p   c    n
    //  <- 1    2 -> 3 ->
    //     p   c,n
    //  <- 1    2 -> 3 ->
    //     p    c    n
    //  <- 1 <- 2    3 ->
    //     p    c    n
    //  <- 1 <- 2    3 ->
    //     p         c, n
    //  <- 1 <- 2    3 ->
    //          p    c    n
    //  <- 1 <- 2 <- 3 
    //          p    c    n
    //  <- 1 <- 2 <- 3 
    //               p   c, n
    
    // Now prev is the reverse linked list because now its reversed and prev is pointing to the begnning



    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(head->next==nullptr)
            return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=head;
        while(curr)
        {
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
