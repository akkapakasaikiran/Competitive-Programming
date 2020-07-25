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
template <typename T> void take_input(vector<T> &a, int size){ T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); } }
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){ for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; } cout<<endl; }
/////////////////////////////////////////

ll maxinc(vll v){
	int n = v.size();
	ll ret = 0;
	ll minsofar = v[0];
	rep(i,n){
		minsofar = min(v[i],minsofar);
		ret = max(v[i] - minsofar, ret);
	}
	return ret;
}


int main(){
	fastio;

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n);

		ll evensum = 0;
		rep(i,n) if(i%2 == 0) evensum += a[i];

		vll diff(n+1);
		rep(i,n){
			if(i%2 == 0) diff[i+1] = diff[i] - a[i];
			else diff[i+1] = diff[i] + a[i];
		}

		vll e,o;
		rep(i,n+1){
			if(i%2 == 0) e.pb(diff[i]);
			else o.pb(diff[i]);
		}

		// prv<ll>(diff);

		// cout<<evensum<<endl;
		// cout<<maxinc(e)<<endl;
		// cout<<maxinc(o)<<endl;

		cout<<evensum + max(maxinc(e), maxinc(o))<<endl; 

	}
}