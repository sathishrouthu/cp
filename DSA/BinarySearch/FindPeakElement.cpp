/*
Given an Array , find the peak element.
if arr[i] is peak element then arr[i-1]<arr[i] and arr[i+1]<arr[i]
 conside arr[-1] and arr[n] as a negative infinity;

at a given index i, we check if it is peak element ? arr[i-1]>arr[i] and arr[i]>arr[i+1];
if given element is greater than the prev element (Ascending) then there must exist a peak element in the right half and we can eliminate the left half;
else (Descending) then there must exist a peak element before current element and we can eliminate right half;
this is because we have negative infinity at the both ends of the array
if we are ascending then there is peak in right;
if we are descending then there is a peak in the left;
*/
int findPeakElement(vector<int> &arr) {
        // Write your code here
        int n=arr.size();
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
    
        int l=1;
        int h=n-2;
    
        while(l<=h){
            int mid = (l+h)>>1;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;  // mid is peak
            if(arr[mid]>arr[mid-1]) l=mid+1;                            // ascending
            else h=mid-1;                                               //descending
        }
        return 0;
}