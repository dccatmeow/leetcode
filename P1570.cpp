/*
1570. Dot Product of Two Sparse Vectors
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

 

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
*/


class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i=0; i<nums.size();++i){
            if (nums[i]!=0){
                v.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i=0;
        int j=0;
        int res(0);
        while(i<vec.v.size() && j<v.size()){
            int id1 = vec.v[i].first;
            int id2 = v[j].first;
            if (id1==id2){
                res+=vec.v[i].second*v[j].second;
                i++;
                j++;
            }else if (id1<id2){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
    vector<pair<int,int>> v;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
