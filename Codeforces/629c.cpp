#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<algorithm>
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
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp;
	for(int i=0;i<size;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

int vmax(vi v){ //positivity assumed
	int ans = 0;
	rep(i,v.size()) ans=max(ans,v[i]);
	return ans;
}

////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int n; cin>>n;
		st x; cin>>x;
		st a = "1"; st b = "1";
		rep1(i,n-1){
			if(a==b){
				if(x[i]=='1'){ a.pb('1'); b.pb('0'); }
				else if(x[i]=='0') { a.pb('0'); b.pb('0'); }
				else{ a.pb('1'); b.pb('1'); }
			}
			else if(a>b){
				if(x[i]=='0'){ a.pb('0'); b.pb('0'); }
				else if(x[i]=='1'){ a.pb('0'); b.pb('1'); }
				else{ a.pb('0'); b.pb('2'); }
			}
			else{
				if(x[i]=='0'){ a.pb('0'); b.pb('0'); }
				else if(x[i]=='1'){ a.pb('1'); b.pb('0'); }
				else{ a.pb('2'); b.pb('1'); }
			}
		}
		cout<<a<<endl<<b<<endl;
	}
}