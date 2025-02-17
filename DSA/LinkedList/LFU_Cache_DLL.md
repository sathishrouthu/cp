# Least Frequently Used Cache

Pre-requisite: **LRU Cache**

We maintain a DLL for each frequency of usage.
1. DLL will contain nodes which will have : key, value, frequency, next and prev.
2. An HashMap to save the key and Node (keyNodeMap)
3. An HashMap to save the DLLs for each frequency of usage. (freqListMap)
4. A variable to know the leastFrequency in cache. (leastFrequency)

Our cache will look like below:
```
Node[key,value,Frequency]

leastFrequency = 1

Freq List Map:
Freq :    LRU Cache
1    :    Head <--> [11,21,1] <--> [14,10,1] <--> Tail
2    :    Head <--> [13,19,2] <--> Tail
3    :    Head <--> [12,20,3] <--> [15,13,3] <--> [10,25,3] <--> Tail

keyNodeMap:
key    :     Node [key, val, frequency]
10     :    [10,25,3]
11     :    [11,21,1]
12     :    [12,20,3]
13     :    [13,19,2]
14     :    [14,10,1]
15     :    [15,13,3]
```
##### For a put operation:
```
Check if key already exists in keyNodeMap:
IF exists:
    get the node from the keyNode map
    update the node's value.
    update the node's frequency in cache.
Else:
    check cache size and maxCapacity
    If cache FULL:
            leastFreqList = Get the list from freqListMap which have the key leastFrequency.
            lastNodekey = leastFreqList's last Node key
            remove the lastNodeKey from keyNodeMap
            remove the last Node from leastFreqList
            decrement the currentSize of cache.
    // since this is a new node, It's initial frquency would be 1.
    set leastFrequency = 1;
    create newNode (key,val,1)
    check if frequency 1 already exists in freqListMap
    If exists:
        get the leastFrequentList = list of frequency 1 in freqListMap.
        add the newNode at the front of leastFrequenctList ( since newNode will be most recent one).
    Else:
        newList = create a new DLL
        add newNode to newList
        add [ 1 : newList ] to freqListMap
```

##### For a get operation:
```
check if key exists in keyNodeMap:
if exists:
    get the Node from keyNodeMap
    update the node's frequency in cache.
    return node's value;
else:
    return -1;
```

##### Updating frequency of a node in cache
This operation increments the given node's frequency by 1 and update it to the corresponding List.
```
giveNode : node

currentFrequency = node.frequency
containingList = get the list which has the currentFrequency
remove the node from the containingList;
IF leastFrequency in cache is currentFrequency and containingList has no more nodes:
    increment the leastFrequency by 1.
newFrequency = currentFrequency+1 (increment the node's frequency by 1)
check if a list already exists with newFrequency.
IF Exists:
    add the node at the front of the exisiting list
Else:
    create a new List and add the node to the list.
    add the new List in freqlistMap.

```

```
class Node{
    int key;
    int val;
    int frequency;
    Node prev;
    Node next;
    public Node(int key, int val){
        this.key = key;
        this.val = val;
        this.frequency = 1;
    }
}

class DLL{
    Node head;
    Node tail;
    int size;
    public DLL(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head.next = tail;
        tail.prev = head;
        size = 0;
    }

    public void addFront(Node node){
        Node headNext = head.next;
        head.next = node;
        node.next = headNext;
        node.prev = head;
        headNext.prev = node;
        size++;
    }
    public void removeNode(Node node){
        Node nextNode = node.next;
        Node prevNode = node.prev;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
        size--;
    }
    public void removeLast(){
        Node lastNode = tail.prev;
        lastNode.prev.next = tail;
        tail.prev = lastNode.prev;
        size--;
    }
}

class LFUCache {
    Map<Integer,DLL> freqListMap;
    Map<Integer,Node> keyNodeMap;
    int maxCapacity;
    int currSize;
    int leastFrequency;
    public LFUCache(int capacity) {
        freqListMap = new HashMap<>();
        keyNodeMap = new HashMap<>();
        this.maxCapacity = capacity;
        this.leastFrequency = 0;
        this.currSize = 0;
    }
    
    public int get(int key) {
        if(keyNodeMap.containsKey(key)){
            Node node = keyNodeMap.get(key);
            int value = node.val;
            updateFrequency(node);
            return value;
        }
        return -1;
    }
    
    public void put(int key, int value) {

        if(maxCapacity == 0) return;

        if(keyNodeMap.containsKey(key)){
            Node existing = keyNodeMap.get(key);
            existing.val = value;
            updateFrequency(existing);
        }else{
            if(currSize == maxCapacity){
                DLL leastFrequencyList = freqListMap.get(leastFrequency);
                keyNodeMap.remove(leastFrequencyList.tail.prev.key);
                leastFrequencyList.removeLast();
                currSize--;
            }
            leastFrequency = 1;
            DLL leastFrequencyList = new DLL();
            if(freqListMap.containsKey(leastFrequency)){
                leastFrequencyList = freqListMap.get(leastFrequency);
            }
            Node newNode = new Node(key,value);
            leastFrequencyList.addFront(newNode);
            keyNodeMap.put(key,newNode);
            freqListMap.put(leastFrequency,leastFrequencyList);
            currSize++;
        }
    }

    public void updateFrequency(Node node){
        DLL containingList = freqListMap.get(node.frequency);
        containingList.removeNode(node);
        if(node.frequency == leastFrequency && containingList.size == 0){
            leastFrequency++;
        }
        node.frequency += 1;
        DLL freqList = new DLL();
        if(freqListMap.containsKey(node.frequency)){
            freqList = freqListMap.get(node.frequency);
        }
        freqList.addFront(node);
        freqListMap.put(node.frequency,freqList);
    }
}


```
