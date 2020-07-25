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
void add_edge(vector<set<int> > &a, int u, int v){
	a[u].insert(v);
}

#define prg print_graph
void print_graph(vector<set<int> > &a){
	rep(i,a.size()){ cout<<i<<" : "; for(int x : a[i]){ cout<<x<<" "; } cout<<endl; }
}

vector<set<int> > a;
vb vis;
vi topsort;

void dfs1(int u){
	vis[u] = true;
	for(int v : a[u]) if(!vis[v] && a[v].find(u) == a[v].end()) dfs1(v);
	topsort.pb(u);
}

int main(){
	fastio;

	test(t){
		int n,m; cin>>n>>m;
		a.clear(); vis.clear(); topsort.clear();
		a.resize(n+1); vis.resize(n+1); topsort.resize(n+1);

		int d,u,v;
		rep(i,m){
			cin>>d>>u>>v;
			ae(a,u,v);
			if(d == 0) ae(a,v,u);
		}

		rep1(i,n) if(!vis[i]) dfs1(i);
		reverse(all(topsort));
		vi index(n+1);
		rep(i,n) index[topsort[i]] = i;

		bool ok = true;
		rep1(u,n) for(int v : a[u]) if(a[v].find(u) == a[v].end()){
			if(index[u] > index[v]) ok = false;
		}

		if(!ok) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			// rep1(u,n) for(int v : a[u]) if(a[v].find(u) != a[v].end()){
			// 	if(index[u] < index[v]) a[v].erase(u);
			// 	else a[u].erase(v);
			// }
			rep1(u,n) for(int v : a[u]){
				if(a[v].find(u) == a[v].end()) cout<<u<<" "<<v<<endl;
				else if(index[u] < index[v]) cout<<u<<" "<<v<<endl;
			}
		}


	}
}