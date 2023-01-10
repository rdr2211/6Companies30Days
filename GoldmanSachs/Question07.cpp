/*
Company :- Goldman Sachs
7. Count Good Triplets in an Array

You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

 

Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation: 
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
 

Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        // Used policy based data structure (pbds)
        int n = nums1.size();
        vector<int> pos(n); 
        
        for(int i = 0; i < n; i++){
            pos[nums2[i]] = i;
        }
        vector<int> pref(n) , suff(n);
        ordered_set s,s2;
        for(int i = 0; i < n; i++){
            pref[i] = s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
       
        for(int i = n-1; i >= 0; i--){
            suff[i] = s2.order_of_key(-pos[nums1[i]]);
            s2.insert(-pos[nums1[i]]);
        }
        long long ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = ans + pref[i]*1LL*suff[i];
        }
        return ans;
    }
};
