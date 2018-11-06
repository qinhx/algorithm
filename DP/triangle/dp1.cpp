#include <iostream>
using namespace std;
#include <vector>
#include <cstring>

class Solution{
	public:
		int MaxSum(vector<vector<int> > t,int n){
			vector<vector<int> > dp(n,vector<int>(n,0));
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==0){
						dp[i][j] = t[i][j];
					}else {
						if(j==0){
							dp[i][j] = dp[i-1][j]+t[i][j];
						}else{
							dp[i][j] = max(dp[i-1][j]+t[i][j],dp[i-1][j-1]+t[i][j]);
						}
					}
				}
			}
			int max =0;
			for(int i=0;i<n;i++){
				if(dp[n-1][i]>max)
					max = dp[n-1][i];
			}
			return max;
		}
};
int main(){
	int n;
	cin>>n;
	vector<vector<int> > t(n,vector<int>(n,0));
	int n1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cin>>n1;
			t[i][j]=n1;
		}		
	}
	Solution solu;
	cout<<solu.MaxSum(t,n)<<endl;
}
