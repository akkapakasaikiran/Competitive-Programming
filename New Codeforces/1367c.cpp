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
template <typename T> void take_input(vector<T> &a, int size){ T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); } }
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){ for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; } cout<<endl; }
/////////////////////////////////////////

string format(string s, int k){
	string tmp = "1";
	rep(i,k) tmp.pb('0');
	s = tmp + s;
	reverse(all(tmp));
	s = s + tmp;
	return s;
}


int main(){
	fastio;

	test(t){
		int n,k; cin>>n>>k;
		string s; cin>>s;

		vi dist;
		s = format(s,k);

		int prev = 0;
		int ans = 0;
		rep1(i,s.size()-1){
			if(s[i] == '1'){
				ans += (i-prev)/(k+1) - 1;
				prev = i;
			}
		}

		cout<<ans<<endl;
	}
}