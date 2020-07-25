/* Author: Akkapaka Saikiran (@saikidon911) */
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
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////

bool isprime(int n){
	bool prime = true;
	for(int i = 2; i <= sqrt(n); i++) if(n%i == 0) prime = false;
	return prime;
}

int main(){
	fastio;

	int n; cin>>n;

	if(isprime(n)){
		cout<<n<<endl;
		rep1(i,n) cout<<i<<" "<<i%n+1<<endl;
	}
	else{
		int p;
		rep1(i,n/2) if(isprime(n+i)) p = n+i;
		cout<<p<<endl;
		rep1(i,n) cout<<i<<" "<<i%n+1<<endl;		
		rep1(i,p-n) cout<<i<<" "<<i+n/2<<endl;
	}



}