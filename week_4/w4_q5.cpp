#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll inv(ll r_i, ll r_j) {
    if(r_i > r_j) return ((r_i-r_j)*r_j+r_j*(r_j*r_j-1)/3);
    else return r_j*(r_j*r_j-1)/3;
}

