#include <bits/stdc++.h>

using namespace std;

int getmid(char ch) {
    return ch - 'a';
}

int getwid(char ch) {
    return ch - 'A';
}

pair<string, string> split_str(string& s, char ch) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ch) {
            idx = i;
            break;
        }
    }
    assert(idx < (int)s.size()); // check invalid input
    return {s.substr(0, idx), s.substr(idx + 1)};
}

// male-optimal stable marriage
void gale_shapley() {
    int n;

    vector<int> M(26, -1);
    vector<vector<int>> mpref(26);
    vector<int> mnext(26);

    vector<int> W(26, -1);
    vector<vector<int>> wpref(26);
    vector<bool> wengaged(26);
    vector<int> wengagedto(26, -1);

    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch; 
        cin >> ch;
        M[i] = getmid(ch);
    }

    for (int i = 0; i < n; i++) {
        char ch; 
        cin >> ch;
        W[i] = getwid(ch);
    }

    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        auto [id, plist] = split_str(s, ':');
        auto& entry = mpref[getmid(id[0])];
        entry.resize(n);
        for (int i = 0; i < n; i++)
            entry[i] = getwid(plist[i]);
    }

    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        auto [id, plist] = split_str(s, ':');
        auto& entry = wpref[getwid(id[0])];
        entry.resize(n);
        // modify women preference list to compare each men in constant time
        // pref[i] = j to pref[j] = i
        vector<int> pref(n);
        for (int i = 0; i < n; i++) 
            pref[i] = getmid(plist[i]);
        for (int i = 0; i < n; i++) 
            entry[pref[i]] = i;
    }

    // run g-s algorithm

    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (M[i] != -1)
            q.push(M[i]);
    }

    while (!q.empty()) {
        int m = q.front();
        q.pop();
        // w = the highest-ranked woman in m's preference list to whom m has not yet proposed
        int w = mpref[m][mnext[m]++];
        if (!wengaged[w]) {
            wengaged[w] = true; 
            wengagedto[w] = m;
            continue;
        }
        int m2 = wengagedto[w];
        // lower the higher
        if (wpref[w][m] > wpref[w][m2]) { 
            q.push(m);
        } else {
            wengagedto[w] = m;
            q.push(m2);
        }   
    }

    map<int, int> S;

    for (int i = 0; i < 26; i++) {
        if (wengagedto[i] != -1)
            S[wengagedto[i]] = i;
    }

    for (auto [m, w] : S)
        cout << (char)(m + 'a') << ' ' << (char)(w + 'A') << '\n';
}

int main() {
#ifdef _DEBUG
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;

    while (t--) {
        gale_shapley();
        if (t)
            cout << '\n';
    }
}