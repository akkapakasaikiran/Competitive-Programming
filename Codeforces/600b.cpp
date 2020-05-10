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

void prsi(si s){
	for(int x : s) cout<<x<<" ";
	cout<<endl;
}

////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vi a; tkii(a,n);

	int numdays = 0;
	vi daylen;
	int start = -1;
	si went;
	si came;
	rep(i,n){
		if(a[i]>0){
			if(went.find(a[i])==went.end() 
				&& came.find(a[i])==came.end()) came.insert(a[i]);
			else{ cout<<-1<<endl; return 0; }
		}
		else{
			if(came.find(-a[i])!=came.end()){
				came.erase(came.find(-a[i]));
				went.insert(-a[i]);
			}
			else{ cout<<-1<<endl; return 0; }  
		}
		if(came.size()==0){
			numdays++;
			went.clear();
			daylen.pb(i-start);
			start = i;
		}
	}
	if(came.size()!=0) cout<<-1<<endl;
	else{
		cout<<numdays<<endl;
		rep(i,daylen.size()) cout<<daylen[i]<<" ";
		cout<<endl;
	}
}