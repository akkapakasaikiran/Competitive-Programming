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

int newrem(int oldrem, int div, int dig){
	return (oldrem*10 + dig)%div;
}

int ctoi(char c){
	int tmp = c - 48;
	return tmp;
}

int main(){
	fastio;

	string s; cin>>s;
	int n = s.size();
	int a,b; cin>>a>>b;

	vi prerem; prerem.resize(n);
	prerem[0] = ctoi(s[0])%a;
	rep1(i,n-1){
		prerem[i] = (prerem[i-1]*10 + ctoi(s[i]))%a;
	}

	int tenrem; tenrem = 1;
	vi sufrem; sufrem.resize(n);
	sufrem[0] = ctoi(s[n-1])%b;
	rep1(i,n-1){
		tenrem = (tenrem*10)%b;
		sufrem[i] = (ctoi(s[n-i-1])*tenrem + sufrem[i-1])%b;
	}

	int pos = -1;
	rep(i,n-1) if(prerem[i] == 0 && sufrem[n-2-i] == 0 && ctoi(s[i+1]) != 0) pos = i;

	if(pos == -1) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<s.substr(0,pos+1)<<endl;
		cout<<s.substr(pos+1,n-pos-1)<<endl;
	}
	



}