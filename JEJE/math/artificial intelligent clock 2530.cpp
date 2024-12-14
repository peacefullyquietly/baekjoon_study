#include <stdio.h>
int main(){int h,m,s,t;scanf("%d %d %d %d", &h,&m,&s,&t);s+=t;m+=s/60;s%=60;h+=m/60;m%=60;h%=24;printf("%d %d %d",h,m,s);}