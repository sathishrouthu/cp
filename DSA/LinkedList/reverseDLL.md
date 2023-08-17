### Iterative Method

```
    public static Node reverseDLL(Node head)
    {
        // Write your code here.
        if(head==null || head.next==null) return head;
        Node prev = null;
        Node curr = head;
        Node nex = null;
        while(curr!=null){
            nex = curr.next;
            curr.next = prev;
            curr.prev = nex;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

```

### Recursive Method

```
    public static Node reverseDLL(Node head)
    {
        // Write your code here.
        if(head==null || head.next==null) return head;
        Node rest = reverseDLL(head.next);
        head.next.next = head;
        head.prev = head.next;
        head.next = null;
        return rest;
    }

```
