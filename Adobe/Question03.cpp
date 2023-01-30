/*
Company :- Adobe
3. K-th Smallest in Lexicographical Order

Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 

Constraints:

1 <= k <= n <= 109
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 1;
        for(--k; k > 0; )
        {            int count = 0;
            for (long long first = static_cast<long long>(result), last = first + 1;
                first <= n; 
                first *= 10, last *= 10) 
            {
                count += static_cast<int>((min(n + 1LL, last) - first)); 
            }
            
            if (k >= count)
            {   
                ++result;
                k -= count;
            }
            else
            {   
                result *= 10;
                --k;
            }
        }
        return result;
    }
};
