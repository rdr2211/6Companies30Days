/*
Company :- Adobe
5. Non-negative Integers without Consecutive Ones

Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

 

Example 1:

Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Example 2:

Input: n = 1
Output: 2
Example 3:

Input: n = 2
Output: 3
 

Constraints:

1 <= n <= 109
*/
class Solution {
public:
    int findIntegers(int n) {
        vector<int> dpZero(32), dpOne(32), dp(32);
        dpZero[0] = dp[0] = 1;
        for (int i = 1; i < 32; ++i) {
            dpOne[i] = dpZero[i-1];
            dpZero[i] = dpZero[i-1] + dpOne[i-1];
            dp[i] = dpZero[i] + dpOne[i];
        }
        int ans = 0, lastBit = -1;
        for (int k = 30; k >= 0; --k) {
            int bit = (n >> k) & 1;
            if (bit == 1) {
                ans += dp[k];
                if (lastBit == 1) return ans; 
            }
            lastBit = bit;
        }
        return ans + 1; 
    }
};
