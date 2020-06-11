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

vector<set<int> > vs;

int findmax(int l, int r){
	int ans = -100;
	rep(x,61){
		if(!vs[x].empty() && *(vs[x].lower_bound(l)) <= r){
			ans = x-30;
			//cout<<"findmax found "<<x-30<<" in "<<l<<" to "<<r<<endl;
		} 
	}
	return ans;
}

int main(){
	fastio;

	int n; cin>>n;
	vi a; tkii(a,n);

	vs.clear();
	vs.resize(61);

	rep(i,n) vs[a[i]+30].insert(i);
	
	//cout<<findmax(0,3)<<endl;
	// for(int i = -3; i <= 3; i++){
	// 	cout<<i<<" : ";
	// 	for(int x : vs[30+i]) cout<<x<<" ";
	// 	cout<<endl;
	// }

	ll maxsum = 0;
	ll cursum = 0;
	int i = 0, j = 0;
	int maxi;
	while(j < n){
		
		cursum += a[j];
		maxi = findmax(i,j);
		if(cursum - maxi >= maxsum){
			maxsum = cursum - maxi;
			j++;
		}
		else if(cursum <= 0){
			cursum = 0;
			i = j+1;
			j = j+1;
		}
		else{
			j++;
		}
		cout<<i<<" "<<j<<" "<<cursum-maxi<<" "<<cursum<<endl;
	}

	cout<<maxsum<<endl;


	//cout<<*(vs[30].lower_bound(3))<<endl;

}