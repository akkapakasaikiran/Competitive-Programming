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

	int n; cin>>n;
	vector<ll> a; tki<ll>(a,n);

	ll gcd;
	if(n == 1) gcd = a[0];
	else{
		gcd = __gcd(a[0],a[1]);
		rep1(i,n-2) gcd = __gcd(gcd,a[i+1]);
	}

	int cnt = 0;
	int sq = sqrt(gcd);

	if(sq*1ll*sq == gcd){
		cnt++;
		rep1(i,sqrt(gcd)-1) if(gcd%i == 0) cnt+=2;
	}
	else{
		rep1(i,sqrt(gcd)) if(gcd%i == 0) cnt+=2;	
	}
	
	cout<<cnt<<endl;

}