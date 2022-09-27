

Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.
```
Example 1: 

Input: arr=[1,3,4,2,2]

Output: 2

Explanation: Since 2 is the duplicate number the answer will be 2.

```

Approach-1 :

Sort the array. After that, if there is any duplicate number they will be adjacent.

So we simply have to check if arr[i]==arr[i+1] and if it is true,arr[i] is the duplicate number.

Time Complexity: O(Nlogn + N)


Approach-2 : 

```
Take a frequency array of size N+1 and initialize it to 0.
Now traverse through the array and 
if the frequency of the element is 0 increase it by 1, 
else if the frequency is not 0 then that element is the required answer.

Time Complexity: O(N)
Space Complexity: O(N)
```

Approach-3 : 

similar to linked list cycle method : 
let us take two pointers alow and fast.
slow moves one step at a time and fast moves two steps at a time.

let us take an array :   [ 2, 5, 9, 6, 9, 3, 8, 9, 7, 1 ]

initially we have slow and fast at 0th index.

![image](https://user-images.githubusercontent.com/93826731/192653841-8e0b8b2c-22b3-4cef-966c-975b4352d1b6.png)

after they meet at a point we start a pointer start of the array and moves start and slow one by one : 
where these start and slow meets that is the duplicate.

```
int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

```


*/
