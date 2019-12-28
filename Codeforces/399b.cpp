#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

map<ll,ll> len;
map<ll,ll> ans;

ll length(ll n){
	if(n==1) return 1;
	else{
		if(len.find(n)==len.end()) len[n]=2*length(n/2)+1;
		return len[n];
	}
}

ll func(ll n, ll l, ll r){
	//cout<<"call "<<n<<" "<<l<<" "<<r<<endl;
	if(n==0) return 0;
	else if(n==1) return 1;
	else{
		ll len1 = length(n/2);
		//cout<<n/2<<" "<<len1<<" yo"<<endl;
		if(l<=len1){
			//cout<<"ek"<<endl;
			if(r<=len1) return func(n/2,l,r);
			else if(r==len1+1) return func(n/2,l,n/2)+n%2;
			else return func(n/2,l,len1)+func(n/2,1,r-len1-1)+n%2;
		}
		else if(l==len1+1){
			//cout<<"do"<<endl;
			if(r==len1+1) return n%2;
			else return n%2 + func(n/2,1,r-len1-1);
		}
		else return func(n/2,l-len1-1,r-len1-1);
	}
}

int main(){
	ll n,l,r; cin>>n>>l>>r;
	cout<<func(n,l,r)<<endl;
}