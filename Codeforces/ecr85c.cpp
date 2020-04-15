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
		int n; cin>>n;
		v<ll> a,b; ll x,y;
		rep(i,n){
			cin>>x>>y;
			a.pb(x); b.pb(y);
		}

		rep(i,n){
			if(i!=n-1) b[i]=min(b[i],a[i+1]);
			else b[i]=min(b[i],a[0]);
		}

		int last = -1;
		ll minn = 1e13;
		rep(i,n) if(b[i] < minn){ minn = b[i]; last = i; }

		a.insert(a.end(),a.begin(),a.end());
		b.insert(b.end(),b.begin(),b.end());

		ll bul = a[last+1];
		for(int i=(last+2);i<=last+n;i++) bul+=a[i]-b[i-1];
		cout<<bul<<endl;
	}
}