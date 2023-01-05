/*
Company :- Microsoft
9. Number of Pairs Satisfying Inequality

You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

 

Example 1:

Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
Output: 3
Explanation:
There are 3 pairs that satisfy the conditions:
1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
Therefore, we return 3.
Example 2:

Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
Output: 0
Explanation:
Since there does not exist any pair that satisfies the conditions, we return 0.
 

Constraints:

n == nums1.length == nums2.length
2 <= n <= 105
-104 <= nums1[i], nums2[i] <= 104
-104 <= diff <= 104
*/
#define ll long long
struct SEG {
    vector<vector<ll>> v;
    ll siz = 1;
    
    SEG(ll n, vector<ll> &ar) {
        siz = 1;
        while(siz <= n) siz <<= 1;
        v.resize(2 * siz);
        build(0, siz - 1, 0, ar);
    }
    
    void merge(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
        int i = 0, j = 0;
        while(i < b.size() and j < c.size()) {
            if(b[i] < c[j]) a.push_back(b[i++]);
            else a.push_back(c[j++]);
        }
        while(i < b.size()) {
            a.push_back(b[i++]);
        }
        while(j < c.size()) {
            a.push_back(c[j++]);
        }
    }

    void build(ll lx, ll rx, ll x, vector<ll> &ar) {
        if(lx == rx) {
            if(lx < ar.size()) {
                v[x].push_back(ar[lx]);
            }
            return;
        }
        ll mid = lx + (rx - lx) / 2;
        build(lx, mid, 2 * x + 1, ar);
        build(mid + 1, rx, 2 * x + 2, ar);
 
        merge(v[x], v[2 * x + 1], v[2 * x + 2]);
    }
    
    //count of numbers greater than equal to val
    ll cnt(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(lx > r or rx < l) return 0;
        if(lx >= l and rx <= r) {
            int ind = lower_bound(v[x].begin(), v[x].end(), val) - v[x].begin();
            return v[x].size() - ind;
        }
        ll mid = lx + (rx - lx) / 2;
        return cnt(l, r, val, 2 * x + 1, lx, mid) + cnt(l, r, val, 2 * x + 2, mid + 1, rx);
    }
    ll cnt(ll l, ll r, ll val) {
        return cnt(l, r, val, 0, 0, siz - 1);
    }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();
        vector<ll> v(n);
        for(int i = 0; i < n; ++i) v[i] = a[i] - b[i];
        
        SEG tree(n, v);
        
        ll pairs = 0;
        for(int i = 0; i < n; ++i) {
            pairs += tree.cnt(i + 1, n - 1, v[i] - diff);
        }
        return pairs;
    }
};
