/* Author: Akkapaka Saikiran (@saikidon911) */
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
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////

int main(){
	fastio;

	test(t){
		int n,m; cin>>n>>m;

		vvi grid(n,vi(m));
		int tmp;
		rep(i,n) rep(j,m){
			cin>>tmp;
			grid[i][j] = tmp;
		}

		bool yes = true;
		if(grid[0][0] > 2 || grid[0][m-1] > 2) yes = false;
		else if(grid[n-1][0] > 2 || grid[n-1][m-1] > 2) yes = false;
		rep1(i,n-2) if(grid[i][0] > 3) yes = false;
		rep1(i,n-2) if(grid[i][m-1] > 3) yes = false;
		rep1(j,m-2) if(grid[0][j] > 3) yes = false;
		rep1(j,m-2) if(grid[n-1][j] > 3) yes = false;
		rep1(i,n-2) rep1(j,m-2) if(grid[i][j] > 4) yes = false;

		if(!yes) cout<<"NO"<<endl;
		else{
			grid[0][0] = 2; grid[0][m-1] = 2;
			grid[n-1][0] = 2; grid[n-1][m-1] = 2;
			rep1(i,n-2) grid[i][0] = 3;
			rep1(i,n-2) grid[i][m-1] = 3;
			rep1(j,m-2) grid[0][j] = 3;
			rep1(j,m-2) grid[n-1][j] = 3;
			rep1(i,n-2) rep1(j,m-2) grid[i][j] = 4; 

			cout<<"YES"<<endl;
			rep(i,n) prvi(grid[i]);
		}
	}
}