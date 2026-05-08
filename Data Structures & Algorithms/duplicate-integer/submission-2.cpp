class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /* Approach 1: Naive Version
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
        */

        /* Approach 2: Sorting
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                return true;
            }
        }
        return false;
        */

        // Approach 3: Frequency Map
        unordered_map<int, int> counts;

        for(int n : nums){
            counts[n]++;

            if(counts[n] > 1){
                return true;
            }
        }
        return false;
    }
};