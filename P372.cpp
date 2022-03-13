/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

 

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
*/

class Solution {
public:
    int mypow(int a, int b){
        if (b == 0){
            return 1;
        }
        if (b%2 == 0){
            // event number
            int tmp = ( mypow(a, b/2) )%1337;
            return (tmp*tmp)%1337;
        }else{
            // odd number
            return ((a%1337)*mypow(a, b-1))%1337;
        }
    }
    
    int superPow(int a, vector<int>& b) {
        //a^b
        if(!b.empty()){
            // a^[1 3] = a^3 * (a^1)^10
            int tmp = b.back();
            b.pop_back();
            return ( (mypow(a,tmp))%1337 * (mypow(superPow(a, b), 10))%1337 )%1337;
        }else{
            return 1;
        }
    }
};
