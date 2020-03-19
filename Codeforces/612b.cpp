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

char bachahua(char a, char b){
	if(a=='S' && b=='E' || a=='E' && b=='S') return 'T';
	else if(a=='S' && b=='T' || a=='T' && b=='S') return 'E';
	else return 'S';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,k; cin>>n>>k;
	set<st> cards;
	st tmp;
	rep(i,n){ cin>>tmp; cards.insert(tmp); }

	int cnt = 0;
	for(st x : cards){
		for(st y : cards){
			if(x!=y){
				st z=x;
				rep(i,k){
					if(x[i]==y[i]) z[i]=x[i];
					else z[i]=bachahua(x[i],y[i]);
				}
				if(cards.find(z)!=cards.end()) cnt++;
			}
		}
	}
	cout<<cnt/6<<endl;
}