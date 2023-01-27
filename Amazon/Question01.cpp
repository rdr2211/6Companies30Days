/*
Company :- Amazon
1. Shuffle an Array

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 50
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 104 calls in total will be made to reset and shuffle.
*/
class Solution {
public:
    vector<int> s;
    Solution(vector<int>& nums) {
        s.assign(nums.begin(), nums.end());
    }
    
    vector<int> reset() {
        return s;
    }
    // Intuition :- to shuffle we have to take a random index from [0, n) and swap it with last elemnt, and keep on decreasing index and decreasing the range for finding random index intil we reach first index
    vector<int> shuffle() {
        int n = s.size();
        vector<int> temp(s);

        int k = n;
        for(int i = n - 1; i >= 0; i--){
            int j = rand() % k;
            swap(temp[i], temp[j]);
            k--;
        }

        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
