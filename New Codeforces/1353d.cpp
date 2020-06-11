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

struct cmp {
	bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) const {
		if((p1.second - p1.first) == (p2.second - p2.first)) return p1.first < p2.first;
		else return p1.second - p1.first > p2.second - p2.first;
	}
};

int main(){
	fastio;

	test(t){
		set<pair<int,int>,cmp> s;
		int n; cin>>n;
		s.insert(make_pair(1,n));
		vi a; a.resize(n+1);

		rep1(i,n){
			pair<int,int> cur = *s.begin();
			int l = cur.first; int r = cur.second;
			if((r-l+1)%2 == 1){
				a[(l+r)/2] = i;
				//cout<<i<<" "<<(l+r)/2<<endl;
				s.erase(s.begin());
				s.insert(make_pair(l,(l+r)/2-1));
				s.insert(make_pair((l+r)/2+1,r));
			}
			else {
				a[(l+r-1)/2] = i;
				//cout<<i<<" "<<(l+r-1)/2<<endl;
				s.erase(s.begin());
				s.insert(make_pair(l,(l+r-1)/2-1));
				s.insert(make_pair((l+r-1)/2+1,r));
			}
		}

		rep1(i,n) cout<<a[i]<<" ";
		cout<<endl;
	}
}