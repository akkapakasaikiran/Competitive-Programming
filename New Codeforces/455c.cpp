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

const int N = 1e5+7;

int main(){
	fastio;

	vector<ll> freq;
	freq.resize(N);

	ll n; cin>>n;
	vector<ll> a; tki<ll>(a,n);

	rep(i,n) freq[a[i]]++;

	vector<ll> dp; dp.resize(N);

	dp[0] = 0;
	dp[1] = freq[1];

	for(int i = 2; i<N ; i++){
		dp[i] = max(dp[i-1],dp[i-2] + freq[i]*i);
	}

	cout<<dp[N-1]<<endl;

//	puts("123");

	
}