#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int binmodexp(int a,int b,int m){
	if(b==0) return 1;
	else if(b%2==1) return (a*binmodexp(a,b-1,m))%m;
	else{
		long long x = pow(binmodexp(a,b/2,m)%m,2);
		/*cout<<x<<" "<<a<<" "<<b<<" "<<m<<endl;*/
		return x%m;
	}
}

void printgrid(vector<vector<int> > grid){
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++) cout<<grid[i][j]<<" ";
		cout<<endl;
	}
	cout<<"------"<<endl;
}

int main(){
	int big = 1000000007;
	vector<int> r;
	vector<int> c;
	int h,w,temp;

	cin>>h>>w;
	int count = h*w;
	for(int i=0;i<h;i++){
		cin>>temp;
		r.push_back(temp);
	}
	for(int i=0;i<w;i++){
		cin>>temp;
		c.push_back(temp);
	}

	vector< vector<int> > grid;
	grid.resize(h);
	for(int i=0;i<h;i++) grid[i].resize(w);

	/*grid[1][0]=5;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) cout<<grid[i][j]<<" ";
		cout<<endl;
	}*/

	bool ok = true;

	for(int i=0;i<h;i++){
		int j=0;
		for(;j<r[i];j++){
			grid[i][j]=1;
			count--;
		}
		if(j==w) continue;
		grid[i][j]=-1; count--;
	}

	for(int i=0;i<w;i++){
		int j=0;
		for(;j<c[i];j++){
			if(grid[j][i]==1) continue;
			else if(grid[j][i]==-1){ 
				ok=false;
				break;
			}
			else if (grid[j][i]==0){
				count--;
				grid[j][i]=1;
			}
/*			printgrid(grid);*/
		}
		if(not(ok)) break;
		if(j==h) continue;
		if(grid[j][i]==-1) continue;
		else if(grid[j][i]==1){ 
			ok=false;
			break;
		}
		else if (grid[j][i]==0){
			count--;
			grid[j][i]=-1;
		}
	}

	/*printgrid(grid);
	cout<<count<<endl;*/

	/*cout<<binmodexp(2,51,big);*/

	if(not(ok)) cout<<0<<endl;
	else cout<<binmodexp(2,count,big)<<endl;

}