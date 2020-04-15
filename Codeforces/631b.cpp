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

int vmax(vi v){ // assumed non negative elements 
	int ans = -1;
	rep(i,v.size()) ans=max(ans,v[i]);
	return ans;
}

////////////////////////////////////////

bool isperm(vii s, vii e){
	int l = e - s;
	vb seen; seen.resize(l);
	for(vii i = s;i!=e;i++){
		if(*i>l) return false;
		else seen[(*i)-1] = true;
	}
	rep(i,l) if(!seen[i]) return false;
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n);
		int maxi = vmax(a); 
		
		if(maxi >= n){
			cout<<0<<endl;
			continue;
		}

		bool one = isperm(a.begin(),a.begin()+maxi) && isperm(a.begin()+maxi,a.end());

		bool two = isperm(a.begin(),a.begin()+n-maxi) && isperm(a.begin()+n-maxi,a.end());

		if(one && two && maxi == n/2){
			cout<<1<<endl;
			cout<<maxi<<" "<<n-maxi<<endl;
		}
		else if(one && two){
			cout<<2<<endl;
			cout<<maxi<<" "<<n-maxi<<endl;
			cout<<n-maxi<<" "<<maxi<<endl;
		}
		else if(one){
			cout<<1<<endl;
			cout<<maxi<<" "<<n-maxi<<endl;
		}
		else if(two){
			cout<<1<<endl;
			cout<<n-maxi<<" "<<maxi<<endl;			
		}
		else cout<<0<<endl;
	}
}