<a href="https://leetcode.com/problems/palindrome-linked-list/">Problem here</a>

```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null) return true;
        ListNode slow = head;
        ListNode fast = head;
        
        //find middle of list
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        //reverse the right half
        slow.next = reverseList(slow.next);
        
        //move slow to the right half
        slow = slow.next;
        
        //compare left half and right half
        while(slow!=null){
            if(head.val!=slow.val)
                return false;
            head = head.next;
            slow = slow.next;
        }
        return true;
    }
    public ListNode reverseList(ListNode head){
        if(head==null || head.next==null){
            return head;
        }
        ListNode rest = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return rest;
    }
}
```