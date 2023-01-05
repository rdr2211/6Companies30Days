/*
Company :- Microsoft
11. Number of Ways to Arrive at Destination

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //First create an adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //Now to calculate miminum time to reach the destination let create an array and initialize all the positions to LONG_INT
        // except starting index
        vector<ll> time(n,LONG_MAX);
        time[0] = 0;
        //Now to store the number of way to reach the node in min time let create another array named way
        //And initialize all the nodes to zero but the number of way to start from the staring index is 1 so initialize it
        vector<ll> way(n,0);
        way[0] = 1;
        //As usual create an priority queue of pair which stores node and time to reach the current node
        priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;//{time,node}
        pq.push({0,0});
        while(!pq.empty()){
            ll currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                ll timeTotravel = it.second;
                // relax adjNode nodes and push in to priority queue
                // adjNode node ways will be updated with current node ways as
                // we find a lesser time for adjNode node
                if(currTime + timeTotravel < time[adjNode]){
                    time[adjNode] = currTime + timeTotravel;
                    pq.push({time[adjNode],adjNode});
                    way[adjNode] = way[node]%mod;
                }
                // if current node time + timeTotravel = adjNode node cost then
                // this is another way to reach the adjNode node with min time
                // so we update adjNode node ways as ways[adjNode] = (ways[node]+way[adjNode])%mod
                else if(currTime + timeTotravel == time[adjNode])
                    way[adjNode] = (way[adjNode]+way[node])%mod;
            }
        }
        return way[n-1];
    }
};
