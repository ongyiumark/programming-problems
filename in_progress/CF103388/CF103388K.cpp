#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, D, M; cin >> T >> D >> M;

    bool valid = false;
    int prev = 0;
    for (int i = 0; i < M; i++) {
        int curr; cin >> curr;
        if (curr-prev >= T) valid = true; 
        prev = curr;
    }
    if (D-prev >= T) valid = true;
    cout << (valid ? "Y" : "N") << endl;
    
    return 0;
}