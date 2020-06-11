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

ll btod(string s){
	int n = s.size();
	ll powof2 = 1;
	ll ans = 0;
	rep(i,n){
		if(s[n-i-1] == '1') ans += powof2;
		powof2 *= 2;
	}
	
	return ans;
}

string dtob(ll num, int m){
	string ans;

	while(ans.size() != m){
		if(num % 2 == 1) ans.pb('1');
		else ans.pb('0');
		num /= 2;
	}		
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	fastio;

	test(t){
		int n,m; cin>>n>>m;
		ll median = pow(2,m-1)-1;

		string s;
		ll num;
		rep(i,n){
			//cout<<dtob(median,m)<<endl;

			cin>>s;
			num = btod(s);
			if(i%2 == 0){
				if(num <= median) median++;
			}
			else{
				if(num >= median) median--;
			}
			
		}

		//cout<<dtob(11,4)<<endl;

		cout<<dtob(median,m)<<endl;	
	}
		

}