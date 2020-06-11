#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	test(t){
		int a,b,c; cin>>a>>b>>c;
		int n = a+b+c+1;
		vi ans;
		if(a >= b && a >= c){
			ans.pb(0); ans.pb(0); a--;
		}
		else if(b >= c && b >= a){
			ans.pb(0); ans.pb(1); b--;
		}
		else{
			ans.pb(1); ans.pb(1); c--;
		}
		rep(i,n-2){
			if(ans.back() == 1){
				if( c >= b){ ans.pb(1); c--; }
				else{ ans.pb(0); b--; }
			}
			else{
				if(b > a){ ans.pb(1); b-- ; }
				else{ ans.pb(0); a--; }
			}
		}
		//cout<<a<<b<<c<<endl;
		rep(i,n) cout<<ans[i];
		cout<<endl;
	}
}