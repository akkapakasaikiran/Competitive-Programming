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

	test(t){
		int n,k; cin>>n>>k;
		vector<set<int> > vs;
		vs.resize(k);

		int sz,tmp;
		rep(i,k){
			cin>>sz;
			rep(j,sz){
				cin>>tmp;
				vs[i].insert(tmp);
			}
		}

		// queries
		int mainmax;
		cout<<"? "<<n<<" ";
		rep(i,n) cout<<i+1<<" ";
		cout<<endl; cout.flush();
		cin>>mainmax;


		sz = n;
		int l = 1, r = n/2;
		int maxi;
		while(r != l){
			if(r-l+1 == 0) break;
			cout<<"? "<<r-l+1<<" ";
			rep(i,r-l+1) cout<<l+i<<" ";
			cout<<endl;cout.flush();
			cin>>maxi;
			if(maxi == -1) return 100;
			if(maxi == mainmax){
				sz = sz/2;
				r = (l+r)/2;
			}
			else{
				sz -= sz/2;
				l = r + 1;
				r = r + sz/2;			
			}
			//cout<<l<<" "<<r<<endl;
		}

		cout<<"? 1 "<<l<<endl; cout.flush();
		cin>>maxi;
		if(maxi != mainmax){
			l++;
			if(sz == 3){
				cout<<"? 1 "<<l<<endl; cout.flush();
				cin>>maxi;
				if(maxi != mainmax) l++;
			}
		}

		int pos = -1;
		rep(i,k){
			if(vs[i].find(l) != vs[i].end()){
				pos = i;
			}
		} 

		if(pos == -1){
			cout<<"! ";
			rep(i,k) cout<<mainmax<<" ";
			cout<<endl; cout.flush();
		}
		else{
			int almostmax;
			if(n-vs[pos].size() != 0){
				cout<<"? "<<n-vs[pos].size()<<" ";
				rep(i,n) if(vs[pos].find(i+1) == vs[pos].end()) cout<<i+1<<" ";
				cout<<endl; cout.flush();
				cin>>almostmax;
			}
			

			cout<<"! ";
			rep(i,k){
				if(i != pos) cout<<mainmax<<" ";
				else cout<<almostmax<<" ";
			}
			cout<<endl; cout.flush();	
		}
		
		string s; cin>>s;

	}
}