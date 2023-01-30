/*
Company :- Adobe
7. Number of Matching Subsequences

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Intuition :- Traversing through the character of element of words vector and at the same time checking whether those characters exist in string s in the same order or not, if so we updating the ans with count of such element in words vector
        int ans = 0;
        map<string, int> mp;
        for(auto i : words){
            mp[i]++;
        }

        for(auto i : mp){
            int n = i.first.length();
            int j = 0, k = 0;
            while(k < s.length() && j < n){
                if(i.first[j] == s[k]){
                    j++; k++;
                }else k++;
            }
            if(j == n) ans += i.second;
        }
        return ans;
    }
};
