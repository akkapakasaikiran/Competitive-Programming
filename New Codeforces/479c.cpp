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

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

// struct comp {
// 	bool operator() (const pii &p1, const pii &p2) const {
// 		if(p1.fi == p2.fi) return p2.se ;
// 	}
// };

int main(){
	fastio;

	int n; cin>>n;
	vi a,b;
	a.resize(n);
	b.resize(n);

	rep(i,n) cin>>a[i]>>b[i];
	
	multiset<pair<int,int>> ms;
	rep(i,n) ms.insert(mp(a[i],b[i]));

	int prev = 0;
	for(pii p: ms){
		if(p.se >= prev) prev = p.se;
		else prev = p.fi;
	}
	cout<<prev<<endl;
}