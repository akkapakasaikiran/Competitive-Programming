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

const int alphabet_size = 26;

vvi a;
vb vis;

int ctoi(char c){
	return c - 'a';
}

void dfs(int u){
	vis[u] = true;
	for(int v : a[u]) if(!vis[v]) dfs(v);
}

int main(){
	fastio;

	int n; cin>>n;
	a.resize(n+alphabet_size);
	vis.resize(n+alphabet_size);

	string s;
	rep(i,n){
		cin>>s;
		set<char> cs;
		rep(j,s.size()) cs.insert(s[j]);
		for(char c : cs){
			ae(a,ctoi(c)+n,i);
			ae(a,i,ctoi(c)+n);
		}
	}

	int cnt = 0;
	rep(i,n){
		if(!vis[i]){
			cnt++;
			dfs(i);
		}
	}

	cout<<cnt<<endl;

	
}