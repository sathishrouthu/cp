//   1.Binary Search    
  
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if (nums[mid]==target)
                return mid;
            else if (nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }



// TWO-POINTER technique 

Ex: Two Sum problem.:
for Example if we want to find a pair of elements in a given array those sums upto specific value
Ex: [4,1,3,2,5,1,7] ,  value= 10

  ans : 3,7
    
this problem take O(n^2) in a bruteforce approach.
this can be solved in efficient way as O(n) by using a hashmap.

    there is also another approach called twopointer technique.
    [4,1,3,2,5,1,7]
    before traversing our array we need to sort our array.
    
    [1,1,2,3,4,5,7]
    
    we use two pointer to traverse the array.
    i=0 , j=n-1
    
    we traverse one element in the array from front by using i and back by using j
   
    when i==j array is exceeded.
    when arr[i]+arr[j] == value
      we return True
    if arr[i]+arr[j] > value: we need to decrease the sum so we decrement j (j traversing bigger elements)
    else  we need to increase sum by incrementing i
    
    
    
   1. Sort the array 
   2.i=0 ,  j=n-1
   3. while(i<j)
    {
      if (arr[i]+arr[j]== val)
        return True;
      else if(arr[i]+arr[j]>val)
        j--;
      else
        i++;
    }
  4. return False;



/*

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node. 

Example 1:
          __
1--->2--->3--->4--->5

Input: head = [1,2,3,4,5]
Output: [3,4,5]

Explanation: The middle node of the list is node 3.

Example 2:
              ___
1--->2--->3--->4--->5--->--->6
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*//*
This problem can be done in 2 ways :
1.
Put every node into an array A in order. Then the middle node is just A[A.length // 2], since we can retrieve each node by index.
We can initialize the array to be of length 100, as we're told in the problem description that the input contains between 1 and 100 nodes.

  */
   
    ListNode* middleNode(ListNode* head) {
        ListNode *temp= head;
        vector<ListNode*> arr={head};
        while(arr.back()->next!=NULL)
            arr.push_back(arr.back()->next);               
        return arr[arr.size()/2];
    }

/*
2.
slow and fast pointer :
When traversing the list with a pointer slow, make another pointer fast that traverses twice as fast.
When fast reaches the end of the list, slow must be in the middle.
*/
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
