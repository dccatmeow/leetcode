//4. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n)/2;
        // if ((m+n)%2==0) mid-1, mid
        // else mid
        int i=0; 
        int j=0;
        int cnt=0;
        double res(0);
        while(i<m && j<n){
            if (nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
            cnt++;
            if (cnt == mid){
                // i,j,i-1,j-1
                priority_queue<int> pq;
                if (i<m){
                    pq.push(nums1[i]);
                }
                if (i>0){
                    pq.push(nums1[i-1]);
                }
                if (j<n){
                    pq.push(nums2[j]);
                }
                if (j>0){
                    pq.push(nums2[j-1]);
                }
                if (i<m && j<n){
                    // one of i or j is above mid
                    // pop extra item
                    pq.pop();
                }
                if ((m+n)%2==0){
                    res += pq.top(); // mid
                    pq.pop();
                    res += pq.top(); // mid-1
                    return res/2;
                }else{
                    return pq.top();
                }
            }
        }
        // one vector comes to the end
        if (i==m){
            j +=mid-cnt;
            if ((m+n)%2==0){
                res = nums2[j]+nums2[j-1];
                return res/2;
            }else{
                return nums2[j]; 
            }
        }else{
            i+=mid-cnt;
            if ((m+n)%2==0){
                res = nums1[i]+nums1[i-1];
                return res/2;
            }else{
                return nums1[i]; 
            }
        }
        return res;
    }
};
