
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // [key value]
        // [target-num[i], i]
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); ++i){
            if (m.count(nums[i])){
                return vector<int>{m[nums[i]], i};
            }
            m[target-nums[i]] = i;
        }
        return vector<int>();
    }
};
