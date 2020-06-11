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
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input 
#define tkii take_input<int>
template <typename T> void take_input(vector<T> &a, int size){ T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); } }
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){ for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; } cout<<endl; }
/////////////////////////////////////////

int main(){
	fastio;

	test(t){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		cout<<s.size()<<endl;

		vi zeros;
		rep(j,n) if(s[j] == '0') zeros.pb(j);

		int z = zeros.size();

		rep(i,z){
			if(k >= (zeros[i] - i)){
				int diff = zeros[i] - i;
				zeros[i] -= diff;
				k -= diff;
			}
			else{
				zeros[i] -= k;
				k -= k;
			}
		}

		string ans;
		rep(j,n) ans.pb('1');
		rep(j,z) ans[zeros[j]] = '0';

		//cout<<ans<<endl;


	}
}