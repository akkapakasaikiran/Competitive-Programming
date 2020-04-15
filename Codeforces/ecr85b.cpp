#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define si set<int>
#define pb push_back

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		ll n,x; cin>>n>>x;
		vll a; tki<ll>(a,n);
		sort(a.begin(),a.end(),greater<ll>());

		vll prefixsum; prefixsum.pb(a[0]);
		rep1(i,n-1) prefixsum.pb(a[i] + prefixsum[i-1]);

		ll ans = 0;
		for(ll i = n-1; i>=0; i--){
			if(prefixsum[i] >= (i+1)*x ){
				ans = i+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
}