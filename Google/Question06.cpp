/*
Company :- Google
6. Distinct Echo Substrings

Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).

 

Example 1:

Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
Example 2:

Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
 

Constraints:

1 <= text.length <= 2000
text has only lowercase English letters.
*/
class Solution {
public:
    int distinctEchoSubstrings(string tx) {
        unordered_set<string> s;
        for (auto split = 1; split < tx.size() - 1; ++split) {
            for (auto sz = 1; split - sz >= 0 && split + sz - 1 < tx.size(); ++sz) {
                // Using compare fuction of string
                if (tx.compare(split - sz, sz, tx, split, sz) == 0)
                    s.insert(tx.substr(split, sz));
            }
        }
        return s.size();
    }
};
