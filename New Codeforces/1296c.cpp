#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	test(T){
		int n; cin>>n;

		map<pair<int,int>,set<int> > m;

		int u = 0, r = 0;
		set<int> tp; tp.insert(-1);
		m[make_pair(0,0)] = tp;

		string s; cin>>s;
		rep(i,n){
			if(s[i] == 'U') u++;
			else if(s[i] == 'D') u--;
			else if(s[i] == 'R') r++;
			else r--;
			if(m.find(make_pair(r,u)) != m.end()) m[make_pair(r,u)].insert(i);
			else{
				set<int> tmp; tmp.insert(i);
				m[make_pair(r,u)] = tmp; 
			}
		}

		int l = -2,rr = n+1;
		int curl,curr;
		for(map<pair<int,int>,set<int> >::iterator it = m.begin(); it != m.end();it++){
			for(set<int>::iterator si = it->second.begin(); si != --(it->second.end()); si++){
				curl = *si; si++;
				curr = *si; si--;
				if(curr - curl < rr-l){
					rr = curr; l = curl;
				}
			}
		}

		if(l == -2) cout<<-1<<endl;
		else cout<<l+2<<" "<<rr+1<<endl;
	}
}