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
vi depth;

void dfs(int u){
	for(int v : a[u]) if(depth[v] == -1){
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int main(){
	fastio;

	int n; cin>>n;
	a.resize(n+1); depth.resize(n+1,-1);

	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}

	depth[1] = 0;
	dfs(1);

	vi order; tkii(order,n);
	vi depths;
	for(int x : order) depths.pb(depth[x]);

	vi sdepths = depths;
	sort(all(sdepths));
	if(sdepths == depths) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}