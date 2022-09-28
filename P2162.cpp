/*
A generic microwave supports cooking times for:

at least 1 second.
at most 99 minutes and 99 seconds.
To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,

You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.

There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.

Return the minimum cost to set targetSeconds seconds of cooking time.

Remember that one minute consists of 60 seconds.

Example 1:

Input: startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
Output: 6
10:00
9:60
  */

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        // case 1 10:00
        int i = targetSeconds/60;
        int j = targetSeconds%60;
        string s1;
        int res(INT_MAX);
        if (i<100){ // *** check for valid cases
            if (i>0){ //**** have first position or not 
                s1 = to_string(i);
                if (j<10){
                    // add a '0' **** need to add a '0' or not
                    s1 = s1 + '0' + to_string(j);
                }else{
                    s1 = s1 + to_string(j);
                }
            }else{
                // **** only have j
                s1 = to_string(j);
            }
            // calculate count for s1 and s2
            res = min(res,count(startAt, moveCost, pushCost, s1));
        }
        
        // case 2 9:60
        string s2;
        if (j<100-60 && i>0 && i<=100){ //**** i=100 is the max this case can use
            // i-1:j+60
            if (i-1>0){
                s2 = to_string(i-1); //** have i-1 or not
            }
            s2 = s2 + to_string(j+60); //** 2 digits for sure
            res = min(res, count(startAt, moveCost, pushCost, s2));
        }
        return res;
    }
    
    int count(int startAt, int moveCost, int pushCost, const string& s){
        char tmpc = startAt+'0';
        int tmp(0);
        for (auto c:s){
            if (c != tmpc){
                tmp+=moveCost;
            }
            tmp+=pushCost;
            tmpc = c; 
        }
        return tmp;
    }
};
