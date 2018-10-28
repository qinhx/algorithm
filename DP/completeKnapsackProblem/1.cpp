#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int>dp(amount+1,INT_MAX);
		dp[0]=0;
        int len = coins.size();
        for(int i=0;i<=coins.size();i++){
        	for(int j= 0;j<=amount;j++){
        		if((j-coins[i])>=0&&dp[(j-coins[i])]<INT_MAX){
        			dp[j] = min(dp[j],dp[j-coins[i]]+1);
				}
			}
		}
		
		return dp[amount]==INT_MAX ? -1:dp[amount]; 
    }
};
int main(){
	vector<int> coin;
	coin.push_back(2);
	Solution solu;
	cout<<solu.coinChange(coin,10)<<endl;
}
