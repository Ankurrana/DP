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

 
typedef unsigned long long int lld;
typedef unsigned long int ld;
using namespace std;
 
lld minCoins(lld *deno,lld money,int l){
	//Denominations are the type of coins while money is the amout we want
	// l dented the lenght of the deno array
	lld dp[money+1][l+1];
	dp[0][0] = 0;  // to make 0 amout i need zero coins But upto what index ?? i did not consider the denominations
				//	in this definition whick is not correct !
				// Maybe you should consider multi array

	for(int i=0;i<l;i++){
		dp[0][i] = 0; //we need zero coins to make amount 0 with any deno
	}


    for(lld m=1;m<=money;m++){
		for(int d=0;d<l;d++){
			if( m >= deno[d] && d>0){
				dp[m][d] = min( dp[m-deno[d]][d] + 1, dp[m][d-1]);
			}	
			else if(d>0)
				dp[m][d] = dp[m][d-1];
			else
				dp[m][d] = dp[m-deno[d]][d] + 1;
		}
	}

	return dp[money][l-1];

}


int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	
	lld g[] = {1,2,5,10};

	cout << minCoins(g,2,4);

 
	return 0;
}