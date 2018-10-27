#include <iostream>
using namespace std;
#include <string>
#include <vector>
class Solution{
	public:
		int LCS(string s1,string s2){
			int l1= s1.size();
			int l2 = s2.size();
			vector<vector<int> > dp(l1+1,vector<int>(l2+1,0));
			for(int i=0;i<=l1;i++){
				for(int j=0;j<=l2;j++){
					if(i==0||j==0)
						dp[i][j]=0;
					else if(s1[i]==s2[j])
						dp[i][j]=dp[i-1][j-1]+1;
					else if(s1[i]!=s2[j]){
						dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
					}
				}
			}
			return dp[l1][l2];
		}
};
int main(){
	string s1 = "ab";
	string s2 = "asd";
	Solution solu;
	cout<<solu.LCS(s1,s2) <<endl;
}
