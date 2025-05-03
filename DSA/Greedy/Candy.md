```
A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid.
These kids are receiving candy, according to the following criteria:
1) There must be at least one candy for every child.
2) Kids whose scores are higher than their neighbours receive more candies than their neighbours.
Return the minimum number of candies needed to distribute among children.

Input : ratings = [1, 0, 5]
Output : 5
Explanation : The distribution of candies will be 2 , 1 , 2 to first , second , third child respectively.

Input : ratings = [1, 2, 2]
Output : 4
Explanation : The distribution of candies will be 1 , 2 , 1 to first , second , third child respectively.
              The third gets only 1 candy because it satisfy above two criteria.

```
### Bruteforce:
```
First, scan the children from left to right, giving more candies to those with higher ratings than the child before them.
Then, scan from right to left, ensuring children with higher ratings than the children after them also get more candies.
The total number of candies needed is the sum of the maximum number of candies assigned from both directions for each child.
for example: ratings = [1,0,5]
when we look at left neighbours only:
candies to be given
for rating 1 : 1 - no left neighbour
for rating 0 : 1 - rating is less than left neighbour
for rating 5 : 2 - raging greater than left neighbour, increase candies just by 1 ( to use minimum )
candies: [1 , 1, 2]
when we look at right neighbours only:
candies to be given
for rating 1 : 2 - rating is greater than right neighbour
for rating 0 : 1 - rating is less than right neighbour
for rating 5 : 1 - no right neighbour
candies : [2, 1, 1]
by checking both directions:
for rating 1: we should give max of left and right directions which is : 2
for rating 2: we should give max of left and right directions which is : 1
for rating 5: we should give max of left and right directions which is : 2
Answer: [2, 1, 2 ] total = 5
```
```
public int candy(int[] ratings) {
    int n = ratings.length;
    int[] left = new int[n];
    int[] right = new int[n];
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++){
        if(ratings[i] > ratings[i-1]){
            left[i]=left[i-1]+1;
        }
        else{
            left[i]=1;
        }
        if(ratings[n-1-i] > ratings[n-i]){
            right[n-i-1] = right[n-i]+1;
        }else{
            right[n-i-1] = 1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += Math.max(left[i],right[i]);
    }
    return ans;
}
```
### Optimal using slope concept:
```java
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int sum=1;
        int i = 1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                sum += peak+1;
                peak++;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            sum += down>peak ? down-peak : 0;
        }
        return sum;
    }
}

```
