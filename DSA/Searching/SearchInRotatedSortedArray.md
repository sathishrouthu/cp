### Search in a rotated sorted Array

given an array which is sorted but rotated at an element. we need to find out the index of the key element.
ex : 
arr = [ 1,2,3,4,5,6,7 ]
after rotated at 5 : 
arr = [ 5,6,7,1,2,3,4 ]

Solution : 

we need to find out the element in the sorted array, but it is rotated at some element;

there are two ways : 

```
find pivot element where the array is rotated and apply binary search on two sorted sub arrays : 
ex : [ 7 8 9 1 2 3 4 5 6 ] the pivot element here is 9 ( all elements before 9 > and all elements after 9 )
we can find pivot by using same binary search but each time we will check 
if arr[mid-1] > arr[mid]  then arr[mid-1] is pivot
or 
if arr[mid] > arr[mid+1] then arr[mid]  is pivot

after finding pivot we apply the binary search on two arrays divided at pivot
```

applying Binary search without finding pivot : 

we can aaply binary search without pivot 

at each time we will check which part of the array is sorted. and move to favourible region :

```
int search(int* arr, int n, int key) {
    int l=0;
    int h = n-1;
    while(l<=h){
        int mid = (l+h)>>1;
        if(arr[mid]==key) return mid;

        // check if left part is sorted
        if(arr[l]<=arr[mid]){
            // check if key lies in left part or not
            if(arr[l]<=key && arr[mid]>=key)
                h = mid-1;
            else
                l = mid+1;
        }
        //right part is sorted
        else{
            // check if key lies in right part or not 
            if(arr[mid]<=key && arr[h]>=key)
                l = mid+1;
            else
                h = mid-1;
        }
    }
    return -1;
}

```
