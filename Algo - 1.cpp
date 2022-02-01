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
    
    
    
    
