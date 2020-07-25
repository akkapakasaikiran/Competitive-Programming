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

	ll k; cin>>k;

	vector<vll> arr(10);
	rep(i,100000) arr[0].pb(i+1);
	rep(i,100000){
		rep1(j,9){
			if(arr[j-1][i] == -1) arr[j].pb(-1);
			else if(arr[j-1][i] < llmax/((i+j+1))/(j+1)){
				arr[j].pb(arr[j-1][i]*1ll*(j+i+1)/(j+1));
			}
			else arr[j].pb(-1);	
		}
	}

	int mini = intmax;
	int ibest, jbest;
	if(k < 10){
		rep(i,10){
			int j = 0;
			while(arr[i][j] < k) j++;
			if((i+1)*j < mini){
				jbest = j; ibest = i;
				mini = (i+1)*j;
			}
		}
	}
	else if(k < 100){
		rep1(i,9){
			int j = 0;
			while(arr[i][j] < k) j++;
			if((i+1)*j < mini){
				jbest = j; ibest = i;
				mini = (i+1)*j;
			}
		}
	}
	else if( k < 500){
		for(int i = 2; i < 10; i++){
			int j = 0;
			while(arr[i][j] < k) j++;
			if((i+1)*j < mini){
				jbest = j; ibest = i;
				mini = (i+1)*j;
			}
		}
	}
	else{
		for(int i = 2; i < 10; i++){
			int j = 0;
			while(arr[i][j] < k) j++;
			if((i+1)*j < mini){
				jbest = j; ibest = i;
				mini = (i+1)*j;
			}
		}
	}

	//rep(i,10) prv<ll>(arr[i]);
	//cout<<ibest<<' '<<jbest<<endl;

	string c = "codeforces";
	cout<<c.substr(0,10-ibest-1);
	rep(i,jbest+1) cout<<c.substr(10-ibest-1,ibest+1);
	cout<<endl;

}