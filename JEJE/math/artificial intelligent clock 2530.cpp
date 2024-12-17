// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <stdio.h>
int main(){int h,m,s,t;scanf("%d %d %d %d", &h,&m,&s,&t);s+=t;m+=s/60;s%=60;h+=m/60;m%=60;h%=24;printf("%d %d %d",h,m,s);}