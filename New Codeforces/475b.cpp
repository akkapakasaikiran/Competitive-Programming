#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define si set<int>
#define pb push_back

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); }
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

void rsort(vector<int> &v){
	sort(v.begin(),v.end(),greater<int>());
}

////////////////////////////////////////
#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

////////////////////////////////////////

vvi a;
vvi rev;
vb vis;

void dfs(vvi g,int u){
	vis[u] = true;
	for(int v : g[u]){
		if(!vis[v]) dfs(g,v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m; cin>>n>>m;
	a.resize(n*m); vis.resize(n*m); rev.resize(n*m);

	string s;
	cin>>s;
	rep(i,n){
		if(s[i] == '<') rep(j,m-1){ ae(a,i*m+j+1,i*m+j); ae(rev,i*m+j,i*m+j+1); } 
		else rep(j,m-1){ ae(a,i*m+j,i*m+j+1); ae(rev,i*m+j+1,i*m+j); }
	}
	cin>>s;
	rep(j,m){
		if(s[j]=='^') rep(i,n-1){ ae(a,(i+1)*m+j,i*m+j); ae(rev,i*m+j,(i+1)*m+j); }
		else rep(i,n-1){ ae(a,i*m+j,(i+1)*m+j); ae(rev,(i+1)*m+j,i*m+j); }
	}

	dfs(a,0);
	bool ok = true;
	rep(i,n*m) if(!vis[i]) ok = false;

	vis.clear(); vis.resize(n*m);
	dfs(rev,0);
	rep(i,n*m) if(!vis[i]) ok = false;

	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}