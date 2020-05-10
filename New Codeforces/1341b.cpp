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

	test(t){
		int n,k; cin>>n>>k;
		vi a; tkii(a,n);
		vb peak; peak.resize(n);
		rep1(i,n-2) peak[i] = (a[i] > a[i-1] && a[i] > a[i+1]);
		//prv<bool>(peak);

		int cn = 0;
		rep(i,k) if(peak[i]) cn++;

		vi cnt; cnt.resize(n-k+1);
		cnt[0] = cn;
		
		int cur = cn;
		int l = 0;
		if(peak[0]) cur--;
		if(peak[k-1]) cur--;
		int t = cur;

		rep1(i,n-k){
			cnt[i] = cnt[i-1];
			if(peak[i-1]) cnt[i]--;
			if(peak[i+k-1]) cnt[i]++;
			cur = cnt[i];

			if(peak[i]) cur--;
			if(peak[i+k-1]) cur--;

			if(cur > t){t = cur; l = i; }
		}
		cout<<t+1<<" "<<l+1<<endl;

	}
}