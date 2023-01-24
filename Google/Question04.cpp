/*
Company :- Google
4. Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = INT_MIN;
 
        int n = fruits.size();
        map<int, int> mp;
        map<int, int> :: iterator it;
        for(auto i : fruits){
            if(mp.size() == 2) break;
            mp[i]++;
        }
        
        int count = 1;
        int res = 0;
        int i = 1;
        while(i < n){
            if(mp.find(fruits[i]) != mp.end()){
                if(fruits[i - 1] == fruits[i]){
                    count++; // for handling conscutive common elements
                }else{
                    res += count; 
                    count = 1;
                }
            }else{
                // To make sure the current distinct element only exist in map
                it = mp.begin();
                while(it != mp.end()){
                    if(it != mp.find(fruits[i - 1])) mp.erase(it);
                    ++it;
                } 
                mp[fruits[i]]++;
                res += count; // this is the count of the consecutive occurence of previous element   
                ans = max(ans, res);
                res = 0; res += count; // this is the count of the consecutive occurence of previous element 
                count = 1;
            }
            i++;
        }
        res += count;
        ans = max(ans, res);

        return ans;
    }
};
