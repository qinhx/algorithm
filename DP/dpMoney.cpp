#include<iostream>
using namespace std;
void dp_fun(int num)
{
	int coin[3] = {1,3,5}; 
	int dp[num+1];
	dp[0]=0;
	for(int i=1;i<=num;i++){
		dp[i]=9999;
		for(int j=0;i>=coin[j]&&j<3;j++){
			if((dp[i-coin[j]]+1)<dp[i])
				dp[i] = dp[i-coin[j]]+1;
		}
	}
	cout<<dp[num]<<endl;
}
int main()
{

	int n;
	while(cin>>n){
		dp_fun(n);
	}
	return 0; 
}

