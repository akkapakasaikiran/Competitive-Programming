#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>; 
using pii = pair<int,int>; using vll = vector<ll>;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////// 
#define tkii tki<int>
template <typename T> void tki(vector<T> &a, int sz){ T tmp; for(int i=0;i<sz;i++){cin>>tmp; a.pb(tmp);}}
#define prvi prv<int>
template <typename T> void prv(vector<T> v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////

vi memod;
vi memo;

int rec(int n, int k){
	//cout<<"rec call for "<<n<<endl;
	if(n < 0) return 0;
	else if(n == 0) return 1;
	else{
		if(memo[n] == -1){
			memo[n] = 0;
			rep1(i,k){
				memo[n] = (memo[n] + rec(n-i,k))%mod;
			}
		}
		return memo[n];
	}
} 

int recd(int n, int k, int d){
	//cout<<"recd call for "<<n<<endl;
	if(n < d) return 0;
	else if(n == d) return 1;
	else{
		if(memod[n] == -1){
			memod[n] = 0;
			rep1(i,d-1) memod[n] = (memod[n] + recd(n-i,k,d))%mod;
			for(int i = d; i <= k; i++) memod[n] = (memod[n] + rec(n-i,k))%mod;
		}
		return memod[n];
	}
}



int main(){
	fastio;
	
	int n,k,d; cin>>n>>k>>d;

	rep(i,n+1){
		memod.pb(-1); 
		memo.pb(-1);
	}

	cout<<recd(n,k,d)<<endl;
}