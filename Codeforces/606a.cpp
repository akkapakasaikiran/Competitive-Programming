#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num_digits(int n){
	int ans=0;
	while(n!=0){
		ans++;
		n/=10;
	}
	return ans;
}

int first_digit(int n){
	string s = to_string(n);
	return stoi(s.substr(0,1));
}

int one_of_len(int len){
	string s;
	while(len--) s.append("1");
	return stoi(s);
}

int main(){
	int q; cin>>q;
	while(q--){
		int n; cin>>n;
		int dig = num_digits(n);
		int fi = first_digit(n);

		int ans = 9*(dig-1);
		if(n/fi>=one_of_len(dig)) ans+= fi;
		else ans+=fi-1;
		cout<<ans<<endl; 
	}
}