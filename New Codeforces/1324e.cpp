#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
using pii = pair<int,int>; 
#define pb push_back
#define all(v) v.begin(),v.end()
#define llmax 9223372036854775807
#define intmax 2147483647
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9+7;
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input 
#define tkii take_input<int>
template <typename T> void take_input(vector<T> &a, int size){ T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); } }
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){ for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; } cout<<endl; }
/////////////////////////////////////////

int main(){
	fastio;

	int n,h,l,r; cin>>n>>h>>l>>r;
	vi a; tkii(a,n);

	vi pref; pref.pb(0);
	rep(i,n) pref.pb((a[i]+pref.back())%h);

	vvi dp(n+1);
	rep(i,n+1){
		vi tmp(n+1);
		dp[i] = tmp;
	}

	prvi(pref);

	rep1(i,n) rep(j,n+1){
		if(j > i) continue;
		else if(j == 0){
			if(pref[i] >= l && pref[i] <= r) dp[i][0] = 1 + dp[i-1][0];
			else dp[i][0] = dp[i-1][0];
		}
		else{
			if((pref[i]-j+h)%h >= l && (pref[i]-j+h)%h <= r)
				dp[i][j] = 1 + max(dp[i-1][j], dp[i-1][j-1]);
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);	
		} 
	}

	rep(i,n+1) prvi(dp[i]);

	int ans = 0;
	rep(j,n+1) ans = max(ans, dp[n][j]);
	cout<<ans<<endl;
}