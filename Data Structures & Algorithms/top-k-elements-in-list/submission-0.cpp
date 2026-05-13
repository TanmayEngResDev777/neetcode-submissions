class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* Sorting Approach
        unordered_map<int, int> count;
        for(int num : nums){
            count[num]++;
        } 

        vector<pair<int, int>> arr;
        for(const auto& p : count){
            arr.push_back({p.second, p.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(arr[i].second);
        }

        return res;
        */

        // Bucket Sort
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for(int num : nums){
            count[num]++;
        } 

        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for(int i = freq.size() - 1; i > 0; i--){
            for(int n : freq[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;

    /* MinHeap Approach
    unordered_map<int, int> count;
    for(int num : nums){
        count[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for(const auto& entry : count){
        heap.push({entry.second, entry.first});
        if(heap.size() > k){
            heap.pop();
        }
    }

    vector<int> res;
    for(int i = 0; i < k; i++){
        res.push_back(heap.top().second);
        heap.pop();
    }
    return res;
    */
    }
};
