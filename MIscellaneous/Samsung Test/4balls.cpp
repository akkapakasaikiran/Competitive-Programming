#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS	// Ignore build errors when using unsafe functions in Visual Studio.
#endif

#include <iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define all(v) v.begin(),v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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



vvi grid;

vi m1 = {1,2,3,4};
vi m2 = {5,5,5,5};

int findwrap(){
	int ret = -1;
	int n = grid.size();
	rep(i,n-1){
		vi tmp = {grid[n-1][i], grid[n-1][i+1], grid[n-2][i], grid[n-2][i+1]};
		sort(all(tmp));
		if(tmp == m1 || tmp == m2) return i;
	}
	return ret;
}

void fall(int i){
	int n = grid.size();
	for(int j = n-1; j >= 2; j--){
		grid[j][i] = grid[j-2][i];
		grid[j][i+1] = grid[j-2][i+1];
	}
	grid[0][i] = grid[1][i] = grid[0][i+1] = grid[1][i+1] = 0;
}


void rotate(){
	int n = grid.size();
	vvi newgrid(n, vi(n));
	rep(i,n) rep(j,n) newgrid[i][n-j-1] = grid[j][i];
	grid = newgrid;

	rep(i,n){
		vi tmp;
		rep(j,n) if(grid[j][i] != 0) tmp.pb(grid[j][i]);
		rep(j,n-tmp.size()) grid[j][i] = 0;
		rep(j,tmp.size()) grid[n-tmp.size()+j][i] = tmp[j];
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		grid.clear();
		int n; cin>>n;
		grid.resize(n, vi(n));
		rep(i,n) rep(j,n) cin>>grid[i][j];

		int cnt = 0, rot = 0;
		while(rot < 1000){
			int loc = findwrap(); 
			if(loc == -1){
				rot++;
				rotate();
			}
			else{
				cnt++;
				fall(loc);
			}

			//rep(i,n) prvi(grid[i]);
		}
		
		//rep(i,n) prvi(grid[i]);


		// Print the answer to standard output(screen).
		cout << "#" << test_case << " " << 4*cnt << endl;
	}

	return 0; // Your program should return 0 on normal termination.
}