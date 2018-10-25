#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
class Solution{
	public:
		void getMaxValue(vector<int> c,vector<int> w,int maxV,int n){
			vector<vector<int> > f(n+1,vector<int>(maxV+1,0));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=maxV;j++){
					if(c[i]>j){
						f[i][j]=f[i-1][j];
					}else{
							f[i][j]=max(f[i-1][j],f[i-1][j-c[i]]+w[i]);	
					}
				}
			}
			cout<<f[n][maxV]<<endl;	
		}
		
};
int main(){
	int n,v;;
	n=6;v=17;
	vector<int> c(n+1);
	vector<int> w(n+1);
	c[0]=0;
	w[0]=0; 
	c[1]=3;
	c[2]=4;
	c[3]=7;
	c[4]=8;
	c[5]=9;
	w[1]=4;
	w[2]=5;
	w[3]=10;
	w[4]=11;
	w[5]=13;
	Solution solu;
	solu.getMaxValue(c,w,v,n);
}
