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
const ll mod = 1e9+7;
/////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool dp[505][505];
	int n,k; cin>>n>>k;
	int a[n],b[n]; 
	ll tot = 0;
	rep1(i,n){
		cin>>a[i]>>b[i];
		tot += a[i]+b[i];
	}

	dp[0][0] = true;
	rep1(i,n){
		rep(j,k){
			dp[i][j] = dp[i-1][(j-a[i]%k+k)%k];
			rep(l,min(k,a[i]+1)) if((a[i]-l)%k + b[i] >= k) dp[i][j] |= dp[i-1][(j-l+k)%k];
		}
	}

	ll ans = 0;
	rep(j,k) if(dp[n][j]) ans = max(ans,(tot-j)/k);
	cout<<ans<<endl;

}
