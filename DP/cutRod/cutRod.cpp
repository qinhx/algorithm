#include <iostream>
using namespace std;
#include <vector>
class Solution{
	public:
		int	ExtendedBUCutRod(int n,vector<int> p){
			vector<int> sell(n+1);
			for(int i=1;i<n+1;i++){
				sell[i]=p[i-1];
			}
			for(int i=1;i<n+1;i++){
				int max =sell[i];
				for(int j=1;j<i;j++){
					if(max<(sell[j]+sell[i-j]))
						max = sell[j]+sell[i-j];
				}
				sell[i]=max;
			}
			for(int i=1;i<n+1;i++){
				cout<<"长度为 i ："<<i<<" 售价："<<sell[i]<<endl;
			}
			return sell[n];
		}
}; 
int main(){
	int n;
	while(cin>>n){
		vector<int> price(n);//求出n的最高价格 
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			price[i]=tmp;
		}
		Solution solu;
		solu.ExtendedBUCutRod(n,price);
	}
}
