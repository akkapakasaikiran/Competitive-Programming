/* Author: Akkapaka Saikiran (@saikidon911) */
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define all(v) v.begin(),v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

vector<int> maxdiv;

bool comp(int x, int y){
	return maxdiv[x] < maxdiv[y];
}


int main(){
	fastio;

	int n; cin>>n;
	maxdiv.resize(n+1, 1);
	
	vector<int> nums;
	for(int i = 2; i <= n; i++){
		nums.push_back(i);
		for(int j = 2; j <= sqrt(i); j++) if(i%j == 0){
			maxdiv[i] = i/j;
			break;
		}
	}

	sort(all(nums), comp);
	for(int i : nums) cout<<maxdiv[i]<<" ";
	cout<<endl;

}