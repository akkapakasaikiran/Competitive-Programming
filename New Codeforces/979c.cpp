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

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){ a[u].pb(v); }

#define prg print_graph
void print_graph(vector<vi> &a){ rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); } }

vvi a;
vb vis;
vi sts; // subtree size
vb path;

void dfs(int u){
	vis[u] = true;
	sts[u] = 1;
	for(int v : a[u]){
		if(!vis[v]){
			dfs(v);
			sts[u] += sts[v];
			if(path[v]) path[u] = true;
		}
	}
}


int main(){
	fastio;

	int n,x,y; cin>>n>>x>>y;

	a.resize(n+1); vis.resize(n+1);
	sts.resize(n+1); path.resize(n+1);

	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}

	path[y] = true;

	dfs(x);

	int z;
	for(int v : a[x]) if(path[v]) z = v;

	ll n1 = (ll)(sts[x] - sts[z]);

	ll n2 = (ll)(sts[y]);

	ll ans = (ll)n * (ll)(n-1) - n1*n2;
	cout<<ans<<endl; 

	
}