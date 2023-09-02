package BS_On_Answer;

public class MinDaysForMbouquets {
    /*
     * Minimum days to make M bouquets
        Problem Statement: You are given ‘N’ roses and you are also given an array ‘arr’  where ‘arr[i]’  denotes that the 
        ‘ith’ rose will bloom on the ‘arr[i]th’ day. You can only pick already bloomed roses that are adjacent to make a bouquet. 
        You are also told that you require exactly ‘k’ adjacent bloomed roses to make a single bouquet.
        Find the minimum number of days required to make at least ‘m’ bouquets each containing ‘k’ roses.
        Return -1 if it is not possible.
    
     */
    static int makeBouquet(int[] arr,int r,int day){
        int j=0;
        int cnt=0;
        int n = arr.length;
        int totalBouquets=0;
        while(j<n){
            if(arr[j]<=day)
                cnt++;
            else{
                totalBouquets+=cnt/r;
                cnt=0;
            }
            j++;
        }
        totalBouquets+=cnt/r;
        return totalBouquets;
    }
    static int findMax(int[] arr){
        int max = arr[0];
        for(int i=1;i<arr.length;i++)
            max = arr[i]>max?arr[i]:max;
        return max;
    }
    public static int roseGarden(int[] arr, int r, int b) {
        // Write your code here.
        int n = arr.length;
        if(r*b > n) return -1;
        int l = 1,h = findMax(arr);
        while(l<=h){
            int mid = (l+h)>>1;
            int totalBouquets  = makeBouquet(arr, r, mid);
            if(totalBouquets>=b)    h=mid-1;
            else l=mid+1;
        }
        return l;
    }
}
