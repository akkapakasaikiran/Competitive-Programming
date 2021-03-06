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

int main(){
	fastio;

	int n; cin>>n;
	vvi grid(n,vi(n));
	string s;
	rep(i,n){
		cin>>s;
		rep(j,n) if(s[j] == '#') grid[i][j] = 1;
	}

	rep1(i,n-2){
		rep1(j,n-2){
			if(grid[i][j] == 0 && grid[i][j+1] == 0 &&
				grid[i][j-1] == 0 && grid[i-1][j] == 0 &&
				grid[i+1][j] == 0){
				grid[i][j] = 1; grid[i][j-1] = 1;
				grid[i][j+1] = 1; grid[i-1][j] = 1;
				grid[i+1][j] = 1;
			}
		}
	}

	if(grid == vvi(n,vi(n,1))) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}