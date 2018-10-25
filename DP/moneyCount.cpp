#include <iostream>
using namespace std;
#include <vector>
/*如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够n元？*/
vector<int> m(12);
class Solution{
	public:
		void Count(int i,int num){
			if(i==0){
				m[i]=0;
				Count(1,num);
			}else{
				int MIN=999;
				for(int j=1;j<=5;){					
					if(i>=j)
						MIN = min(m[i-j]+1,MIN);
					j=j+2;
				}
				m[i]=MIN;
				if(i==num){
					cout<<m[num]<<endl;
				}
				else
					Count(i+1,num);
			}
		}
};
int main(){
	int n;
	Solution solu;
	while(cin>>n){
		solu.Count(0,n);
	}
}
