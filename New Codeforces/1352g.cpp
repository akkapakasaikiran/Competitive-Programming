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

	test(t){
		int n; cin>>n;
		if(n <= 3) cout<<-1<<endl;
		else if(n == 4){
			cout<<"3 1 4 2"<<endl;
		}
		else if(n%2==1){
			rep1(i,n) if(i%2 == 1) cout<<i<<" ";
			cout<<n-3<<" "<<n-1<<" ";
			for(int i = n-5; i >= 2 ;i -= 2) cout<<i<<" ";
			cout<<endl;
		}
		else{
			rep1(i,n) if(i%2 == 1) cout<<i<<" ";
			cout<<n-4<<" "<<n<<" "<<n-2<<" ";
			for(int i = n-6; i >= 2 ;i -= 2) cout<<i<<" ";
			cout<<endl;
		}
	}
}