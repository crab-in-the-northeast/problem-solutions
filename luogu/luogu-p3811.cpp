/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:46:01 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:46:01 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,p,inv[3000005];
int main()
{
	scanf("%d%d",&n,&p);
	inv[1]=1; puts("1");
	for(int i=2;i<=n;i++)
	{
		inv[i]=(long long)(p-p/i)*inv[p%i]%p;
		printf("%d\n",inv[i]);
	}
	return 0;
}
