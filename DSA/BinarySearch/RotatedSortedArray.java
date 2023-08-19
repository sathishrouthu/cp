import java.util.ArrayList;



public class RotatedSortedArray {


/*
 * Given an array which is sorted and rotated at a unknown pivot index.
 * given a target , find the position of target in the array, if it doesnot exist return -1;
 * ex : 
 *  arr = 1 2 3 4 5
 * 
 *  rotatedArr = 4 5 1 2 3
 *  target = 5
 *  output = 1
 * 
 */
    public static int search(ArrayList<Integer> arr, int n, int target) {
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(arr.get(mid)==target) return mid;                //target found
            if(arr.get(l)<=arr.get(mid)){                       // left part is sorted
                if(arr.get(l)<=target && target<=arr.get(mid))  // target lies in the left part
                    h=mid-1;        
                else                                            //target lies in the right part                           
                    l=mid+1;
            }
            else{                                               // right part is sorted
                if(arr.get(mid)<=target && target<=arr.get(h))  // target lies in the right part
                    l = mid+1;                  
                else                                            // target lies in the left part
                    h = mid-1;
            }
        }
        return -1;
    }

/*
 * Search In Rotated Sorte Array II
 * 
 * it is similar to previous problem but, the given array may contains duplicates.
 * 
 * our previous may fail when the arr[mid]==arr[low]==arr[high] as we cannot determine which part is sorted.
 * we simply eliminate arr[low] , arr[high] from array by low--, h--; 
 * here arr[low], arr[high] wont be our target as we are already checking if arr[mid] is target.
 * 
 */
    public static boolean searchInARotatedSortedArrayII(int []A, int key) {
        int n=A.length;
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(A[mid]==key) return true;
            else if(A[mid]==A[l] && A[mid]==A[h]){
                l++;
                h--;
            }
            else if(A[l]<=A[mid]){
                if(A[l]<=key && key<=A[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else{
                if(A[mid]<=key && key<=A[h])
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        return false;
    }

    /*
     * 
     * Find Minimum in Rotated Sorted Array
     * we maintain an answer variable mini;
     * at each time we compare the left most value in the sorted array with the mini and update based on it's value;
     * we will find out the sorted part of the rotated sorted array with same logic in previous problems 
     * 
     * if(arr[mid]>=arr[low])   // left part is sorted
     * if(arr[mid]<=arr[high])  // right part is sorted
     * 
     * Further Optimization:
     *  at some point if(arr[low]<=arr[high]) then it means that the entire array is sorted, 
     *  take the left most value and compare with and exit.
     * 
     */
    public static int findMin(int []arr) {
        int l = 0;
        int h = arr.length-1;
        int ans = arr[0];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[l]<=arr[h]) return Math.min(ans,arr[l]);
            if(arr[l]<=arr[mid]){
                ans = Math.min(ans,arr[l]);
                l=mid+1;
            }
            else{
                ans = Math.min(ans,arr[mid]);
                h=mid-1;
            }
        }
        return ans;
    }
    /*
     *  Above question can be asked like : find out how many times does an array has been rotated.
     *  answer is the index of the minimum value in the array.
     */



}
