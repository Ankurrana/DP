#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
#include <map>
 
#define getw getchar_unlocked
#define iterate(n) for(i=0;i<n;i++)
#define d_iterate(p,q) for(int i=p;i<=q;i++)
#define r_iterate(n,z) for(int i=n-1;i>=n-z;i--) /* z number of elements to the left of n */
#define p(n) printf("%d\n",n);
#define get(n) n = scan2();
// #define sort(k,q) qsort(k,q,sizeof(*k),comp);
#define print_array(k,n) iterate(n){ p(k[i]);}
#define ps(s) printf("%s\n",s);
#define repeat(n) for (int i = (0); i < n; i++)
#define clear(v) memset((v), 0, sizeof (v))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair;
#define pb push_back;
// int comp(const void *e1,const void *e2){ return *((const lld *)e1) - *((const lld *)e2);}
 
typedef unsigned long long int lld;
typedef unsigned long int ld;
using namespace std;
 
inline lld scan2(){
	lld n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}

lld ks(lld *w, lld *v, lld c ,lld l){
	//l is the lenght
	int i,j,k;
	lld dp[l+1][c+1];
	dp[0][0] = 0;  //upto items 0 with capacity = 0  or dp[0..l][0] = 0 ; if capacity is 0 then everything in 0
	//  and dp[0][0..cap] = 0 because none of the items are considered herein

	iterate(c+1)
		dp[0][i] = 0;

	iterate(l+1)
		dp[i][0] = 0;  //in case no capacity is provided

	// for(i=1;i<=c;i++){
	// 	//the capacity is c
	// 	for(j=1;j<=l;j++){
	// 		// the item is j-1
	// 		if( w[j-1] <= i )
	// 			dp[j][i] = max( dp[j-1][i],dp[j-1][i - w[j-1]] + v[j-1]);
	// 		else
	// 			dp[j][i] = dp[j-1][i];
	// 	}
	// }

	for(  i = 1;i<=l;i++ ){
		for(  j = 1;j<=c;j++){
			if( w[i-1] <= j ){
				dp[i][j] = max( dp[i-1][j] , dp[i-1][j-w[i-1]]+v[i-1]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	for( i=0;i<=l;i++){
		for(j=0;j<=c;j++ ){
			cout << dp[i][j] << " " ;
		}
		cout << endl;
	}

	return dp[l][c];

}
 

 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	lld w[] = {3,1,2,4};
	lld v[] = {5,3,12,1};

	ks(w,v,5,4);
 
	return 0;
}