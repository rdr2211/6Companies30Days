/*
Company :- Adobe
4. Magical String

A magical string s consists of only '1' and '2' and obeys the following rules:

The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string s itself.
The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.

 

Example 1:

Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 105
*/
class Solution {
public:
    int magicalString(int n) {
        if(n <= 2) return 1;

        // Intuition :- Just to create a vector where we initially going to enter 1 and 2, after that we created a pointer pointing to the last element of vector formed and push backed the temp which is equal to last element and used the counter which when equal to element at the pointer then counter becomes zero, pointer increases, if temp is 2 the it becomes 1 and vice versa. this loop runs until for n - 2 number of times;
        vector<int> nums{1, 2};
        int i = 1, count = 1;
        int temp = nums[i];
        int k = n;
        while(k - 2) {
            nums.push_back(temp);
            count++;
            if(count == nums[i]){
                i++;
                if(temp == 1) temp = 2;
                else temp = 1;
                count = 0;
            }
            k--;
        }

        int ans = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == 1) ans++;
        }

        return ans;
    }
};
