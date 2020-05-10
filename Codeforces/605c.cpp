#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,k; cin>>n>>k;
	string s; cin>>s;
	bool yes[26]={false};
	char c;
	for(int i=0;i<k;i++){
		cin>>c;
		yes[c-97]=true; 
	}

	long long ans=0;
	int len=0;
	for(int i=0;i<n;i++){
		if(yes[s[i]-97]){
			len++;
			ans+=len;
		}
		else{
			len=0;
		}
	}
	cout<<ans<<endl;
}