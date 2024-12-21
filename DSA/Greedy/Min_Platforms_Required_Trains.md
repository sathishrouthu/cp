```
Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day.
Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
```

**Bruteforce:**
```
public int findPlatform(int[] Arrival, int[] Departure) {
        int n = Arrival.length;
        /* Initialize the variable to store the maximum number of platforms needed initialised with 1
        since at least one train will require one platform */
        int ans = 1;

        // Outer loop to iterate each arrival time
        for (int i = 0; i < n; i++) {
            
            /* Initialize the count of overlapping intervals for the current train initialised 
            with 1 since the current train itself requires one platform */
            int count = 1;

            /* Inner loop to compare the
            current train with all other trains */
            for (int j = i + 1; j < n; j++) {
                /* Check if there is an overlap between
                the current train (i) and another train (j)
                There is an overlap if:
                1. The arrival time of train i is between the arrival and departure times of train j
                2. OR the arrival time of train j is between the arrival and departure times of train i */
                if ((Arrival[i] >= Arrival[j] && Arrival[i] <= Departure[j]) ||
                    (Arrival[j] >= Arrival[i] && Arrival[j] <= Departure[i])) {
                    
                    // Increment count
                    count++;
                }
            }

            /* Update the maximum number of platforms needed.
              This keeps track of the highest count of overlapping trains found so far */
            ans = Math.max(ans, count);
        }
        // Return number of platforms
        return ans;
    }
```
**Optimal:**
```
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Consider we have a clock, firstly we start at 0 and track count of required platforms in count variable.
clock at 0900 : train1 arrives - count = 1 ( train arrives - count increases )
clock at 0910 : train1 departs - count = 0 ( train departs - count decreases )
clock at 0940 : train2 arrives - count = 1 
clock at 0950 : train3 arrives - count = 2
clock at 1100 : train4 arrives - count = 3
clock at 1120 : train3 departs - count = 2
clock at 1130 : train4 departs - count = 1
clock at 1200 : train2 departs - count = 0
clock at 1500 : train5 arrives - count = 1
clock at 1800 : train6 arrives - count = 2
clock at 1900 : train5 departs - count = 1
clock at 2000 : train6 departs - count = 0

The max count is 3 which is required no. of platforms.

to check the clock at each event of arrival or departure, we need to sort the timings in the following order:
(0900,A), (0910,D), (0940,A), (0950,A), (1100,A), (1120,A), (1130,D), (1200,D) .......
Or 
we can sort Arrivals and Departs separately and keep two pointers to iterate each array.
```
```
public int findPlatform(int[] Arrival, int[] Departure) {
        int n = Arrival.length;
        Arrays.sort(Arrival);
        Arrays.sort(Departure);
        int i=0,j=0;
        int required = 0;
        int ans = 0;
        while(i<n){
            if(Arrival[i] <= Departure[j]){
                required++;
                i++;
            }else{
                required--;
                j++;
            }
            ans = Math.max(ans,required);
        }
        return ans;
    }
```


```
int findPlatform(int arr[], int dep[], int n)
{
  sort(arr,arr+n);
  sort(dep,dep+n);
  int i=1;
  int j=0;
  int occupied=1,result=1;
  while(i<n){
      if(arr[i]<=dep[j]){
          occupied++;
          i++;
          result = max(occupied,result);
      }
      else{
          occupied--;
          j++;
      }
  }
  return result;
}
```
