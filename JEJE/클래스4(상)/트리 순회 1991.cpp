// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;

struct bintree{
    char left, right;
}; vector<bintree> v(27);

void preorder(char node)
{
    if(node == '.') return;
    cout << node;
    preorder(v[node-'A'].left);
    preorder(v[node-'A'].right);
}

void inorder(char node)
{
    if(node == '.') return;
    inorder(v[node-'A'].left);
    cout << node;
    inorder(v[node-'A'].right);
}

void postorder(char node)
{
    if(node == '.') return;
    postorder(v[node-'A'].left);
    postorder(v[node-'A'].right);
    cout << node;
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        char root, l, r;
        cin >> root >> l >> r;
        v[root-'A'].left = l;
        v[root-'A'].right = r;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
}