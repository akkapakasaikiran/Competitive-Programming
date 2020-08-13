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


struct Point{
	int x;
	int y;

	Point(int xx = 0, int yy = 0){
		x = xx;
		y = yy;
	}
};

bool operator==(Point p1, Point p2){
	return p1.x == p2.x && p1.y == p2.y;
}

ostream& operator<<(ostream &os, Point p){
	return os<<"("<<p.x<<","<<p.y<<")";
}

int dist(Point p1, Point p2){
	return abs(p1.x-p2.x) + abs(p1.y-p2.y); 
}
 

struct Unit; 
struct Tower;


struct Unit{
	Point p;
	int sz;

	Unit(Point pp, int size){
		p = pp;
		sz = size;
	}

	void move(int index);

	int nearest_tower();

};

struct Tower{
	Point p;
	int h = 10;

	Tower(Point pp){
		p = pp;
	}

	int nearest_unit();
};


vector<Tower> towers;
vector<Unit> units;

void Unit::move(int index){
	Point tp = towers[index].p;
	if(abs(tp.y-p.y) >= abs(tp.x-p.x)) (tp.y < p.y) ? p.y-- : p.y++;
	else tp.x < p.x ? p.x-- : p.x++ ;
}

int Unit::nearest_tower(){
	int ret = -1;
	int best = INT_MAX, cur = 0;
	rep(i, towers.size()){
		if(towers[i].h == 0) continue;
		else{
			Point tp = towers[i].p;
			cur = dist(p, tp);
			if(cur < best){
				ret = i;
				best = cur;
			}
			else if(cur == best){
				Point retp = towers[ret].p;
				if(tp.y < retp.y) ret = i;
				else if(tp.y == retp.y && tp.x < retp.x) ret = i;
			}
		}
	}
	return ret;
}


int Tower::nearest_unit(){
	int ret = -1;
	int best = INT_MAX, cur = 0;
	rep(i, units.size()){
		if(units[i].sz == 0) continue;
		else{
			Point up = units[i].p;
			cur = dist(p, up);
			if(cur < best){
				ret = i;
				best = cur;
			}
			else if(cur == best){
				Point retp = units[ret].p;
				if(up.y < retp.y) ret = i;
				else if(up.y == retp.y && up.x < retp.x) ret = i;
			}
		}
		
	}
	return ret;
}

bool unitcomp(Unit u1, Unit u2){
	return make_pair(u1.p.y, u1.p.x) < make_pair(u2.p.y, u2.p.x);
}

bool gameover(){
	bool over = true;
	rep(i,towers.size()) if(towers[i].h != 0) over = false;
	if(over) return true;
	else{
		over = true;
		rep(i,units.size()) if(units[i].sz != 0) over = false;
		return over;
	}
}


void merge(){
	sort(units.begin(), units.end(), unitcomp);
	vector<Unit> ret = {units[0]};
	rep1(i,units.size()-1){
		if(units[i].p == ret.back().p){
			units[i].sz += ret.back().sz;
			ret.pop_back();
			ret.push_back(units[i]);
		}
		else if(units[i].sz != 0) ret.push_back(units[i]);
	}
	units = ret;
}

void attact(){
	vi hits(towers.size());
	rep(i,units.size()){ cout<<"";
		if(units[i].sz == 0) continue;
		else{
			int index = units[i].nearest_tower();
			if(index == -1) return;
			else if(dist(units[i].p, towers[index].p) == 1) hits[index] += units[i].sz;
			else units[i].move(index);		
		}	
	}
	rep(i,hits.size()) towers[i].h = max(0, towers[i].h - hits[i]);

	merge();
	// cout<<"Attact"<<endl;
	// cout<<"units:"<<endl;
	// rep(i,units.size()) cout<<units[i].p<<" "<<units[i].sz<<endl;
	// cout<<"towers:"<<endl;
	// rep(i,towers.size()) cout<<towers[i].p<<" "<<towers[i].h<<endl;
}


void defense(){ cout<<"";
	vi hits(units.size());
	rep(i, towers.size()){
		if(towers[i].h == 0) continue;
		else{
			int index = towers[i].nearest_unit();
			if(index == -1) return;
			else if(dist(towers[i].p, units[index].p) <= 4) hits[index]++;
		}
	}
	rep(i,hits.size()) units[i].sz = max(0, units[i].sz - hits[i]);

	// cout<<"Defense"<<endl;
	// cout<<"units:"<<endl;
	// rep(i,units.size()) cout<<units[i].p<<" "<<units[i].sz<<endl;
	// cout<<"towers:"<<endl;
	// rep(i,towers.size()) cout<<towers[i].p<<" "<<towers[i].h<<endl;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{

		// IO
		towers.clear();
		units.clear();

		int n; cin>>n;
		vector<vector<int>> grid(n);
		for(int i = 0; i < n; i++) tkii(grid[i], n);
		rep(i,n) rep(j,n) if(grid[i][j] == 1) towers.pb(Tower({j,i}));

		int m, x, y, s; cin>>m;
		rep(i,m){
			cin>>x>>y>>s;
			units.pb(Unit({x,y}, s));
		}

		//rep(i,units.size()) cout<<units[i].p<<"!"<<endl;


		// moves
		int ans = 0;
		while(!gameover()){
			ans++;

			attact();
			defense();
		}


		// Print the answer to standard output(screen).
		cout << "#" << test_case << " " << ans << endl;
	}

	return 0; // Your program should return 0 on normal termination.
}