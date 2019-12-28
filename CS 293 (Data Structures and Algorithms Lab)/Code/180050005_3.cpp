#include<iostream>
#include<vector>
using namespace std;
typedef vector<int>::iterator iter;

void easy_multiply(iter p, iter q, iter r, long long n){
	for(long long i=0;i<n;i++){ 
		for(long long j=0;j<n;j++){
		 *(r+i+j)+=(*(p+i))*(*(q+j));
		}
	}
}

void multiply(iter p,iter q,iter r,long long n){
	if (n<=16) easy_multiply(p,q,r,n) ; 
	//if (n==1) (*r) += (*p)*(*q);
	else{
		multiply(p,q,r,n/2); // R filled till first half
		multiply(p+n/2,q+n/2,r+n,n/2);  // second half of R filled

		long long i;
		for(i=0;i<n/2;i++){  // P_0 = P_0 + P_1
			*(p+i)+=*(p+n/2+i);
			*(q+i)+=*(q+n/2+i);
		}  
		vector<int> S(n);
		iter s=S.begin();

		multiply(p,q,s,n/2); // S populated
		for(i=0;i<n;i++) *(s+i) -= (*(r+i) + *(r+n+i));  // S=S-R(part 1) - R(Part 2)
		for(i=0;i<n;i++) *(r+n/2+i) += *(s+i); // Modifying R
		for(i=0;i<n/2;i++){
			*(p+i)-=*(p+n/2+i);  // restoring P and Q
			*(q+i)-=*(q+n/2+i);	
		}	
	}
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n,i;
	cin>>n;
	vector<int> P(n),Q(n),R(2*n);
	int x;
	for(i=0;i<n;i++){
		cin>>x; P[i]=x;
		//P[i]=1;
	}
	for(i=0;i<n;i++){
		cin>>x; Q[i]=x;
		//Q[i]=1;
	}

	multiply(P.begin(),Q.begin(),R.begin(),n);

	for(i=0;i<2*n-1;i++){
		cout<<*(R.begin()+i)<<" ";
	}

}