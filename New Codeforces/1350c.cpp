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

vi primes;

map<int,int> primefactorise(int n){
	map<int,int> ret; 
	int i = 0;
	while(n != 1){
		if(n%primes[i] == 0){
			if(ret.find(i) != ret.end()) ret[i]++;
			else ret[i] = 1;
			n /= primes[i];
		}
		else i++;
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	for(int i = 2; i <= 2e5; i++){
		bool div = false;
		for(int j = 2; j <= sqrt(i); j++){
			if(i%j == 0) div = true;
		}
		if(!div) primes.pb(i);
	}	

	vi min1; rep(i,primes.size()) min1.pb(100);
	vi min2; rep(i,primes.size()) min2.pb(100);


	int n; cin>>n;
	vi a; tkii(a,n);

	vi zero;
	rep(i,primes.size()) zero.pb(n);

	map<int,int> m;
	int pi,v;
	rep(i,n){
		m = primefactorise(a[i]);
		for(map<int,int>::iterator it = m.begin();it != m.end(); it++){
			pi = it->first; v = it->second;
			zero[pi]--;
			if(v < min1[pi]){
				min2[pi] = min1[pi];
				min1[pi] = v;
			}
			else if(v < min2[pi]) min2[pi] = v;
		}
	}

	ll ans = 1;
	int cnt;
	rep(i,primes.size()){
		if(zero[i] == 1) cnt = min1[i]; 
		else if(zero[i] == 0) cnt = min2[i]; 
		else cnt = 0;
		rep(j,cnt) ans *= primes[i];
	}
	cout<<ans<<endl;

}