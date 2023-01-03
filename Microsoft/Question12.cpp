/*
Company :- Microsoft
1392. Longest Happy Prefix

A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.
*/

// Good examle of KMP Algorithm

class Solution {
public:
    string longestPrefix(string s) {
        string ans = "";
        int n = s.length();

        vector<int> prefix(n, 0);
        int left = 0, i = 1;
        while(i < n){
            if(s[left] == s[i]){
                prefix[i] = left + 1;
                left++; i++;
            }else{
                if(left == 0) i++;
                else left = prefix[left - 1];
            }
        }
        ans = s.substr(0, left);
        return ans;
    }
};
