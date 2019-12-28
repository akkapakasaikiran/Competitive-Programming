#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a;
		vector<int> b;
		int tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			a.push_back(tmp);
		}
		for(int i=0;i<n;i++){
			cin>>tmp;
			b.push_back(tmp);
		}

		/*for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++) cout<<b[i]<<" ";
		cout<<endl;*/

		int s=-1,e=-1;
		bool ok = true;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i] && s==-1) s=i;
			else if(a[i]!=b[i] && e==-1) continue;
			else if(a[i]!=b[i] && e!=-1) ok=false;
			else if(a[i]==b[i] && s==-1) continue;
			else if(a[i]==b[i] && e!=-1) continue;
			else if(a[i]==b[i] && e==-1) e=i; 
		}
		if(s!=-1 && e==-1) e=n;

		/*cout<<s<<" "<<e<<endl;*/

		if(not(ok)){
			cout<<"NO"<<endl;
			continue;
		}

		if(s==-1 && e==-1){
			cout<<"YES"<<endl;
			continue;
		}

		int diff=a[s]-b[s];
		for(int i=s;i<e;i++){
			if(a[i]-b[i]!=diff) ok = false;
		}

		if(not(ok) || diff>0){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			cout<<"YES"<<endl;
			continue;
		}
	}
}