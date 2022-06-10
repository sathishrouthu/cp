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

 
