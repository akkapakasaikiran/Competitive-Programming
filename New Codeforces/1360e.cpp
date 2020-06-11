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


int ctoi(char c){
	int ret = c - 48;
	return ret;
}


int main(){
	fastio;

	test(t){
		int n; cin>>n;
		vvi a; a.resize(n);

		string s;
		rep(i,n){
			cin>>s; 
			rep(j,n) a[i].pb(ctoi(s[j]));
		}
		//prg(a);
		bool yay = true;		

		rep(i,n-1) rep(j,n-1) if(a[i][j] == 1){
			if(i == n-1 || j == n-1) continue;
			else if(a[i+1][j] == 1 || a[i][j+1] == 1) continue;
			else yay = false;
		}

		if(yay) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}