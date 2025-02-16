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
