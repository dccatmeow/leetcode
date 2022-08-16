/* quick sort*/

class Solution {
public:
    int partition(vector<int>&nums, int p, int r){
        // partition
        int i=p-1, temp=0;
        for (int j=p;j<r;j++){
            // iterate through all the numbers [p,r)
            // smaller value than pivot| pivor |larger value than pivot
            if (nums[j]<nums[r]){
                // value smaller than pivot should be on the left side of pivot
                // swap nums[j] with nums[i]
                ++i;
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }            
        }
        // swap i+1 and r, put pivot to correct position
        temp = nums[i+1];
        nums[i+1] = nums[r];
        nums[r] = temp;
        return i+1;
    }
    void randomQuickSort(vector<int>& nums, int p, int r){
        if (p<r){
            // randomly pick a position q in [p r]
            // nums[q] is the pivot
            // switch pivot to the end by swapping with nums[r]
            int q = rand()%(r-p)+p;
            int temp = nums[r];
            nums[r] = nums[q];
            nums[q] = temp;
            // pivot at nums[r]
            // after partition 
            // smaller value than pivot| pivor |larger value than pivot
            int pivot = partition(nums, p, r);
            // recursively call random quick sort for left and right part
            randomQuickSort(nums, p, pivot-1);
            randomQuickSort(nums, pivot+1, r);            
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // quick sort
        randomQuickSort(nums, 0, nums.size()-1);
        return nums;
        
    }
};
