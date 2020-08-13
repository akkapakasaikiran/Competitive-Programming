#include<bits/stdc++.h>
using namespace std;
#define test(t) int t; cin>>t; while(t--)

int main(){
	test(t){
		int a,b; cin>>a>>b;
		if(a == b) cout<<0<<endl;
		else{
			if(a < b){
				int tmp = a; a = b; b = tmp;
			}
			int diff = a - b;
			if(diff%5 == 1 || diff%5 == 2) cout<<diff/5 + 1<<endl;
			else cout<<diff/5 + 2<<endl;
		}
	}


}