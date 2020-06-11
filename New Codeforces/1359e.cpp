#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int MOD = 998244353;
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

vi fact;

int modmul(int a, int b){
	return (a*1ll*b)%MOD;
}

int binmodexp(int a, int b){
	if(b == 0) return 1;
	else if(b%2==0) return binmodexp(modmul(a,a),b/2);
	else return modmul(a,binmodexp(modmul(a,a),b/2));
}

int inv(int a){
	return binmodexp(a,MOD-2);
}

int moddiv(int a, int b){
	return modmul(a,inv(b));
}

int ncr(int n, int r){
	return moddiv(fact[n],modmul(fact[n-r],fact[r]));
}

int main(){
	fastio;

	int n,k; cin>>n>>k;

	rep(i,n+1) fact.pb(1);
	rep1(i,n) fact[i] = modmul(fact[i-1],i);

	ll ans = 0;
	
	int mini = 1;
	while(n/mini >= k){
		ans = (ans + ncr(n/mini-1,k-1))%MOD;
		mini++;
	}

	cout<<ans<<endl;

	
}