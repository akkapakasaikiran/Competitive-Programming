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

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

vvi a;
vb vis;
vi cnt;
vi c;

int dfs(int u){
	vis[u] = true;
	cnt[u] = 1;
	for(int v : a[u]){
		if(!vis[v]) cnt[u] += dfs(v);
		if(c[v] == c[u]) cnt[u]--;
	}
	//cout<<u<<" "<<cnt[u]<<endl;
	return cnt[u];
}

int main(){
	fastio;

	int n; cin>>n;
	a.resize(n+1); vis.resize(n+1);
	cnt.resize(n+1);

	vi p; tkii(p,n-1);
	c.pb(-1);
	tkii(c,n);

	rep(i,n-1) ae(a,p[i],i+2);

	cout<<dfs(1)<<endl;


}