/*
Company :- Amazon
12. Maximum Length of Repeated Subarray

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //Intuition :- Silding window approach, here i create a pointer for nums1 and pointer for nums2, and for each index of nums1 I kept on matching the longest subarray & if it fails we check if the previous index of nums1 matches with the current index of nums2 if not we move the index of nums1 to initial index and again do the same process with count = 0 otherwise we just move the window slide made in nums2 by 1 to the right
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int ans = 0, count = 0; 
        while(i < n1){
            int temp = i;
            int j = 0;
            map<int, int> mp;
            while(j < n2 && temp < n1){
                mp[nums2[j]]++;
                if(nums1[temp] == nums2[j]) {
                    count++; temp++;
                }else if(nums1[temp] != nums2[j] && count != 0) {
                    ans = max(ans, count);
                    if(nums1[temp - 1] != nums2[j]) {count = 0; temp = i; mp.erase(mp.begin(), mp.end()); continue;}
                    else if(mp.size() != 1) {count = 0; temp = i; mp.erase(mp.begin(), mp.end()); continue;}
                }
                j++;
            }
            ans = max(ans, count);
            count = 0;
            i++;
        }
        return ans;
    }
};
