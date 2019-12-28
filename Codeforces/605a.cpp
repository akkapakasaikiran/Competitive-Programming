#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int abs3(int a, int b,int c){
	return abs(a-b)+abs(b-c)+abs(a-c); 
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());
		
		int cur = abs3(a,b,c);
		int best = cur;

		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				for(int k=-1;k<=1;k++){
					cur = abs3(v[0]+i,v[1]+j,v[2]+k);
					if(cur < best) best = cur;
				}
			}
		}
		cout<<best<<endl;
	}
}