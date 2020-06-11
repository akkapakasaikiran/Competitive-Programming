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

void swap(vi &a, int i){
	int tmp = a[i];
	a[i] = a[i+1];
	a[i+1] = tmp;
}

int findmin(vi a, int pos){
	int ans = pos;
	for(int i = pos; i < a.size(); i++){
		if(a[i] < a[ans]) ans = i;
	}
	return ans;
}

int main(){
	fastio;

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n);

		int pos = 0;
		int newpos;
		while(pos < n){
			if(pos == findmin(a,pos)) pos++;
			else{
				newpos = findmin(a,pos); 
				for(int i = newpos-1; i >= pos; i--) swap(a,i);
				pos = newpos; 
			}
			//cout<<pos<<" ";
			//prvi(a);
		}
		prvi(a);

	}
}