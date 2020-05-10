#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void take_input(int size, vector<int> &a){
	int tmp;
	for(int i=0;i<size;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
}



int main(){
	int n,k,a,b; cin>>n>>k>>a>>b;
	vector<int> a;
	take_input(k,a);
}