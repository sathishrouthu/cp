**Insert Interval**
```
Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] represents the start and end of the ith interval,
the array represents non-overlapping intervals sorted in ascending order by start[i]. 
Given another array newInterval, where newInterval = [start, end] represents the start and end of another interval,
insert newInterval into Intervals such that Intervals remain non-overlapping and sorted in ascending order by start[i].
Return Intervals after the insertion of newInterval.

Input : Intervals = [ [1, 3] , [6, 9] ] , newInterval = [2, 5]
Output : [ [1, 5] , [6, 9] ]
Explanation : After inserting the newInterval the Intervals array becomes [ [1, 3] , [2, 5] , [6, 9] ].
So to make them non overlapping we can merge the intervals [1, 3] and [2, 5].
So the Intervals array is [ [1, 5] , [6, 9] ].

Input : Intervals = [ [1, 2] , [3, 5] , [6, 7] , [8,10] ] , newInterval = [4, 8]
Output : [ [1, 2] , [3, 10] ]
Explanation : The Intervals array after inserting newInterval is [ [1, 2] , [3, 5] , [4, 8] , [6, 7] , [8, 10] ].
We merge the required intervals to make it non overlapping.
So final array is [ [1, 2] , [3, 10] ].
```
**Solution**
```
As the array is already sorted according to the start of intervals, we need to check where we can add our new interval.
when we insert a new interval in existing intervals, we will see 3 parts in intervals.
1. Intervals which are not overlapping and before the newInterval
2. Intervals which are overlapped with the newInterval
3. Intervals which are not overlapping and after the newInterval
For example:
Intervals = [ [1, 2] , [3, 5] , [6, 7] , [8,10] ] , newInterval = [4, 8]
when we insert new interval:
Intervals = [ [1, 2] , [3, 5] , [4, 8],  [6, 7] , [8,10] ]
now
1. [1, 2] is before newInterval and not over lapping
2. [3, 5] , [4, 8],  [6, 7] are intervals which are getting overlapped.
3. [8,10] is after the newInterval and not over lapping

- we can keep the intervals which are not overlapping as it is in the resultant intervals.
- the intervals which are overlapping we need to merge all of them togther to form a single new interval, and add it to the resultant.
    newInterval = [minimumStartingPoint,maximumEndingPoint] of all the overlapping intervals.
    if [3,5] [4,9], [7,8] are the intervals, the finals interval should be [3,9]
- If there are no overlapping intervals we can just add the given newInterval in the result.
```
```
1. create a resultant array.
2. add each interval to result until an overlap encountered.
    how can we check if an interval to the left is not overlapped with newInterval ?
    if the intervals end time (interval[i][1])  is less than the newinterval's start time. (newInterval[0])
3. now we are at intervals which are getting overlapped, we have to find the merged interval.
    update the newInterval's start and end by checking all overlapped intervals.
    how to check if an interval is overlapped with the new Interval
    if the interval's start time (intervals[i][0]) is less than the newInterval's end time ( newInterval[1] )
4. now add all the remaining intervals on the right side, which are not overlapping
```

```
public int[][] insertNewInterval(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        int i = 0;
        List<int[]> result = new ArrayList<>();
        // left non-overlapping
        while(i<n && intervals[i][1] < newInterval[0]){
            result.add(intervals[i]);
            i++;
        }
        // overlapped
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = Math.min(newInterval[0],intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1],intervals[i][1]);
            i++;
        }
        result.add(newInterval);
        // right non-overlapped
        while(i<n){
            result.add(intervals[i]);
            i++;
        }
        return result.toArray(new int[result.size()][]);
}
```
