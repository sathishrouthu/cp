'''

Topological sorting for Directed Acyclic Graph (DAG) is a linear
ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering.
Topological Sorting for a graph is not possible if the graph is not a DAG.

Algo :

--> Calculate indegree of all vertices.
--> initialize visited count=0
-->Where to start ? Vertices with indegree 0.
-->add all vertices with indegree 0 to Que
-->Deque a vertex and:
        -->Decrement it's adjacent vertices indegree by 1
        -->if indegree of any vertex became 0 then add it to Que
        -->increment visited++
--> Stop when Que is empty..

Psuedo Code:

indegree[]={0}*V
for each vertex v in graph G:
    for each adj vertex av of v
          indegree[av]++
visited=0
que=[]
topo=[]
for each vertex v in G
    if indegree[v]==0:
        add v to Que
while( Que not empty)
    v<--Deque
    add v to topo
    for each adj vertex av of v
          indegree[av]--
          if indegree[av]==0
                add av to Que
    visted++

if visited != V
    error msg - Cycle found!!
  

'''

V=int(input("Enter total No. of vertices in the graph : "))
E=int(input("Enter total No. of Edges in the graph : "))
print("Enter edges :")
indegree=[0]*V
adj_list={}
while(E):
    a,b=map(int,input().split())
    if a in adj_list:
        adj_list[a].append(b)
    else:
        adj_list[a]=[b]
    indegree[b]+=1
    E-=1
visited=0
Q=[]
topo=[]
print(adj_list)

for v in range(V):
    if indegree[v]==0:
        Q.append(v)
while(len(Q)!=0):
    v=Q.pop(0)
    topo.append(v)
    if v in adj_list:
        for av in adj_list[v]:
            indegree[av]-=1
            if indegree[av]==0:
                Q.append(av)
    visited+=1
if visited!=V:
    print("Cycle found in graph..!!")
print("Topo order : ")
print(*topo)



'''
Complexity Analysis: 

--> Time Complexity: O(V+E). 
The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.
  O(V+E)
--> Auxiliary space: 
  O(V). 
The extra space is needed for the stack.



'''
