/*

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false


*/

bool containsDuplicate(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0;i < nums.size() - 1; i++)
        {
            if(nums.at(i) == nums.at(i + 1))
            {
                return true;
            }
        }
        return false;
    }


/*

bool containsDuplicate(vector<int>& nums) {
  std::unordered_set<int> s(nums.begin(), nums.end());        //converting vector to set
  return s.size() != nums.size();                              // if set and vector are same size the there is no duplicates else there is a duplicate
  }


*/
