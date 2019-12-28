#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
        int x = ceil(1.0*a/c); 
        int y = ceil(1.0*b/d);
        if(x+y<=k) cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
    }
}