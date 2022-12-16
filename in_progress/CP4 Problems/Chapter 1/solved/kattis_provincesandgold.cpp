#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const ld EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi power = {3, 2, 1};
    vi cards(3);
    for (int i = 0; i < 3; i++) cin >> cards[i];

    int total = 0;
    for (int i = 0; i < 3; i++) total += cards[i]*power[i];

    string bestVictory;
    if (total >= 8) bestVictory = "Province";
    else if (total >= 5) bestVictory = "Duchy";
    else if (total >= 2) bestVictory = "Estate";

    string bestTreasure;
    if (total >= 6) bestTreasure = "Gold";
    else if (total >= 3) bestTreasure = "Silver";
    else bestTreasure = "Copper";

    if (bestVictory != "") printf("%s or %s\n", bestVictory.c_str(), bestTreasure.c_str());
    else cout << bestTreasure << "\n";
    
    return 0;
}