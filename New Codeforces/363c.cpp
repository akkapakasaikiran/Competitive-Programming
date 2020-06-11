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

string s, ans;

bool triplet(int i){
	return i <= s.size()-3 && s[i] == s[i+1] && s[i+1] == s[i+2];
}

bool twopairs(int i){
	return i <= s.size()-2 && ans.size() >= 2 && ans[ans.size()-1] == ans[ans.size()-2] && s[i] == s[i+1];
}

int main(){
	fastio;

	cin>>s;
	int n = s.size();
	

	rep(i,n) if(!triplet(i) && !twopairs(i)) ans.pb(s[i]);
	
	cout<<ans<<endl;
}