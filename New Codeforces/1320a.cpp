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
	vi b; tkii(b,n);

	vi a; 
	rep(i,n) a.pb(b[i]-i);

	map<int,vi> cnt;

	rep(i,n){
		if(cnt.find(a[i]) == cnt.end()){
			vi tmp; tmp.pb(i);
			cnt[a[i]] = tmp;
		}
		else cnt[a[i]].pb(i);
	}

	ll maxsum = 0, cursum = 0;
	for(map<int,vi>::iterator mit = cnt.begin(); mit != cnt.end(); mit++){
		cursum = 0;
		for(int i : mit->second) cursum += b[i];
		maxsum = max(maxsum,cursum);
	}

	cout<<maxsum<<endl;
}