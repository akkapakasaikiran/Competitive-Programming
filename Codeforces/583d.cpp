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
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define pb push_back
#define all(v) v.begin(),v.end()

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define forv(v) for(auto x : v)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

////////////////////////////////////////////

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

int vmax(vi v){ //positivity assumed
	int ans = 0;
	rep(i,v.size()) if(v[i]>ans) ans = v[i];
	return ans;
}

////////////////////////////////////////

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
	a[v].pb(u);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

/////////////////////////////////////////

vvi adj;
vb vis;
vi low;
vi dfs_num;

int num = 1;

int cnt = 0;

void dfs(int u){
	vis[u]=true;
	dfs_num[u]=num;
	low[u]=num;
	num++;
	for(int v : adj[u]){
		if(!vis[v]) dfs(v);
		low[u]=min(low[u],low[v]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m; cin>>n>>m;
	adj.resize(n*m);
	vis.resize(n*m);
	low.resize(n*m);
	dfs_num.resize(n*m);

	vb pass(n*m);
	rep(i,n){
		st tmp; cin>>tmp;
		rep(j,m){
			if(tmp[j]=='.') pass[m*i+j]=true;
			else pass[m*i+j]=false;
		}
	}

	rep(i,n){
		rep(j,m){
			if(!pass[m*i+j]) continue;
			if(i!=n-1 && j!=m-1){
				if(pass[m*i+j+1]) ae(adj,m*i+j,m*i+j+1);
				if(pass[m*i+m+j]) ae(adj,m*i+j,m*i+m+j);
			}
			else if(i==n-1 && j!=m-1){
				if(pass[m*i+j+1]) ae(adj,m*i+j,m*i+j+1);
			}
			else if(i!=n-1 && j==m-1){
				if(pass[m*i+m+j]) ae(adj,m*i+j,m*i+m+j);
			}
		}
	}

	if(m>1 && n>1){
		dfs(0);
		if(!vis[m*n-1]) cout<<0<<endl;
		else{
			int cnt = 0;
			rep(i,n*m) if(low[i]>=dfs_num[i] && low[i]!=0) cnt++;
			if(cnt==1) cout<<1<<endl;
			else cout<<2<<endl;
		}


	}
	

}