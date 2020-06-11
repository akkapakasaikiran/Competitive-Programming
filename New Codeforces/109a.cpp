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

int main(){
	fastio;

	int n; cin>>n;

	vi numsevens; numsevens.resize(n+1);

	rep1(i,3) numsevens[i] = -1;
	numsevens[4] = 0;
	for(int i = 5; i <= 7; i++) numsevens[i] = -1;
	numsevens[7] = 1;
	for(int i = 8; i<= n; i++){
		if(numsevens[i-7] != -1) numsevens[i] = numsevens[i-7] + 1;
		else if(numsevens[i-4] != -1) numsevens[i] = numsevens[i-4];
		else numsevens[i] = -1;
	}

	//prvi(numsevens);

	if(numsevens[n] == -1) cout<<-1<<endl;
	else{
		int ns = numsevens[n];
		int nf = (n - 7*ns)/4;
		rep(i,nf) cout<<4;
		rep(i,ns) cout<<7;
		cout<<endl;
	}
}