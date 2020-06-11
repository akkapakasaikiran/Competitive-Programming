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
	vvi cubes(n);
	rep(i,n) tkii(cubes[i],6);

	set<int> nums;
	if(n == 1) for(int x : cubes[0]) nums.insert(x);
	else if(n == 2){
		for(int x : cubes[0]) for(int y : cubes[1]){
			nums.insert(10*x+y);
			nums.insert(10*y+x);
		}
	}
	else{
		for(int x : cubes[0]) for(int y : cubes[1]) for(int z : cubes[2]){
			nums.insert(100*x+10*y+z);
			nums.insert(100*x+10*z+y);
			nums.insert(100*y+10*x+z);
			nums.insert(100*y+10*z+x);
			nums.insert(100*z+10*y+x);
			nums.insert(100*z+10*x+y);
		}
	}

	for(int x : nums) cout<<x<<" ";
	cout<<endl;

	int ans = -1;
	rep1(i,1000) if(nums.find(i) == nums.end() && ans == -1) ans = i;	

	cout<<ans<<endl;
}