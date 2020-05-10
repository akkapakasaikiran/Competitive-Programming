#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("testcase.txt");

	fout<<1<<endl;
	fout<<200000<<endl;
	int num;
	for(int i = 0; i<200000;i++){
		num = rand();
		if(num == 0) i--;
		else fout<<num<<" ";
	}

}