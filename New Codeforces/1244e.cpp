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

int main(){
	fastio;

	ll n,k; cin>>n>>k;
	vll a; tki<ll>(a,n);

	map<ll,ll> cnt;
	rep(i,n){
		if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
		else cnt[a[i]]++;
	}

	bool ok = true;
	ll diff = (*(--cnt.end())).first - (*cnt.begin()).first;

	while(cnt.size() > 1 && ok){
		if((*(--cnt.end())).second < (*cnt.begin()).second){
			pair<ll,ll> last = *(--cnt.end());
			pair<ll,ll> secondlast = *(--(--cnt.end()));

			if(last.second*(last.first - secondlast.first) <= k){
				k -= last.second*(last.first - secondlast.first);
				diff -= last.first - secondlast.first;
				cnt.erase(last.first);
				cnt[secondlast.first] += last.second;
			}
			else{
				diff -= k/last.second;
				ok = false;
			}
		}
		else{
			pair<ll,ll> firstt = *cnt.begin();
			pair<ll,ll> secondd = *(++cnt.begin());

			if(firstt.second*(secondd.first - firstt.first) <= k){
				k -= firstt.second*(secondd.first - firstt.first);
				diff -= secondd.first - firstt.first;
				cnt.erase(firstt.first);
				cnt[secondd.first] += firstt.second;
			}
			else{
				diff -= k/firstt.second;
				ok = false;
			}
		}
	}

	cout<<diff<<endl;
}