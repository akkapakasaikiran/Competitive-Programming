#include<iostream>
using namespace std;

int num_twos(int n){
	int cnt=0;
	while(n%2==0){
		n=n/2;
		cnt++;
	}
	return cnt;
}

int num_threes(int n){
	int cnt=0;
	while(n%3==0){
		n=n/3;
		cnt++;
	}
	return cnt;
}

int main(){
	int n,m; cin>>n>>m; 
	
	int x2 = num_twos(n);
	int x3 = num_threes(n);
	int y2 = num_twos(m);
	int y3 = num_threes(m);
	
	// cout<<x2<<" "<<x3<<" "<<y2<<" "<<y3<<endl;
	if (y2 - x2 >=0 && y3 - x3 >=0) cout<< y3 + y2 - x3 - x2 <<endl;
	else cout<<-1<<endl;

}