#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vii vector<int>::iterator
#define pb push_back
#define all(v) v.begin(),v.end()

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define forv(x,v) for(auto x : v)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp;
	for(int i=0;i<size;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}
#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

//////////////////////

vector<vi> adj;
vector<bool> vis;
vi ans;
vi a; 


void dfs(int u){
	cout<<"dfs "<<u<<endl;
	vis[u]=true;
	if(adj[u].size()==1){
		int v=adj[u][0];
		if((a[u]+a[v])%2==1) ans[u]=1;
		else{
			if(!vis[v]) dfs(v);
			if(ans[v]==-1) ans[u]=-1;
			else ans[u]=ans[v]+1;	
		}
	}
	else if(adj[u].size()==2){
		int v=adj[u][0]; int w=adj[u][1];
		if((a[u]+a[v])%2==1 || (a[u]+a[w])%2==1) ans[u]=1;
		else{
			if(!vis[v]) dfs(v); if(!vis[w]) dfs(w);
			if(ans[v]==-1 && ans[w]==-1) ans[u]=-1;
			else if(ans[v]==-1 && ans[w]!=-1) ans[u]=1+ans[w];
			else if(ans[v]!=-1 && ans[w]==-1) ans[u]=1+ans[v];
			else ans[u]=1+min(ans[v],ans[w]);
		}
	}
	else{
		ans[u]=-1;
	}
	cout<<"ans "<<ans[u]<<endl;;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	adj.resize(n+1);
	vis.resize(n+1);
	ans.resize(n+1,-1);

	a.pb(-1); tkii(a,n); // a.size()==n+1

	for(int i=1;i<=n;i++){
		if(i+a[i]<=n) ae(adj,i,i+a[i]);
		if(i-a[i]>=1) ae(adj,i,i-a[i]);
	}

	prg(adj);
	
	rep(i,n+1) if(!vis[i]) dfs(i);

	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	
}