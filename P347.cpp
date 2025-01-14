p347. Top K frequent element
/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> res;
        for (auto i:nums){
            map[i]++;
        }
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>, greater<pii>> pq; // frequency, value in nums
        for (auto& elem:map){
            pq.push(pii(elem.second, elem.first));
            if (pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
