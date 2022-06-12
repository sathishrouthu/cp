### DAY-1

###### 1523. Count Odd Numbers in an Interval Range
* Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
    
```
    
    int countOdds(int low, int high) {
        if(low%2==0 && high%2==0)
            return (high-low)/2;
        else
           return  (1+(high-low)/2);
    }
    
```

###### 1491. Average Salary Excluding the Minimum and Maximum Salary
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

```
    double average(vector<int>& salary) {
        double s= accumulate(salary.begin(), salary.end(), 0); // sum of elements 
        s -= *max_element(salary.begin(), salary.end()); // subtract max
        s -= *min_element(salary.begin(), salary.end()); // subtract min
        return s / (salary.size() - 2);
    }
```

 
### DAY-2

##### 191. Number of 1 Bits

<pre>

counting set(1) bits (no.of 1's in a binary number)

Approach 1 :
-------------
we can use & operator to compare the last (LSB) bit to check whether it is 1 or not 
if it is 1 we count it.
and then we will remove that bit by left shift
ex :

n = 9 ( 1 0 0 1 )
pass1 :                pass2:         pass3:          pass4:   

1 0 0 1                 1 0 0           1 0             1 
0 0 0 1                 0 0 1           0 1             1
-------                -------          ----           -----
0 0 0 1                 0 0 0           0 0             1
count = 1               count=1         count=1         count=2
                          
& operation with 1 will be 1  <--->  LSB is 1

we just use left shift to remove the last bit . 

*/

/*

Approach 2 :
Brian Kernighan's Algorithm:

What will happen if we do & operation between n & (n-1) ?

example of a substraction :

1 0 1 1 0 0     --->  1 0 1 0 1 2     (n)
          1     --->            1
-------------         ------------
                       1 0 1 0 1 1    (n-1)
                       
                                    -->these last 3 bits are toggled version of 1 0 0  which are last 3 bits of initial number (n)
                                    -->the first 3 bits remain unchanged.

and  now if we make & operation b/w  n & n-1

1st iteration :

1 0 1 1 0 0
1 0 1 0 1 1
------------
1 0 1 0 0 0     --> last 3 bits are became 0  i.e; the right most 1 from left in the given number is unset for first iteration.

                --->  in the next iteration the next right most bit will unset.
                --->  no. of times the loop runs is the no. of 1's exist in the binary string.

in the 2nd iteration :

1 0 1 0 0 0   (n-1)
1 0 0 0 0 0   (n-2)
-----------
1 0 0 0 0 0   -->  the right  most 1 became 0

in the 3rd iteration :

1 0 0 0 0 0
0 1 1 0 0 0
------------
0 0 0 0 0 0   ---> the right most 1 became 0 and n became 0 so we stop .

the loop run 3 times and n became 0 
total no. of set bits = 3


</pre>

```

//Naive approach
int count_set_bits(int n)
{
    int count=0;
    while(n>0)
    {
        if(n&1==1)  //checks last bit ( & )
        count++;
        n>>=1;      // removes last bit
    }
    return count;
}

```

```
int brian_Kernighan(int n)
{
    int count=0;
    while(n>0)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
```

### DAY-3

##### 976. Largest Perimeter Triangle
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

say the sidelengths of the triangle are a <= b <= c . The necessary and sufficient condition for these lengths to form a triangle of non-zero area is 
a + b > c
* Sort the array. 
* For any c in the array, we choose the largest possible a≤b≤c:  these are just the two values adjacent to c. 
* If this forms a triangle, we return the answer.

```
 int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-3;i>=0;i--){
            if(nums[i]+nums[i+1]>nums[i+2])
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }

```

##### 1779. Find Nearest Point That Has the Same X or Y Coordinate
You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).

.............................................................................................





