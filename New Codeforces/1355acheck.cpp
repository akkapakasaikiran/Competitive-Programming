#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("1335atestcase.txt");

	fout<<10000<<endl;
	//fout<<10000<<endl;
	int num;
	for(int i = 0; i<10000;i++){
		num = rand();
		if(num <= 0) i--;
		else fout<<num<<" "<<num-1<<endl;
	}

}