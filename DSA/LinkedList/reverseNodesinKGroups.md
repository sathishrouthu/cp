### Reverse Nodes in K Groups

```
we will maintain two pointers known as start and end denoting the starting and ending element of a group of size K.

but we also maintain two more pointers known as beforeStart and afterEnd denoting the element just before start pointer, element just after the end pointer.

example :
we have a list : 1-->2-->3-->4-->5-->6-->7-->8;

when we want to reverse each group of size K we maintain two pointers to reverse the elements in such a way that

        1-->2-->3-->4-->5-->6-->7-->8;
        s       e

now we will reverse the above list group from s,e ==> reverseList(s,e);
but above list need to be linked to remaining list after reversing.
to do this we need two pointers known as beforeStart and afterEnd
so before start will be at the just before start pointer and afterEnd will be just after the end pointer

X 1-->2-->3-->4-->5-->6-->7-->8;
bs s e ae

after reversing
3-->2-->1 4-->5-->6-->7-->8;
bs e s ae

now

bs.next = e;
s.next = ae;
e = ae;
bs = s;

look into the code and take a notes and practice for more understanding

```

```

class Solution {
    public void reverseList(ListNode s,ListNode e){
        ListNode pre = null,curr=s,nex = null;
        while(curr!=e){
            nex = curr.next;
            curr.next = pre;
            pre = curr;
            curr = nex;
        }
        curr.next = pre;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        // if(head==null || head.next==null || k==1) return head;
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode beforeStart = dummyHead;
        int i=0;
        ListNode end = head;
        while(end!=null){
            i++;
            if(i%k==0){
                ListNode start    = beforeStart.next;
                ListNode afterEnd = end.next;
                reverseList(start,end);
                beforeStart.next = end;
                start.next = afterEnd;
                beforeStart = start;
                end = afterEnd;
            }
            else{
                end=end.next;
            }
        }
        return dummyHead.next;
    }
}

```
