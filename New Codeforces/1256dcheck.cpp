#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("1256d.txt");

	fout<<1<<endl;
	fout<<1000000<<" "<<9428683473<<endl;
	int bit;
	for(int i = 0; i<1000000;i++){
		bit = rand()%2;
		if(bit < 0) i--;
		else fout<<bit;
	}
	fout<<endl;

}