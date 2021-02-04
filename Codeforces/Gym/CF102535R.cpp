/*
    Let f_g(x,y) be the number of pairs (i,j) where i <= x, and j <= y such that gcd(i,j) = g
    We want to find f_1(x,y). 
    
    Similar to the previous problem, f_1(x,y) = xy - f_2(x,y) - f_3(x,y) - ...
    But, we can no longer solve it the same way as that will take O(xy).

    Notice that if gcd(i, j) = g, then both i and j are divisible by g.
    That is, gcd(ga, gb) = g such that i = ga and j = gb.
    This transforms to gcd(a,b) = 1 where a <= x//g and b <= y//g.

    Thus, f_g(x,y) = f_1(x//g, y//g).
    We now have f(x,y) = xy - f(x//2,y//2) - f(x//3,y//3) - ... 

    Since there's only sqrt(x) dictinct answers to x//g, we can memoize this.
    WLOG x <= y.
    We split the operation into two: less than and greater than g = sqrt(y).

    For the less than part, we subtract normally.
    For the greater than part, we subtract each possibility times the count.
        x//i gives the largest g such that x//g = i
    So, we can start from g = floor(sqrt(x)) + 1 and let g = min(x//(x//g), y//(y//g))+1 after every iteration. 

    Lastly, we have to deal with the memoization.
    Normal memoization would be too slow so we have to be creative. 
    Notice that g is sufficient to describe a state. 
    Also, x//g + y//g is unique for every state because both x//g and y//g are monatonically decreasing.

    So, we can memoize on g when g is small enough, otherwise memoize on x//g+y//g.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e6;
const ll N = 72000;
ll memod[N+1];
ll memosum[2*N+1];

ll solve(ll x, ll y, ll d) {
    if (x > y) swap(x, y);
    if(x == 0) return 0;
    if(x == 1) return y%MOD;
    if(x+y <= 2*N && memosum[x+y] != -1) return memosum[x+y];
    if(d <= N && memod[d] != -1) return memod[d];

    ll lim = floor(sqrtl(y));
    ll ret = ((x%MOD)*(y%MOD))%MOD;
    for(ll i = 2; i <= lim; i++) ret -= solve(x/i,y/i,d*i);
    ret %= MOD;

    ll i = lim+1;
    ll rx, ry;

    while(i <= x){
        rx = x/(x/i);
        ry = y/(y/i);

        ret -= solve(x/i,y/i,d*i)*(min(rx,ry)-i+1);
        ret %= MOD;

        i = min(rx,ry)+1;
    }
    if (ret < 0) ret += MOD;
    if(d <= N) memod[d] = ret;
    if(x+y <= 2*N) memosum[x+y] = ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memosum,-1,sizeof memosum);
    memset(memod,-1,sizeof memod);
    ll k, b; cin >> k >> b; b--;

    cout << solve(k,b,1) << endl;
    return 0;
}