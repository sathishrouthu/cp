```
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit 
associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .
The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60
```
**Solution:**

```
We are given n jobs where all jobs takes same time to complete but different profits and different deadlines.
1. we need to complete jobs with max profits first. ( Sort the array as per profits in descending order )
2. Delay the jobs to the end days.
    for example we had a job which has max profit and deadline is x.
    we should try to aloocate this job at the xth day if that days is not already occupied by another job.
    if xth day is already allocated to some other job, which given max profit than this,
    we should try x-1 th day and then x-2 th day and so on..
    because of this, the earlier days will be free which might be useful for the other jobs.

- Sort the jobs as per profits in descening order.
- find the max deadline in the given array
- create and array of length n which represents the days to be allocated for jobs ( inititalize all with -1 )
- for each job:
    x = deadline of current job
        if xth day is already allocated:
            check previous days until an empty slot is found.
        else:
            allocate this job on the xth day.

```

```
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comparison(Job a, Job b){
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparison);
        int maxDead = arr[0].dead;
        for(int i=0;i<n;i++)
            maxDead = max(maxDead,arr[i].dead);
        int count = 0;
        int maxProfit = 0;
        vector<int> schedule(maxDead+1,-1);
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(schedule[j]==-1){
                    schedule[j] = i;
                    maxProfit  += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        
        return{count,maxProfit};
    } 
};
```
