/*
Company :- Goldman Sachs
1. Max Points on a Line

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                //calculating the slope
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if(pt[j][1]-pt[i][1]<0 &&(pt[j][0]-pt[i][0])==0 ) //infinite slop for Perpendicular line
                mp[abs(x)]++; 
                else
               //storing the slop into map
                    mp[x]++;
            }
            // same slope w.r.t.that selected point
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
};
