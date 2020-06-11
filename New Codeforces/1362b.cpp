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

	// int n1 = 31;
	// int n2 = 1;
	// cout<<(n1^n2)<<endl;

	test(t){
		int n; cin>>n;
		set<int> s1;
		int tmp;
		rep(i,n){
			cin>>tmp; 
			s1.insert(tmp);
		}

		int ans = -1;
		rep1(k,1024){
			set<int> s2;
			for(int x : s1) s2.insert(x^k);
			if(s1 == s2){
				ans = k;
				break;
			}
		}
		
		cout<<ans<<endl;
	}
}