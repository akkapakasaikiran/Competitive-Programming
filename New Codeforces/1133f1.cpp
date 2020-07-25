/* Author: Akkapaka Saikiran (@saikidon911) */
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

vvi a, b;
queue<int> q;
vb vis;

int main(){
	fastio;

	int n,m; cin>>n>>m;
	a.resize(n+1);
	b.resize(n+1);
	vis.resize(n+1);

	int u,v; 
	rep(i,m){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}

	int maxdeg = 0;
	int node = -1;
	rep1(i,n) if(a[i].size() > maxdeg){
		maxdeg = a[i].size();
		node = i;
	}

	vis[node] = true;
	q.push(node);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : a[u]) if(!vis[v]){
			vis[v] = true;
			q.push(v);
			ae(b,u,v);
		}
	}

	rep1(i,n) if(!b[i].empty()) for(int v : b[i]) cout<<i<<" "<<v<<endl;
	
}