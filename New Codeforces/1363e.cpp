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
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

vvi a;
vb vis;
vector<pair<int,int> > delta;
vi change;
vi net;
vi cost;

vi active;

void dfs1(int u){
	vis[u] = true;
	for(int v : a[u]){
		if(vis[v]) continue;
		cost[v] = min(cost[v],cost[u]);
		dfs1(v);	
	}
}

void dfs2(int u){
	vis[u] = true;
	for(int v : a[u]){
		if(vis[v]) continue;
		dfs2(v);
		if(cost[v] == cost[u]){
			delta[u].first += delta[v].first;
			delta[u].second += delta[v].second;
		}
		else{
			active.pb(v);
			delta[u].first += delta[v].first - min(delta[v].first,delta[v].second);
			delta[u].second += delta[v].second - min(delta[v].first,delta[v].second);
		}
	}
	if(change[u] == 1) delta[u].second++;
	else if(change[u] == 0) delta[u].first++;
}

int main(){
	fastio;

	int n; cin>>n;
	a.resize(n+1); vis.resize(n+1);
	change.resize(n+1);
	cost.resize(n+1); net.resize(n+1);
	rep(i,n+1) delta.pb(make_pair(0,0));

	int aa,b,c;
	rep(i,n){
		cin>>aa>>b>>c;
		cost[i+1] = aa;
		if(b == 0 && c == 1) change[i+1] = 1;
		else if(b == 1 && c == 0) change[i+1] = 0;
		else change[i+1] = -1;
	}

	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}

	dfs1(1);

	vis.clear(); vis.resize(n+1);

	dfs2(1);

	if(delta[1].first != delta[1].second) cout<<-1<<endl;
	
	else{

		rep1(i,n) net[i] = 2*min(delta[i].first,delta[i].second);

		active.pb(1);
		ll ans = 0;
		for(int v : active) ans += (ll)cost[v] * (ll)net[v];
		cout<<ans<<endl;
	}
	
}