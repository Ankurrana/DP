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
 
typedef long long int lld;
typedef long int ld;
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

int lenghtOFLCS(lld *a,int l) {
	// l = lenght of the array
	// a = is the array

	lld dp[l+1];
	clear(dp);
	dp[0] = 0;
	int i,j,k;

	for(j=1;j<=l;j++){
		lld max = 0;
		for(i=1;i<=l;i++){
			if( a[j-1]>=a[i-1] && dp[i]>max)
				max = dp[i];
		}
		dp[j] = max + 1;

		// cout << dp[j] << endl;
	}

	lld max = 0;
	for(i=1;i<=l;i++){
		if(max < dp[i])
			max = dp[i];
	}

	return max;

}


 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld b,c,d;
	
	/*	
		This code is for non - decreasing sequence < for making it strictly increasing just alter line:54 to a[j-1]>a[i-1]
	*/

 	lld a[] = {2,1,3,4,2,4,5,6};

 	cout << lenghtOFLCS(a,8) << endl;
	return 0;
}