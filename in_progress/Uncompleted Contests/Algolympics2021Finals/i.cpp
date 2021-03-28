#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m; cin >> m;
    while(m--){
        set<string> supposed;
        int a; cin >> a;
        for (int i = 0; i < a; i++){
            string s; cin >> s;
            supposed.insert(s);
        }
        int p; cin >> p;
        bool hacked = 0;
        int cnt = 0;
        for (int i = 0; i < p; i++){
            string s; cin >> s;
            if (supposed.find(s) != supposed.end()) cnt++;
            else hacked = 1;
        }

        if (hacked) cout << "STAR STREAM HACKED!!!";
        else if (2*cnt >= a) cout << "START THE MEETING.";
        else cout << "NO STARS IN THE NIGHT SKY.";
        cout << endl;
    }
    return 0;
}