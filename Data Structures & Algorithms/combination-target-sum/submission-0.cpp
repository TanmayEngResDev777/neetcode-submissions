class Solution {
private:
    void dfs(int i, vector<int>& current, int total, vector<int> nums, int target, vector<vector<int>>& res) {
        if(total == target) {
            res.push_back(current);
            return;
        }

        if(total > target || i >= nums.size()) {
            return;
        }

        current.push_back(nums[i]);
        dfs(i, current, total + nums[i], nums, target, res);

        current.pop_back();

        dfs(i + 1, current, total, nums, target, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;
        dfs(0, current, 0, nums, target, res);
        return res;
    }
};
