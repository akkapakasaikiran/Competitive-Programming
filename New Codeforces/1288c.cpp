#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); }
}
#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}
////////////////////////////////////////

const ll mod = 1e9+7;
	
vvi ncr;
ll ncrf(int n, int r){
	if(n == r || r == 0) return 1;
	else if(n < r) return 0;
	else if(ncr[n][r] == 0) ncr[n][r] = (ncrf(n-1,r) + ncrf(n-1,r-1))%mod;
	return ncr[n][r];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m; cin>>n>>m;
	ncr.resize(n+2*m);
	rep(i,n+2*m) ncr[i].resize(n);

	ll ans = ncrf(n+2*m-1,n-1);
	cout<<ans<<endl;

}