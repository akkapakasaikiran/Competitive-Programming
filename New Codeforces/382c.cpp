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
	vi a; tkii(a,n);

	sort(a.begin(),a.end());

	if(n == 1) cout<<-1<<endl;
	else if(n == 2){
		int diff = a[1] - a[0];
		if(diff%2 == 0){
			cout<<3<<endl;
			cout<<a[0]-diff<<" "<<a[1]+diff<<" "<<a[0]+diff/2<<endl;
		}
		else{
			cout<<2<<endl;
			cout<<a[0]-diff<<" "<<a[1]+diff<<endl;
		}
	}
	else{
		set<int> diffs;
		rep1(i,n-1) diff.insert(a[i]-a[i-1]);
		if(diff.size() == 1){
			cout<<2<<endl;
			cout<<a[0]-*diff.begin()<<" "<<a[n-1]+*diff.begin()<<endl;
		}
		else if(diff.size() == 2){
			set<int>::iterator it = diff.begin();
			int diff1 = *it; it++; int diff2 = *it;
			if(diff2 = 2*diff1){
				vi nums;
				rep1(i,n-1) if(a[i]-a[i-1] == diff2)
			}
		}
	}

	


}