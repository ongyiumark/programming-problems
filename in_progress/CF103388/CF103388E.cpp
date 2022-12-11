#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4+5;
int t[N];
int d[N];
queue<int> q[2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
        q[d[i]].push(t[i]);
    }

    int time = t[0];
    int currd = d[0];
    q[d[0]].pop();

    while(true) {
        if (!q[currd].empty()){
            int nxt = q[currd].front();
            if (nxt < time + 10) {
                time = max(time,nxt);
                q[currd].pop();
                continue;
            }
        }

        int nxt0, nxt1;
        nxt0 = nxt1 = -1;
        
        if (!q[0].empty()) nxt0 = q[0].front();
        if (!q[1].empty()) nxt1 = q[1].front();

        if (nxt0 == -1 && nxt1 == -1) {
            break;
        }
        
        if (nxt0 > 0 && nxt1 > 0) {
            if (nxt0 < nxt1) nxt1 = -1;
            else nxt0 = -1;
        }

        if (nxt0 == -1) {
            currd = 1;
            int tmp = q[currd].front();
            q[currd].pop();
            time = max(time+10, tmp);
        }
        else if (nxt1 == -1){
            currd = 0;
            int tmp = q[currd].front();
            q[currd].pop();
            time = max(time+10, tmp);
        }
    }

    cout << time+10 << endl;
    return 0;
}