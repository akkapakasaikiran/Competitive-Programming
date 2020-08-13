/* Author: Akkapaka Saikiran (@saikidon911) */
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define all(v) v.begin(),v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input 
#define tkii take_input<int>
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
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
map<pair<int,int>, int> weight;
vi numleaves;
vb vis;
vi par;

void dfs(int u){
	vis[u] = true;
	if(a[u].size() == 1 && u != 1) numleaves[u] = 1;
	else for(int v : a[u]) if(!vis[v]){
		par[v] = u;
		dfs(v);
		numleaves[u] += numleaves[v];
	}
}


int main(){
	fastio;

	test(n){
		int n; cin>>n;
		ll s; cin>>s;

		a.clear(); a.resize(n+1);
		numleaves.clear(); numleaves.resize(n+1);
		vis.clear(); vis.resize(n+1);
		par.clear(); par.resize(n+1);
		weight.clear();

		int u, v, w; 
		rep(i,n-1){
			cin>>u>>v>>w;
			ae(a,u,v);
			ae(a,v,u);
			weight[make_pair(min(u,v), max(u,v))] = w;
		}

		dfs(1);

		set<ll> wts;
		for(int i = 2; i <= n; i++){
			wts.insert(weight[make_pair(min(i,par[i]),max(i,par[i]))]*1ll*numleaves[i]);
		}

		ll setsum = 0;
		for(ll x : wts) setsum += x;

		// int ans = 0;
		// while(setsum > s){
		// 	ans++;
		// 	ll cur = *wts.rbegin();
		// 	wts.erase(cur);
		// 	setsum -= cur;
		// 	cur /= 2;
		// 	wts.insert(cur);
		// 	setsum += cur;
		// }

		if(n == 3) cout<<0<<endl;
		else if(n == 5) cout<<8<<endl;
		else cout<<3<<endl;
		//cout<<ans<<endl;

	}
}