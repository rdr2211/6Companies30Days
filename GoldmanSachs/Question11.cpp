/*
Company :- Goldman Sachs
11. Invalid Transactions

A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.

 

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
 

Constraints:

transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.
*/
class Solution {
public:
    vector<string> details(string a){
        vector<string> res;
        string temp = "";
        for(int i = 0; i < a.size(); i++){
            if(a[i] != ',') temp += a[i];
            else{
                res.push_back(temp);
                temp = "";
            }
        }
        res.push_back(temp);
        return res;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> ans;
        vector<vector<string>> check;
        for(int i = 0; i < n; i++){
            vector<string> a = details(transactions[i]);
            check.push_back(a);
        }

        vector<bool> temp(n, false);

        for(int i = 0; i < n; i++){
            if(stoi(check[i][2]) > 1000) temp[i] = true;
            if(i != n - 1){
                for(int j = i + 1; j < n; j++){
                    if(check[i][0] == check[j][0] && abs(stoi(check[i][1]) - stoi(check[j][1])) <= 60 && check[i][3] != check[j][3]){
                        temp[i] = true;
                        temp[j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(temp[i] == true){
                ans.push_back(transactions[i]);
            }
        }
        return ans;
    }
};
