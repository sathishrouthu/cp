public class FirstAndLatsPosition {
    public int[] searchRange(int[] nums, int target) {
        int l = 0;
        int h = nums.length-1;
        int first=-1,last = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                first = mid;
                h=mid-1;
            }
            else if(nums[mid]<target)
                l = mid+1;
            else if(nums[mid]>target)
                h = mid-1;
            
        }
        
        l = 0;
        h = nums.length-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                last = mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
                l = mid+1;
            else
                h = mid-1;
        }
        int ans[] = {first,last};
        return ans;
    }
}
/*

    If questions asked as count the occurences of given number in the array, you can return 
    last-first + 1 if the element exists in array atleast once.
    
    if(first!=-1) 
        return last-first + 1 ;
    return 0;

 */
