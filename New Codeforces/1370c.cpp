#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
using pii = pair<int,int>; 
#define pb push_back
#define all(v) v.begin(),v.end()
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

	string a = "Ashishgup", f = "FastestFinger";

	test(t){
		int n; cin>>n;
		if(n == 1) cout<<f<<endl;
		else if(n == 2) cout<<a<<endl;
		else if(n%2 == 1) cout<<a<<endl;
		else{
			int p  = 0; 
			int numodd = 0;
			for(int i = 2; i <= sqrt(n); i++){
				if(n%i == 0){
					if(i%2 == 1) numodd++;
					if((n/i)%2 == 1) numodd++;
				}
			}
			while(n%2 == 0){
				n /= 2;
				p++;
			}
			//	cout<<p<<" "<<numodd<<endl;

			if(p == 1){
				if(numodd == 1) cout<<f<<endl; 
				else cout<<a<<endl;
			}
			else{ // p > 1 => losing
				if(numodd == 0) cout<<f<<endl;
				else cout<<a<<endl;
			}
		}
	}
}