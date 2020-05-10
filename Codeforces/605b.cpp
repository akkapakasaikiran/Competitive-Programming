#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int q; cin>>q;
	while(q--){
		int l=0,r=0,u=0,d=0;
		string s;
		cin>>s;
		char c;
		for(int i=0;i!=s.size();i++){
			c=s[i];
			if (c=='L') l++;
			else if (c=='R') r++;
			else if (c=='U') u++;
			else if (c=='D') d++;
			else break;
		}
		int x=min(r,l);
		int y=min(u,d);
		if(y==0 && x==0) cout<<0<<endl<<""<<endl;
		else if(x==0 && y!=0) cout<<2<<endl<<"UD"<<endl;
		else if(y==0 && x!=0) cout<<2<<endl<<"LR"<<endl;
		else{
			cout<<2*(x+y)<<endl;
			for(int i=0;i<x;i++) cout<<"L";
			for(int i=0;i<y;i++) cout<<"U";
			for(int i=0;i<x;i++) cout<<"R";
			for(int i=0;i<y;i++) cout<<"D";
			cout<<endl;
		}
	}
}