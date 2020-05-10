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

	set<ll> hs;
	ll num = 2;
	rep1(n,3*1e4){
		hs.insert(num);
		num += 3*(n+1) - 1;
	}
	//for(ll x : hs) cout<<x<<" "<<endl;

	test(t){
		ll n; cin>>n;
		int cnt = 0;
		while(n >= 2){
			cnt++;
			ll h = *(--hs.upper_bound(n));
			//cout<<h<<endl;
			n -= h;
		}
		cout<<cnt<<endl;
	}
}