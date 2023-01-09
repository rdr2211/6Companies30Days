/*
4. Count Nice Pairs in an Array

Companies
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
*/
class Solution {
public:
  //My approach was to map patern with the number
    int countNicePairs(vector<int>& nums) {
        int mod = 1000000007;
        long long count = 0;
        int n = nums.size();
        map<long long, long long> mp;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            string k = s;
            reverse(k.begin(), k.end());
            int temp = stoi(k);
            mp[nums[i] - temp]++;
        }

        for(auto i : mp){
            //cout << i.second << endl;
            count += ((i.second * (i.second - 1))/2);
        }
        
        return count % mod;
    }
};
