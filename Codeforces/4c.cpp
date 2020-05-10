#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vii vector<int>::iterator
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define fi first
#define se second

#define rep(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define forv(v) for(auto x : v)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string,int> s;
	int n; cin>>n;
	vector<string> vs;
	tki<string>(vs,n);
	rep(i,n){
		if(s.find(vs[i])==s.end()){
			s[vs[i]] = 0;
			cout<<"OK"<<endl;
		}
		else{
			s[vs[i]]++;
			vs[i].append(to_string(s[vs[i]]));
			cout<<vs[i]<<endl;
		}
	}
}