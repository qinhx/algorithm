#include <iostream>
using namespace std;
#include <vector>
/*�����������ֵΪ1Ԫ��3Ԫ��5Ԫ��Ӳ������ö����������ٵ�Ӳ�Ҵչ�nԪ��*/
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
