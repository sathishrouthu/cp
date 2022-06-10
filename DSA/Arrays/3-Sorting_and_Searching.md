### Search in a rotated Sorted array
<a href="https://www.linkedin.com/posts/mayank-singh-1004981a4_search-in-rotated-sorted-array-ii-activity-6914044080352018432-fhId?utm_source=linkedin_share&utm_medium=member_desktop_web
"> Refer this post for explanation!!</a>

 ```
int search(int* arr, int n, int key) {
    int l=0,h=n-1;
    int mid;
    while(l<=h){
        mid=l+(h-l)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[mid]==arr[h]&&arr[mid]==arr[l]){
            l++;
            h--;
        }
        else if(arr[mid]<=arr[h])
            if(arr[mid]<key && key<=arr[h])
                l=mid+1;
            else
                h=mid-1;
        else if(arr[mid]>=arr[l])
            if(arr[mid]>key && arr[l]<=key)
                h=mid-1;
            else
                l=mid+1;
    }
    return -1;
}

```


### Form a Triangle
You are given an integer of array/list 'ARR' of length ‘N. You are supposed to return true
if it is possible to construct at least one non-degenerate triangle using values of array/list 
as sides of the triangle, otherwise, return false.

Ex:

ip : 4 2 1 3 2

op : YES

if we choose the sides as { 2,3,4} or {2,2,1} or {2,2,3} then it is possible to form a non-degenerate triangle.

ip : 12 3 7 4 28

op : NO

In the first test case, there is no possible way to choose three elements such that they will form the sides of a triangle.

```
bool possibleToMakeTriangle(vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++){
        if(arr[i]+arr[i+1]>arr[i+2])
            return true;
    }
    return false;
}

```
