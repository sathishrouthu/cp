package BS_On_Answer;

public class KoKoEatingBananas {
    /*
     * A monkey is given ‘n’ piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. An integer ‘h’ is also given,
     * which denotes the time (in hours) for all the bananas to be eaten. Each hour, the monkey chooses a non-empty pile 
     * of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas
     * and won’t eat any more bananas in that hour. 
     
      Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
        Example 1:
            Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
            Result: 5
            Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. 
                        So, he will take 8 hours to complete all the piles.  
        Example 2:
            Input Format: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
            Result: 25
            Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. 
            So, he will take 5 hours to complete all the piles.
    */
    public static int findMax(int[] v) {
        int maxi = Integer.MIN_VALUE;;
        int n = v.length;
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = Math.max(maxi, v[i]);
        }
        return maxi;
    }

    public static int calculateTotalHours(int[] v, int hourly) {
        int totalH = 0;
        int n = v.length;
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += Math.ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

    public static int minimumRateToEatBananas(int[] v, int h) {
        int low = 1, high = findMax(v);

        //apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(v, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

}
