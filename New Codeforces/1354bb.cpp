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

int main(){
	fastio;

	test(t){
		string s; cin>>s;
		int n = s.size();

		vi breaks;
		rep1(i,n-1) if(s[i] != s[i-1]) breaks.pb(i);

		
		if(breaks.size() < 2) cout<<0<<endl;		
		else{
			int ans = n+1;
			rep(i,breaks.size()-1){
				if(s[breaks[i]-1] != s[breaks[i+1]]){
					ans = min(ans,2+breaks[i+1]-breaks[i]);
				}
			}	
			if(ans == n+1) cout<<0<<endl;
			else cout<<ans<<endl;	
		}
		
	}
}