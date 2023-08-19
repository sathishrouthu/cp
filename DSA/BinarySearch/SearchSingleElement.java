import java.util.ArrayList;
/*
 * Given an array in which every element appears exactly twice except one element;
 * find the signle element.
 * 
 * ex : 1 1 2 2 3 4 4 5 5 
 * it can be solved by xor method but it will take O(n).
 * we can apply binary search ( only when the given array is sorted ). it will take O(logn)
 *  
 * if we clearly observe the given array.
 *  arr     = [1 1 2 2 3 4 4 5 5]
 *  indices =  0 1 2 3 4 5 6 7 8
 *             e o e o e o e o e   // o - odd, e- even
 * before single element , every element appears at their index in the order : evenIndex , oddIndex
 * After single element , every element appears at their index the order     : oddIndex, evenIndex
 * we can determine whether we are in left half or right half in the array by checking current element's index order.     
 * 
 */
public class SearchSingleElement {
    public static int singleNonDuplicate(ArrayList<Integer> arr)
    {
        //    Write your code here.
        int n = arr.size();
        if(n==1) return arr.get(0);

        if (!arr.get(0).equals(arr.get(1)))
        return arr.get(0);
        if (!arr.get(n - 1).equals(arr.get(n - 2)))
        return arr.get(n - 1);

        int l=1;
        int h=n-2;
        while(l<=h){
            
            int mid = (l+h)/2;
            if(arr.get(mid)!=arr.get(mid+1) && arr.get(mid)!=arr.get(mid-1)) 
                return arr.get(mid);                   
            if( ( mid%2==0 && arr.get(mid)==arr.get(mid+1) ) || (mid%2==1 && arr.get(mid)==arr.get(mid-1)) )  // left half
                l = mid+1;
            else                                                                                              // right half
                h = mid-1;
        } 
        return -1;
    }
}
