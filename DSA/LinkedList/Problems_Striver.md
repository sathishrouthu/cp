### 206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.


![image](https://user-images.githubusercontent.com/93826731/181736333-05aff320-9b51-4145-aafe-061359e40bb2.png)

<a href="https://leetcode.com/problems/reverse-linked-list/">problem here</a>

suppose we have a link list :

1--> 2--> 3--> 4--> 5--> null;

what we have to do is just change the direction of pointers at each node.

null--> 5--> 4--> 3--> 2--> 1;

**Iteratively** 

initially 
we take 
dummy pointer :  denotes the prev node.
head pointer  :  denoting current node.
next pointer  :  denoting the next node of head pointer.

with these 3 pointers we just go to each node and reverse the direction link between them.


At each iteration 
break the  existing link and connect it to prev node (dummy);
move dummy to current node by using head node;
move head to next node by using next node;
move next to next node;

example :

we have a list 

1--> 2--> 3--> null;

dummy = null;
head  = 1;
next  = 2;

1. break the link : 
    head.next = dummy;
2. move dummy forward.
    dummy = head;
3. move head forward
    head = next;
4. move next forward
    next = next.next;

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = null;
        ListNode next = head;
        while(head!=null){
            next = head.next;
            head.next = dummy;
            dummy = head;
            head = next;
        }
        return dummy;
    }
}

```
**Recursive:**
```
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        ListNode rest = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return rest;
    }
}
```


### 19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

![image](https://user-images.githubusercontent.com/93826731/181745035-aa7df773-7255-4a1d-a155-ad78e46297c4.png)

Simple solution is to:

find the length of the node by iterating over the list and then we can find Nth node from end as  (length-N) th node from beginning.

Time complexity for above method is O(2n)

**efficient way :**
```
take two pointer :  Slow pointer and fast pointer:
We move fast pointer n times from starting node.
Then we move slow pointer and fast pointer by a difference of 1 step until fast pointer reaches the end;
At this stage the slow pointer n nodes away from end;
Now we can delete the nth node (next of slow pointer).

special case : if the n == length of list
we have to delete head such that we will not move slow pointer any further.
```
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode start = new ListNode();
        start.next = head;
        ListNode slow = start;
        ListNode fast = start;
        for(int i=1;i<=n;i++)
            fast = fast.next;
        while(fast.next!=null){
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return start.next;
    }
}

```
### 876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Simple approach is to find length of list and then go to n/2 th node or (n/2 + 1) node.

but time complexity is O(N) + O(N/2) 

Slow and Fast pointer approach :

slow pointer takes 1 step at a time and fast pointer takes 2 steps at a time .
by the time that the fast pointer reaches end of list or out of bound the slow pointer will be at middle of the list

```
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null ){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
```

### 21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

![image](https://user-images.githubusercontent.com/93826731/181773644-b0ddc468-7464-4424-a08f-15d12fc93169.png)

**Simple Solution:**

Create a new list and add each element from both given lists by comparing them.

But it will take O(N1+N2) space.

So inorder make it without extra space :
**Efficient solution: **

```
let given lists are L1 and L2;
L1 will be the list with lower value at starting node every time.
L2 will be the list with higher value at starting node.


Decide L1 and L2 by comparing their starting nodes.
Now move L1 pointer until L1.val > L2.val  (but before moving L1 forward store the it's address in a temp )
Now connect the L2 to the L1's previous node (stored in temp)
swp L1 and L2 (because L1 should have lower value at starting node)
```

```
Ex:
L1 = 1->3->4->7->null;
L2 = 3->5->9->null;
---------------------------------------------------
move L1 until L1.val > L2.val  (but remember current node in temp before moving to next node)
now L1 will be at 4 ant temp at 3;
L2 will be at 3;

Connect temp->next = L2;
swap L1 and L2
L1 will be at 3
L2 will be at 4
---------------------------------------------------
move L1 
L1 will be at 5 and temp is at 3 (in second list)
L2 will be at 4  (in first list)
connect temp->next = L2;
swap L1 and L2
L1 will be at 4
L2 will be at 5
-----------------------------------------------------
Move L1 
L1 will be at 7 and temp is at 4;
L2 will be at 5;
connect temp->next = L2;
swap L1 and L2
L1 will be at 5
L2 will be at 7
----------------------------------------------------
move L1
L1 at 9 and temp at 5
L2 at 7
connect temp->next = L2;
swap L1 and L2
L1 will be at 7
L2 will be at 9
----------------------------------
move L1 and L1 becomes null;
that means we reachede end and ther is only one element left in L2 add to the result;
```

```
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null)    return l2;
        if(l2==null)    return l1;
        
        //make sure that l1 with lower value
        if(l1.val>l2.val){
            ListNode temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode res = l1;
        
        while(l1!=null && l2!=null){
            ListNode tmp = null;
            while(l1!=null && l1.val<=l2.val){
                tmp = l1;
                l1 = l1.next;
            }
            tmp.next = l2;
            
            // swap
            ListNode t = l1;
            l1 = l2;
            l2 = t;
        }
        return  res;
    }   
}
```




