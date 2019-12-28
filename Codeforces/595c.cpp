#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


string ternary(long long n){
	string ans;
	if(n==0) return "0";
	while(n!=0){
		ans.append(to_string(n%3));
		n/=3;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

bool ok(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='2') return false;
	}
	return true;
}

int main(){
	int q; cin>>q;
	while(q--){
		string s; cin>>s;
		long long n = stoll(s);
		//cout<<ternary(n)<<endl;
		//for(int i=0;i<n;i++) cout<<ternary(i)<<endl;
		//cout<<ok(ternary(n))<<"-"<<endl;	
		while(!ok(ternary(n))){
			n++;
			//cout<<ternary(n)<<endl;
		}
		cout<<n<<endl;
		//cout<<ternary(3267)<<endl;
	}
}
