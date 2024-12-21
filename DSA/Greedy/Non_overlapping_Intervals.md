```
Given an array of N intervals in the form of (start[i], end[i]),
where start[i] is the starting point of the interval and end[i] is the ending point of the interval,
return the minimum number of intervals that need to be removed to make the remaining intervals non-overlapping.

Input : Intervals = [ [1, 2] , [2, 3] , [3, 4] ,[1, 3] ]
Output : 1
Explanation : You can remove the interval [1, 3] to make the remaining interval non overlapping.
```
```
This is similar to N Meetings in a room,
you have to maximize the no. of intevrals to be kept and remove minimum overlapping intervals.
instead of returning the maximum count of meetings that can happen,
return the count of the meetings those cannot be conducted.
```
```
    public int MaximumNonOverlappingIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals,(a,b)->a[1]-b[1]);
        int count = 0;
        int lastEnd = -1;
        for(int i=0;i<n;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s>=lastEnd){
                count++;
                lastEnd = e;
            }
        }
        return n-count;
    }
```
