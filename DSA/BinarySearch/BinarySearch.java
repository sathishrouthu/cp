public class BinarySearch {
    public int search(int[] nums, int target) {
        int  l=0,h=nums.length-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) l = mid+1;
            else h = mid-1;
        }
        return -1;
    }
}
