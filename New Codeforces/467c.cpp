#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
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

	int n,m,k; cin>>n>>m>>k;
	vi a; tkii(a,n);

	vector<ll> pre;
	pre.pb(0);
	rep(i,n) pre.pb(pre[i]+a[i]);

	vector<vector<ll> > dp;
	rep(i,n+1){
		vector<ll> tmp; tmp.resize(k+1);
		dp.pb(tmp);
	}

	rep(i,n+1){
		rep(j,k+1){
			if(i-m >= 0 && j >= 1){
				dp[i][j] = max(dp[i-1][j],dp[i-m][j-1] + pre[i]-pre[i-m]);
			}
		}
	}

	cout<<dp[n][k]<<endl;
}