/*
Company :- Flipkart
8. Closest Prime Numbers in Range

Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= nums1 < nums2 <= right .
nums1 and nums2 are both prime numbers.
nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.

A number greater than 1 is called prime if it is only divisible by 1 and itself.

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106*/
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = 1e6;
        vector<int> prime(n + 1, 1);
        prime[1] = 0;
        for(int i = 2; i <= sqrt(n); i++){
            if(prime[i] == 1){
                for(int j = i*2 ; j <= n; j += i){
                    prime[j] = 0;
                }
            }
        }

        vector<int> primeNum;
        for(int i = left; i <= right; i++){
            if(prime[i]) primeNum.push_back(i);
        }

        vector<int> ans(2, -1);
        if(primeNum.size() == 0) return ans;
        int m = INT_MAX;
        for(int i = 0; i < primeNum.size() - 1; i++){
            if(primeNum[i + 1] - primeNum[i] < m){
                m = primeNum[i + 1] - primeNum[i];
                ans[0] = primeNum[i]; ans[1] = primeNum[i + 1];
            }
        }

        return ans;
    }
};
