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

bool found(vi f){
	return f[1] != 0 && f[2] != 0 && f[3] != 0;
}

int main(){
	fastio;

	test(t){
		string s; cin>>s;
		int n = s.size();

		int i = -1, j = -1;
		vi f; f.resize(4);

		int tmp;
		int ans = n+1;
		while(i < n){
			i++; tmp = s[i] - 48;
			f[tmp]++;

			if(found(f)){
				while(found(f)){
					j++; tmp = s[j] - 48;
					f[tmp]--;
				}

				ans = min(ans,i-j+1);
			}
		}

		if(ans == n+1) cout<<0<<endl;
		else cout<<ans<<endl; 
	}
}