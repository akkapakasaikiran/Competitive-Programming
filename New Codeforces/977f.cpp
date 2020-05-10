#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define si set<int>
#define pb push_back

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); }
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

void rsort(vector<int> &v){
	sort(v.begin(),v.end(),greater<int>());
}

////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vi a; tkii(a,n);

	map<int,int> dp; 

	int ans = 0;
	rep(i,n){
		dp[a[i]] = dp[a[i]-1] + 1;
		ans = max(ans,dp[a[i]]);
	}

	vi indices;
	bool found = false;
	int last;
	for(int i = n-1; i >=0 ; i--){
		if((dp[a[i]] == ans && !found) || a[i] == last - 1){
			found = true;
			last = a[i];
			indices.pb(i+1);
		}
	}

	cout<<ans<<endl;
	int sz = indices.size();
	rep(i,sz) cout<<indices[sz-i-1]<<" ";
	cout<<endl;

}