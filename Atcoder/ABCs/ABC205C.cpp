#include <iostream>
#include <iomanip>
#include <set>

using namespace std;
typedef long double ld;
typedef long long ll;

char solve(ll a, ll b, ll c) {
    if (a == b) return '=';
    if (0 <= a and 0 <= b) return (a < b ? '<' : '>');
    if (c % 2 == 0) return solve(abs(a), abs(b), c);

    if (b < 0 and a < 0) return solve(-b, -a, c);
    return (a < 0 ? '<' : '>');

}

int main(int argc, char *argv[])
{
    ll a,b,c; cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}