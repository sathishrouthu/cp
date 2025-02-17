
We maintain a doubly linked list to maintain cache elements and an Hash Map to maintain cache keys.
1. DLL will consists of nodes where each node will have : key, value, next, prev;
2. HashMap stores the key and it's corresponding node.

Inititally DLL will have two pointers Head and Tail
```
Head <--> [3,15] <--> [4,10] <--> Tail
dummy      MRU         LRU        Dummy
```
- Nodes closer to head are most recently used nodes.
- Nodes closer to tail are least recently used nodes.
```
For a put operation:
    Check if key already exists in hashmap:
        if exists:
            remove the node from dll
            update it's value and insert the node at front.
        else:
            check if capacity is full
            If full:
                remove the last node in the DLL and remove that key from hashmap.
                add new node to the DLL at the front and add the key in hashmap.
            else:
                add the new node at the front and add the key in hashmap.
```
```
For a get operation:
    check if key exists in hash map:
    if exists:
        get the node
        remove from dll
        add the node at front.
        return node's value.
    else
        return -1; 
```
```
class Node{
    public int key,val;
    public Node next,prev;
    public Node(){
        key=-1;
        val=-1;
    }
    public Node(int key, int val){
        this.key = key;
        this.val = val;
    }
}
class LRUCache {
    public Node head,tail;
    Map<Integer,Node> map;
    int capacity;
    public LRUCache(int capacity) {
        map = new HashMap<>();
        head = new Node();
        tail = new Node();
        head.next=tail;
        tail.prev = head;
        this.capacity = capacity;
    }
    public void deleteNode(Node node){
        Node nextNode = node.next;
        Node prevNode = node.prev;
        nextNode.prev = prevNode;
        prevNode.next = nextNode; 
    }
    public void insertFirst(Node node){
        Node headNext = head.next;
        headNext.prev = node;
        head.next = node;
        node.next = headNext;
        node.prev = head;
    }
    public int get(int key){
        if(map.containsKey(key)){
            Node node = map.get(key);
            deleteNode(node);
            insertFirst(node);
            return node.val;
        }else{
            return -1;
        }
    }

    public void put(int key, int value) {
        if(map.containsKey(key)){
            Node node = map.get(key);
            deleteNode(node);
            node.val = value;
            insertFirst(node);
        }else{
            if(map.size() == capacity){
                Node lruNode = tail.prev;
                deleteNode(lruNode);
                map.remove(lruNode.key);   
            }
            Node newNode = new Node(key,value);
            map.put(key,newNode);
            insertFirst(newNode);
        }
    }
}
```

```

#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        int key;
        int val;
        Node * next;
        Node * prev;
        Node(int _key,int _val){
            key  = _key;
            val  = _val;
        }
    };
    int cap;
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    
    unordered_map<int,Node *> mp;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node * newnode){
        newnode -> prev = head;
        newnode -> next = head -> next;
        head -> next->prev = newnode;
        head -> next = newnode;
    }
    void deletenode(Node * delnode){
        Node * delprev = delnode -> prev;
        Node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    
    int get(int key)
    {
        if(mp.find(key)!=mp.end()){
            Node * res = mp[key];
            int result = res->val;
            mp.erase(key);
            deletenode(res);
            addnode(res);
            mp[key] = head->next;
            return result;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            Node * exist = mp[key];
            mp.erase(key);
            deletenode(exist);
        }
        if(mp.size()==cap){
            Node * temp = tail->prev;
            mp.erase(temp->key);
            deletenode(temp);
            
        }
        addnode(new Node(key,value));
        mp[key] = head->next;
    }
};


```
