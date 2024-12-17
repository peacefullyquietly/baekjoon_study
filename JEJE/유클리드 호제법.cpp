// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
// int Ualgo(int n1, int n2)
// {
//     if(n2 == 0) return n1;
//     Ualgo(n2, n1%n2);
// }

int Ualgo(int n1, int n2)
{
    if(n2 == 0) return n1;
    else return Ualgo(n2, n1%n2);
}