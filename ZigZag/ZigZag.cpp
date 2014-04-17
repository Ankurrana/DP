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
 
lld longestzigzag(lld *a,int l){
	//for now considering differernt terms
	lld dp[l+1][2];   //0 for down and 1 for u
	dp[1][0] = 1;   //single element is always has lenght 1 for both Up and down
	dp[1][1] = 1;
	lld i,j,k;
	lld maxu , maxd , ans;
	for(i = 2; i<=l ;i++){
		maxu = 0;
		maxd = 0;

		for(j=1;j<i;j++){
			if( a[j-1] > a[i-1]){
	
				if( dp[j][1]  > maxd )
					maxd = dp[j][1];
			}else if( a[j-1] < a[i-1]){	

				if( dp[j][0] > maxu )
					maxu = dp[j][0];
			}
		}

		dp[i][0] = maxd + 1;
		dp[i][1] = maxu + 1;

	}
	ans = 0;
	for(i=1;i<=l;i++){

		if( dp[i][1] > ans )
				ans = dp[i][1];
		if( dp[i][0] > ans)
		 		ans = dp[i][0];


	}

	return ans;

}

 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;

	lld arr[] = { 
					374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
					600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
					67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
					477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
					249, 22, 176, 279, 23, 22, 617, 462, 459, 244 
				};

	cout << longestzigzag(arr,50) << endl;

	return 0;
}