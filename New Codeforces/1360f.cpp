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

int numdiff(string s1, string s2){
	int ret = 0;
	rep(i,s1.size()) if(s1[i] != s2[i]) ret++;
	return ret;
}



int main(){
	fastio;

	test(t){
		int n,m; cin>>n>>m;
		
		vector<string> vs;

		string s;
		rep(i,n){
			cin>>s;
			vs.pb(s);
		}

		set<string> ss;
		ss.insert(vs[0]);
		
		rep(i,m){
			rep1(j,n-1){
				s = vs[0];
				s[i]=vs[j][i];
				ss.insert(s);
			}
		}

		string ans = "-1";
		for(string x : ss){
			bool ok = true;
			rep(i,n) if(numdiff(x,vs[i]) > 1) ok = false;
			if(ok) ans = x;
		}

		cout<<ans<<endl;


	}
}