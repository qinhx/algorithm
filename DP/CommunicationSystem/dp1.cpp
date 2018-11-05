#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <algorithm>
#define inf 100000

int main(){

		int case_number;
		cin>>case_number;
		while(case_number--){
			int devices_num,max_bandwidth = 0;
			cin>>devices_num;
			vector<vector<int> > b(devices_num),p(devices_num);
			vector<int>device_choice;
			for(int i=0;i<devices_num;i++){
				int choices_num;
				cin>>choices_num;
				device_choice.push_back(choices_num);
				int bd ,pr;
				for(int j = 0 ;j<choices_num;j++){
					
					cin>>bd>>pr;
					if(bd>max_bandwidth) max_bandwidth =bd;
					b[i].push_back(bd);
					p[i].push_back(pr);
					
				}
			}
			
			vector<vector<int> > dp(devices_num,vector<int>(max_bandwidth+1,inf));
			for(int i=0;i<devices_num;i++){
				for(int j=0;j<=max_bandwidth;j++){
					for(int m=0; m < device_choice[i];m++){
						if(j<=b[i][m]){
							if(i==0)
								dp[i][j] = min(p[0][m],dp[0][j]);
							else
								dp[i][j] = min(dp[i-1][j]+p[i][m],dp[i][j]);
						}
					}
				}
			}
			double maxValue = 0;
			for(int j=0;j<=max_bandwidth;j++){
				if(double(j)/(double)dp[devices_num-1][j] > maxValue){
					maxValue = (double)j / (double)dp[devices_num-1][j];
				}
					
			}
			cout<<maxValue<<endl; 
		}
} 
