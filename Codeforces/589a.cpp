#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dis(int x){
	bool digits[10]={false};
	while(x!=0){
		int d = x%10;
		if(digits[d]==true) return false;
		else digits[d]=true;
		x=x/10;
	}
	return true;
}

int main(){
	int l,r; cin>>l>>r;
	int v;
	for(v=l;v<=r;v++){
		if(dis(v)){
			cout<<v<<endl;
			break;
		}
	}
	if (v==r+1) cout<<-1<<endl;

}