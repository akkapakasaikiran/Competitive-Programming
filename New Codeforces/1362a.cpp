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
		ll a,b; cin>>a>>b;
		if(a == b) cout<<0<<endl;
		else{
			if(a < b){
				ll tmp = b; b = a; a = tmp;
			}

			if(a%b != 0) cout<<-1<<endl;
			else{
				ll div = a/b;
				int p = 0;
				while(div%2 == 0){
					div /= 2;
					p++;
				}
				if(div != 1) cout<<-1<<endl;
				else{
					//cout<<"p is "<<p<<" ";
					int ans = 0;
					ans += p/3; p = p%3;
					ans += p/2; p = p%2;
					ans += p; 
					cout<<ans<<endl;
				}
			}
		}
	}
}