/*
	The Problem is given here : http://people.cs.clemson.edu/~bcdean/dp_practice/dp_6.swf	
	The problem actually is exactly like Longest Incresing Subsequnece
*/

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
#define iterate(n) for(lld i=0;i<n;i++)
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
 
lld lis(lld *a,int l) { // a is the list of numbers on the upper side of the river 
 	lld dp[l+1];
 	dp[0] = 0;
 	dp[1] = 1;  //dp just denotes the lenght of the lis
 	
 	/*
		dp[i] denotes the maximum lenght of the increasing sequnce which ends at i-1 index
		thus dp[0] = 0;
			dp[1] = 1;
	
 	*/

	for(lld i=1;i<=l;i++){
		lld max = 0;
		for(lld j=1;j<i;j++){
			if( (a[i-1] > a[j-1]) && ( dp[j]>max ) ){
				max = dp[j];
			}
		}
		dp[i] = max+1;

	}	

	lld ans = 0;
	iterate(l+1){
		ans = max(ans,dp[i]);
	}

	return ans;

 }
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld b,c,d;
	lld a[] = {1,2,3,4,5,6,7,8,9};

	cout << lis(a,9) << endl ; 	
 
	return 0;
}