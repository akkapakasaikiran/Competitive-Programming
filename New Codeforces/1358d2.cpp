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

ll summ(int inp){
	ll tmp = inp;
	return (tmp*(tmp+1))/2;
}

int main(){
	fastio;

	test(t){
		int n,x; cin>>n>>x;
		vi a; tkii(a,n);
		a.insert(a.begin(),a.begin(),a.end());

		int sd = 0, ed = 0, shift = 0;
		ll maxsum = 0, cursum = 0;

		vector<ll> days;
		days.pb( (ll) a[0] );
		vector<ll> sums;
		sums.pb(summ(a[0]));
		rep1(i,2*n-1){
			days.pb(days[i-1]+a[i]);
			sums.pb(sums[i-1]+summ(a[i]));
		} 

	}
}