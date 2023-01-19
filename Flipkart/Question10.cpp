/*
Company :- Flipkart
10. Distant Barcodes

In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
 

Constraints:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans;
        // Intution  is to get the top frequent elements using priority queue 
        unordered_map<int, int> mp;
        for(auto &i : barcodes){
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto &k : mp){
            pq.push({k.second, k.first});
        }

        while(pq.size() > 1){
            int firstNum = pq.top().second;
            int i = pq.top().first;
            pq.pop();
            int secondNum = pq.top().second;
            int j = pq.top().first; 
            pq.pop();

            ans.push_back(firstNum);
            i--; 
            ans.push_back(secondNum);
            j--;

            if(i > 0){
                pq.push({i, firstNum});
            }
            if(j > 0){
                pq.push({j, secondNum});
            }
        }

        if(pq.size() != 0){
            int num = pq.top().second;
            int i = pq.top().first;
            while(i){
                ans.push_back(num);
                i--;
            }
        }

        return ans;
    }
};
