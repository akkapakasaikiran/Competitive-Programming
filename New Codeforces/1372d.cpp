/* Author: Akkapaka Saikiran (@saikidon911) */
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
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////

bool comp(pair<int,list<int>::iterator> p1, pair<int,list<int>::iterator> p2){
	return p1.first < p2.first;
}

int main(){
	fastio;

	int n; cin>>n;
	vi a; tkii(a,n);

	list<int> l; 
	rep(i,n) l.pb(a[i]);

	vector<pair<int,list<int>::iterator> > b;
	for(list<int>::iterator lit = l.begin(); lit != l.end(); lit++) b.pb(make_pair(*lit,lit));
	
	sort(all(b),comp);
	vi bb = a;
	sort(all(b));

	multiset<int> ms;
	rep(i,n) ms.insert(a[i]);

	while(l.size() != 1){
		int mini = *ms.begin();
		list<int>::iterator lit = l.begin();
		//list<int>::iterator lit = b[lower_bound(all(bb), mini)-bb.begin()].second;
		list<int>::iterator ending = l.end(); ending--;
		list<int>::iterator lit1, lit2;
		if(lit == l.begin()){
			lit++; lit1 = lit;
			lit = ending; lit2 = lit;
			lit = l.begin();
		}
		else if(lit == ending){
			lit--; lit1 = lit;
			lit = l.begin(); lit2 = lit;
			lit = ending;
		}
		else{
			lit--; lit1 = lit;
			lit++; lit++; lit2 = lit;
			lit--;	
		}
		*lit = *lit1 + *lit2;
		ms.erase(*lit1); ms.erase(*lit2);
		l.erase(lit1); l.erase(lit2);
	}

	cout<<*l.begin()<<endl;

}