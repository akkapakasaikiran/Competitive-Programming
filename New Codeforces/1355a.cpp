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

pair<int,int> minmax(ll n){
	string s = to_string(n);
	char mini = s[0], maxi = s[0];
	rep(i,s.size()){
		maxi = max(maxi,s[i]);
		mini = min(mini,s[i]);
	}
	return make_pair(mini,maxi);
}

int main(){
	fastio;

	test(t){
		ll a,k; cin>>a>>k;

		pair<int,int> cur = minmax(a);
		int mini = cur.first - 48 ;
		int maxi = cur.second - 48;

		int cnt = 1;
		while(mini != 0 && cnt < k){
			a += mini*maxi;
			cnt++;
			pair<int,int> cur = minmax(a);
			mini = cur.first - 48;
			maxi = cur.second - 48;
			//cout<<a<<mini<<maxi<<endl;
		}

		cout<<a<<endl;
	}
}