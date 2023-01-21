/*
Company :- Google
12. Restore IP Addresses

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

1 <= s.length <= 20
s consists of digits only.
*/
class Solution {
public:
    vector<string> ans;
    void helper(int index, string s, string &res, int count){
        if(count == 4 && (index >= s.length())){
            ans.push_back(res);
            return;
        }
        
        if(count > 4 || (count < 4 && index >= s.length())){ 
            return;
        }

        for(int j = 1; j <= 3; j++){
            string k = s.substr(index, j);
            if(stoi(k) <= 255 && !(k[0] == '0' && k.size() > 1)){
                if(res == "") res += s.substr(index, j);
                else {
                    if(res[res.length() - 1] != '.') res += ".";
                    res += k;
                }
                helper(index + j, s, res, count + 1);
                res.erase(res.begin() + index + count, res.end());
            }else continue;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if(n < 4 || n > 12) return ans;

        string res = "";
        int count = 0;
        helper(0, s, res, count);

        sort(ans.begin(), ans.end());
        vector<string> :: iterator ip;
        ip = unique(ans.begin(), ans.end());
        ans.resize(distance(ans.begin(), ip));

        return ans;
    }
};
