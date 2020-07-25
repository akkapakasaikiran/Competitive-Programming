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
vb vis;
vi color;


int main(){
	fastio;

	test(t){
		int n,m; cin>>n>>m;
		a.resize(n+1);
		vis.resize(n+1);
		color.resize(n+1);

		int u,v;
		rep(i,m){
			cin>>u>>v;
			ae(a,u,v);
			ae(a,v,u);
		}

		queue<int> q;
		vis[1] = true; q.push(1);
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int y : a[x]) if(!vis[y]){
				vis[y] = true; color[y] = 1 - color[x];
				q.push(y);
			}
		}

		int zeros = 0;
		rep1(i,n) if(color[i] == 0) zeros++;
		if(zeros <= n/2){
			cout<<zeros<<endl;
			rep1(i,n) if(color[i] == 0) cout<<i<<" ";
			cout<<endl;
		}
		else{
			cout<<n-zeros<<endl;
			rep1(i,n) if(color[i] != 0) cout<<i<<" ";
			cout<<endl;
		}

	}
	
}