/*
Company :- Goldman Sachs
2. Valid Square

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
Example 3:

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true
 

Constraints:

p1.length == p2.length == p3.length == p4.length == 2
-104 <= xi, yi <= 104
*/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1 == p2 || p2 == p3 || p3 == p4 || p2 == p4 || p3 == p1 || p1 == p4) return false;

        int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;

        n1 = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
        n2 = pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2);
        n3 = pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2);
        n4 = pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2);
        n5 = pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2);
        n6 = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);

        unordered_set<int> st;
        st.insert(n1); st.insert(n2); st.insert(n3); st.insert(n4); st.insert(n5); st.insert(n6);
        if(st.size() == 2) return true;
        return false;
    }
};
