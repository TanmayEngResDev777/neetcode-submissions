class Solution {
public:
    /* Naive approach
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
    */

    // Hash Map(one pass)
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(map.contains(diff)){
                return {map[diff], i};
            }
            map.insert({nums[i], i});
        }
        return {};
    }
};
