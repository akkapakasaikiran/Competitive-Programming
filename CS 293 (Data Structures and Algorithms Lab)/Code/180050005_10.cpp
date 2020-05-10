#include<iostream>
using namespace std;
typedef long long int ll;

const int N=500007;
ll BIT[N];

void update(ll x, ll delta){
	for(; x <= N; x += x&-x) BIT[x] += delta;
}

ll query(ll x){
	ll sum = 0;
	for(; x > 0; x -= x&-x) sum += BIT[x];
	return sum;
}

int main(){

	int n; cin>>n;
	long long ans;
	ll p[n];
	for(int i=0;i<n;i++) cin>>p[i];

	ll s1=0; // 123 + 132
	for(int i=n-1;i>=0;i--){
		ll bigafter = query(N-1)-query(p[i]);
		s1 += (bigafter*(bigafter-1))/2;
		update(p[i],1);
	}

	for(int i=0;i<N;i++) BIT[i]=0;

	ll ijk=0; // 123
	for(int i=0;i<n;i++){
		ll smallbefore = query(p[i]);
		ll bigafter = n-i-p[i]+smallbefore;
		ijk += smallbefore * bigafter;
		update(p[i],1);
	}

	for(int i=0;i<N;i++) BIT[i]=0;	

	ll s3=0; // 132 + 312
	for(int i=0;i<n;i++){
		ll smallbefore=query(p[i]);
		ll bigbefore=query(N-1)-smallbefore;
		s3 += smallbefore * bigbefore;
		update(p[i],1);
	}

	ll ikj,jki;
	ikj=s1-ijk;  // 132
	jki=s3-ikj;  // 312
	cout<<ikj<<" "<<jki<<endl;

}