/*
Company :- Google
10. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj[n];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }
        vector<int>v(n, 1e9);
        queue<pair<int, int>>q;
        q.push({k-1, 0});
        v[k-1]=0;
        while(!q.empty()){
            int pos=q.front().first, wt=q.front().second;
            q.pop();
            for(auto it: adj[pos]){
                if(wt+it[1]<v[it[0]]){
                    v[it[0]]=it[1]+wt;
                    q.push({it[0], v[it[0]]});
                }
            }
        }
        for(int i=0; i<v.size(); i++){if(v[i]==1e9){return -1;}}
        return *max_element(v.begin(), v.end());
    }
};
