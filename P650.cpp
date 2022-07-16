/*
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
*/
class Solution {
public:
    int minSteps(int n) {
        // Dynamic programming
        if (n==1) return 0;
        // n==1 0
        // n==2 2 copy all, paste
        // n==3 3 copy all, paste, paste
        // n==4 4 copy all, paste, copy all, paste or copy all, paste, paste, paste fcn(2)+fcn(2)
        // n==5 min(n-1+1) 5 prime number is just n
        // n==6 min(n; copy all, paste, copy all, paste, paste; copy all, paste, paste, copy all, paste) 5 fcn(2)+fcn(3)
        //*** n==7 prime numbers is just itself fcn(1)+7
        // n==8 4*2 copy all, paste, copy all, paste, copy all, paste 6 fcn(4)+2 or fcn(2)+4 =6
        // n==9 3*3 copy all, paste, paste, copy all, paste, paste fcn(3)+3 =6
        // n==10 5*2 copy all, paste, paste, paste, paste, copy all, paste fcn(5)+2 or fcn(2)+5=7
        
        vector<int> stepCount(n+1,INT_MAX); // considering n=3 case
        stepCount[0] = 0;
        stepCount[1] = 0;
        stepCount[2] = 2;
        for(int i=3; i<n+1; i++){
            // i represent variable dynmically increase till n
            for (int j=1; j<=i/2; j++){ // consider n=3 case
                // loop though cases where factor from 2 until flour(n/2)
                int k = i/j;
                if (i%j == 0){
                    stepCount[i] = min(stepCount[i], (stepCount[j] + k));
                }
            }
            
        }
        
        return stepCount[n];
        
    }
};
