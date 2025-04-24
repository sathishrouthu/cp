## Tree Traversal 

##### Pre-order
```
root-left-right
```
##### In-order
```
left-root-right
```
##### Post-order
```
left-right-root
```

##### Level Order
```
use a Queue
```

##### Pre, Post, Inorder in one traversal
use a Stack<TreeNode,Integer> : 
if num == 1 : 
  add to pre-order
  num++, push the same node
  node has a left ? push left node with num=1
if num == 2 : goes to inorder
  add to in-order
  num++, push the same node
  node has a right ? push right node with num=1
if num == 3 : goes to postorder
  add to post-order










