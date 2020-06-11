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

	test(t){
		int n,m,x,y; cin>>n>>m>>x>>y;

		vector<string> a;

		string s;
		rep(i,n){
			cin>>s;
			a.pb(s);
		}

		int cnt = 0;
		rep(i,n) for(char c : a[i]) if(c == '.') cnt++;

		if(2*x <= y){
			cout<<cnt*x<<endl;
		}
		else{
			int ans = 0;
			rep(i,n){
				rep(j,m-1){
					if(a[i][j] == '.' && a[i][j+1] == '.'){
						cnt -= 2;
						ans += y;
						j++;
					}
				}
			}
			ans += cnt*x;
			cout<<ans<<endl;	
		}
	}
}