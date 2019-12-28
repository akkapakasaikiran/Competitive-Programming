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
#define vii vector<int>::iterator
#define pb push_back
#define all(v) v.begin(),v.end()

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define forv(v) for(auto x : v)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

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


void swapv(vi &a, vi &b){
	vi tmp = a;
	a = b;
	b = tmp;
}

void swap(int &x, int &y){
	int tmp = x; x = y; y= tmp;
}

////////////////////////////////////////

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}
#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

/////////////////////////////////////////

void invert(vi &a){
	rep(i,a.size()){
		if(a[i]==1) a[i]=2;
		else a[i]=1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n); tkii(a,n);

		vi prer,preb;
		rep(i,2*n){
			if(i==0){
				if(a[0]==1){
					prer.pb(1); preb.pb(0);
				}
				else{
					prer.pb(0); preb.pb(1);
				}
			}
			else{
				if(a[i]==1){
					prer.pb(prer[i-1]+1);
					preb.pb(preb[i-1]);
				}
				else{
					preb.pb(preb[i-1]+1);
					prer.pb(prer[i-1]);
				}
			}
		}
		
		int i = n-1, j = n;
		int r = prer[2*n-1];
		int b = 2*n-r;

		if(r==b) cout<<0<<endl;
		else{
			if(r<b){
				swapv(prer,preb);
				swap(r,b);
				invert(a);
			}
			int diff = r-b;

			while(diff!=0){
				//cout<<i<<" "<<j<<" "<<diff<<endl;
				if(i>=0 && j<=2*n-1){
					if(a[i]==1){
						i--; diff--;
					}
					else if (a[j]==1){
						j++; diff--;
					}
					else{
						int diff1 = prer[i]-preb[i];
						int diff2 = r-prer[j-1]-b+preb[j-1];
						if(diff1 > diff2){
							i--; diff++;
						}
						else{
							j++; diff++;
						}
					}
				}
				else if(j==2*n && i>=0){
					if(a[i]==1) diff--;
					else diff++;
					i--;
				}
				else if(i==-1 && j<=2*n-1){
					if(a[j]==1) diff--;
					else diff++;
					j++;
				}
				else{
					//diff will be 0 because nothing's left
				}
			}
			cout<<j-i-1<<endl;
		}
	}
}