#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("testcase.txt");

	fout<<100<<endl;
	//fout<<10000<<endl;
	int num;
	for(int i = 0; i<100;i++){
		num = (rand())%1000;
		if(num <= 0) i--;
		else fout<<num<<endl;
	}

}