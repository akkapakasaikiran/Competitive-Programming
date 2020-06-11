#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
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

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}

#define prg print_graph
void print_graph(vector<vector<int> > &a){
	rep(i,20){ cout<<i<<" : "; for(int x : a[i]){ cout<<x<<" ";} cout<<endl; }
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<vector<int> > factors; factors.resize(1e5+1);
	rep1(i,1e5){
		rep1(j,sqrt(i)){
			if(j == 1) factors[i].pb(j);
			else if(i%j == 0){
				factors[i].pb(j);
				factors[i].pb(i/j);
			}
		}
	}

	test(t){
		int n; cin>>n;
		vi a; a.pb(0); tkii(a,n);
		vi dp;
		rep(i,n+1) dp.pb(1);

		rep1(i,n){
			for(int j : factors[i]){
				if(a[j] < a[i]) dp[i] = max(dp[i],dp[j]+1);
				//else dp[i] = max(dp[i],dp[j]);
			}
		}

		//prvi(dp);
		int ans = 1;
		rep1(i,n){
			ans = max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
}