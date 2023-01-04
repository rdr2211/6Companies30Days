/*
Company :- Microsoft
10. Shortest Unsorted Continuous Subarray

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = n - 2;
        // Below code is finding the interval where first abnormality is found while traversing through left -> right and right -> left
        int left = 0; int right = 0;
        while(i < n){
            if(nums[i - 1] > nums[i]){
                left = i - 1;
                break;
            }
            i++;
        }

        while(j >= 0){
            if(nums[j + 1] < nums[j]){
                right = j + 1;
                break;
            }
            j--;
        }

        // Edge case
        if(left == 0 && right == 0) return 0;
        if(left == n - 1 && right == 0) return n;
        
        // Finding the max and min element in the interval that we got.
        int ma = INT_MIN, mi = INT_MAX;
        for(int k = left; k <= right; k++){
            ma = max(nums[k], ma);
            mi = min(nums[k], mi);
        }
        
        // Checking if there is any element greater than min element in the left side of the interval.
        i = left;
        j = right;
        while(i >= 1){
            if(mi < nums[i - 1]){
                left = i - 1;
            }
            i--;
        }
        // Checking if there is any element smaller than max element in the right side of the interval.
        while(j < n - 1){
            if(ma > nums[j + 1]){
                right = j + 1;
            }
            j++;
        }
        
        return right - left + 1;
    }
};
