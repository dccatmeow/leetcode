/*
Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. 
Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1
otherwise speed = 1
Your position stays the same.
For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.

Example 1:

Input: target = 3
Output: 2
*/

class Solution {
public:
    int racecar(int target) {
        // three cases
        // case 1: AAAAA
        // case 2: 0,....target,....l AAAAA+R+dp(l-target)
        // case 3
        // 0,.......p AA+R
        // 0,..l A+R
        //     l........target dp(target-l)
        // dp[i] the minimum move to get from 0 to i, 0 has speed=1
        // AAAA number of A is j position is like 1+2+2^2+...+2^(j-1)
        // 2^(j)-1 = target
        vector<int> dp(2*target, 10000);
        dp[0] = 0;
        // case 1: all A
        int pos(0);
        int speed(1);
        int j(0); // number of A
        vector<int> Avec; // Avec[j]=pos
        Avec.push_back(0);
        while (pos<target){
            pos += speed;
            ++j;
            speed = speed*2;
            dp[pos] = j;
            Avec.push_back(pos);
        }
        for (int i=1; i<=target; ++i){
            if (dp[i]!=10000){
                // case 1 already filled
                continue;
            }
            
            // case 3
            // p is the number of A before target
            // 0,..............Avec[p]
            // 0,.........k
            // 0,.........k,..................i
            for (int p=1; Avec[p]<i;++p){
                // turn back
                for (int q=0; Avec[q]<Avec[p];++q){
                    // turn back
                    int k =  Avec[p] - Avec[q];
                    dp[i]= min(dp[i], p+1+q+1+dp[i-k]);
                }
            }
            // case 2
            // number of A
            int n = lower_bound(Avec.begin(), Avec.end(), i)-Avec.begin();
            dp[i] = min(dp[i], n+1+dp[Avec[n]-i]);
        }
        return dp[target];
    }
};
