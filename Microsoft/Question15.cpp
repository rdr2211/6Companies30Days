/*
Company:- Microsoft
15. Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        int prev = 0, left = 0, right = 0;
        while(left < n && right < n){
            map<char, int> mp1;
            while(right < n){
                mp1[s[right]]++;
                if(mp1['a'] != 0 && mp1['b'] != 0 && mp1['c'] != 0){
                    break;
                }
                right++;
            }
            if(right == n) break;

            left = right;
            map<char, int> mp2;
            while(left >= 0){
                mp2[s[left]]++;
                if(mp2['a'] != 0 && mp2['b'] != 0 && mp2['c'] != 0){
                    break;
                }
                left--;
            }

            count += (left - prev + 1)*(n - right);
            prev = left + 1;
            right = prev;
        } 

        return count;
    }
};
