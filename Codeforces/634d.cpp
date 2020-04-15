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

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); }
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		vvi sudoku; sudoku.resize(9);
		rep(i,9){
			st s; cin>>s;
			rep(j,9) sudoku[i].pb(s[j]-48);
		}
		
		vector<st> posns;
		posns.pb("00"); posns.pb("13"); posns.pb("26");
		posns.pb("31"); posns.pb("44"); posns.pb("57");
		posns.pb("62"); posns.pb("75"); posns.pb("88");

		rep(i,9){
			int pos1 = posns[i][0] - 48;
			int pos2 = posns[i][1] - 48;
			if(sudoku[pos1][pos2] != 9) sudoku[pos1][pos2] = 9;
			else sudoku[pos1][pos2] = 8;
		}
		rep(i,9){
			rep(j,9) cout<<sudoku[i][j];
			cout<<endl;
		}
	}
}