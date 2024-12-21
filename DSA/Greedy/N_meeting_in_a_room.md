```
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i 
and end[i] is finish time of meeting i. What is the maximum number of meetings that can be accommodated in the meeting room when only
one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

return the answer such that the positions of the meetings that can happen (1 based indexing)

Ex : 

input : 
n = 6
start = 1 3 0 5 8 5
end   = 2 4 6 7 9 9

op : 
1 2 4 5
```
**Solution:**
```
1. we need to start the meetings that can be ended faster.
2. if a meeting need to be started at time t, then the last meeting happened should be ended before t.

- sort the meetings according to their end time in increasing order.
- track the last meeting end time as lastEnded ( initially it will be -1 as no meeting started )
- for each meeting :
    if it's start time is greater than the lastEnded:
        this meeting can be started, increase count / add to the result
    else:
        this cannot be started as it will overlap with previous meeting.
   move to next.
```

**To Return list of meetings:**
```
import java.util.* ; 
class meeting{
    int start;
    int end;
    int pos;
    meeting(int s,int e,int p){
        this.start=s;
        this.end=e;
        this.pos=p;
    }
}
class MyComparator implements Comparator<meeting>{
    @Override
    public int compare(meeting m1,meeting m2){
        if(m1.end<m2.end)
            return -1;
        else if(m1.end>m2.end)
            return 1;
        else if(m1.pos<m2.pos)
            return -1;
        return 1;
    }
}
public class N_meeting_in_a_room{

}
class Solution {
    public static List<Integer> maximumMeetings(int[] start, int[] end) { 
        List<meeting> meets = new ArrayList<>();
        for(int i=0;i<start.length;i++){
            meeting m =new meeting(start[i],end[i],i+1);
            meets.add(m);
        }
        MyComparator mc = new MyComparator();
        Collections.sort(meets,mc);        
        List<Integer> res = new ArrayList<>();
        res.add(meets.get(0).pos);
        int lastEnd = meets.get(0).end;
        for(int i=1;i<start.length;i++){
            if(meets.get(i).start>lastEnd){
                res.add(meets.get(i).pos);
                lastEnd = meets.get(i).end;
            }
        }
        return res;
    }
}
```
**Simpler:**
**To Return max count of meetings**
```
// This will return the count of maximum meetings possible

public int maxMeetings(int[] start, int[] end) {
        int n = start.length;
        int[][] meetings = new int[n][2];
        for(int i=0;i<n;i++){
            meetings[i][0] = start[i];
            meetings[i][1] = end[i];
        }
        Arrays.sort(meetings,(a,b)->a[1]-b[1]);
        int count = 1;
        int lastEnd = meetings[0][1];
        for(int i=1;i<n;i++){
            int s = meetings[i][0];
            int e = meetings[i][1];
            if(s>lastEnd){
                count++;
                lastEnd = e;
            }
        }
        return count;
    }
```
