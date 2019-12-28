#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
//template <typename T>
#define vit(T) vector<T>::iterator
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

#define rep(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	int tmp;
	for(int i=0;i<size;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d,s; cin>>d>>s;
	vi mi,ma;
	int tmp;
	rep(i,d){
		cin>>tmp; mi.pb(tmp); s-=tmp;
		cin>>tmp; ma.pb(tmp);
	}
	if(s<0) cout<<"NO"<<endl;
	else if(s==0){
		cout<<"YES"<<endl;
		rep(i,d) cout<<mi[i]<<" ";
		cout<<endl;
	}
	else{
		int i=0;
		for(;i<d;i++){
			s-=ma[i]-mi[i];
			if(s<=0) break;
		}
		if(s>0) cout<<"NO"<<endl;
		else if(s==0){
			cout<<"YES"<<endl;
			rep(j,i+1) cout<<ma[j]<<" ";
			forab(j,i+1,d) cout<<mi[j]<<" ";
			cout<<endl;
		}
		else{
			s+=ma[i]-mi[i];
			cout<<"YES"<<endl;
			rep(j,i) cout<<ma[j]<<" ";
			cout<<s+mi[i]<<" ";
			forab(j,i+1,d) cout<<mi[j]<<" ";
			cout<<endl;			
		}
	}

}