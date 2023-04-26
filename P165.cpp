/*
Given two version numbers, version1 and version2, compare them.
Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".
Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
*/
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int ans = 0;
        int n1 = v1.size(), n2 = v2.size();
        
        for(int i=0,j=0; i<n1 || j<n2; ++i, ++j) {
            
            string s1 = "", s2 = "";
            // get part of in version1
            while(i<n1 && v1[i] != '.') {
                // remove prefix 0's
                if(s1.size() == 0 && v1[i] == '0') {
                    ++i; continue;
                }
                
                s1 += v1[i++];
            }
            // get part of version2
            while(j<n2 && v2[j] != '.') {
                // remove prefix 0
                if(s2.size() == 0 && v2[j] == '0') {
                    ++j; continue;
                }
                
                s2 += v2[j++];
            }
            // calculate length
            if(s1.size() < s2.size()) return -1;
            else if(s2.size() < s1.size()) return 1;
            // same length
            ans = s1.compare(s2);
            if(ans < 0) return -1;
            else if(ans > 0) return 1;
        }
        
        return 0;
    }
};
