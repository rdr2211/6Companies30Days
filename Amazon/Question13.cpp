/*
Company :- Amazon
13. Top K Frequent Words

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
*/
class myComp{
public:
    bool operator()(pair<int, string> a, pair<int, string> b){
        if(a.first > b.first) return true;
        else if(a.first == b.first && a.second < b.second) return true;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string, int> mp;
        for(auto i : words){
            mp[i]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
        for(auto i : mp) {
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
