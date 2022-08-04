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
