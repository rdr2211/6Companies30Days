/*
Company :- Amazon
3. Split a String Into the Max Number of Unique Substrings

Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
 

Constraints:

1 <= s.length <= 16

s contains only lower case English letters.
*/
class Solution {
public:
    // Intuition :- try to make small substrings to have makimium unique elements which can be done using backtracking. Learned we cannot delete a element from the map just by mp[elemnt]-- for that we to use iterator in erase function
    int res = 1;
    void helper(int idx, string s, map<string, int> &mp, int count, map<string, int> :: iterator it){
        if(idx >= s.length() && count > 1) {
            res = max(res, count);
            return;
        }

        for(int i = idx + 1; i <= s.length(); i++) {
            string temp = s.substr(idx, i - idx);
            if(mp.find(temp) == mp.end()) {
                mp[temp]++;
                it = mp.find(temp);
                helper(i, s, mp, count + 1, it);
                mp.erase(it);
            }
        }
    }
    int maxUniqueSplit(string s) {
        map<string, int> mp;
        map<string, int> :: iterator it;
        helper(0, s, mp, 0, it);

        return res;
    }
};
