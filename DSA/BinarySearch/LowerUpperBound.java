public class LowerUpperBound {
    public static int lowerBound(int []arr, int n, int x) {
        // Write your code here
        int l=0;
        int h = n-1;
        while(l<=h){
            int mid = (h+l)/2;
            if(arr[mid]<x)
                l = mid+1;
            else 
                h=mid-1;
        }
        return l;
    }
    public static int upperBound(int []arr, int x, int n){
        // Write your code here.
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(arr[mid]<=x) l = mid+1;
            else h=mid-1;
        }
        return l;
    }

    // this is similar to upper bound but if element exists in the array you need yo return it's position else upper bound
    public static int searchInsertPosition(int [] arr, int m){
        int l=0;
        int h=arr.length-1;
        if(arr.length==0) return 0;
        while(l<=h){
            int mid=(l+h)>>1;
            if(arr[mid]==m) return mid;
            if(arr[mid]<m) 
                l = mid+1;
            else 
                h=mid-1;
        }
        return l;
    }
}
