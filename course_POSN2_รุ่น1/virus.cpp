#include <iostream>
#include <vector>

using namespace std;

void kmpPreprocess(string p, int pi[]) {
    for(int i=1; i<p.size(); i++) {
        int j=pi[i-1];
        while(j>0 && p[j]!=p[i])
            j = pi[j-1];
        if(p[j]==p[i]) 
            j++;
        pi[i] = j;
    }
}

int match_string(string t, string p) {
    int ans=0;
    int pi[p.size()];
    pi[0] = 0;
    kmpPreprocess(p, pi);
    int j=0;
    for(int i=0; i<t.size(); i++) {
        while(j>0 && t[i]!=p[j]) 
            j = pi[j-1];
        if(p[j]==t[i]) 
            j++;
        if(j==p.size()) 
            ans++;
    }
    return ans;
}

int matches[100001];
string p[100001];
vector<string> v_ans;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    string s; cin >> s;
    int t; cin >> t;

    int max_string_length = 0;
    for(int i=1; i<=t; i++) {
        cin >> p[i];

        matches[i] = match_string(s, p[i]);

        max_string_length = max(matches[i], max_string_length);
    }

    for(int i=1; i<=t; i++) {
        if(matches[i]==max_string_length) {
            v_ans.push_back(p[i]);
        }
    }

    sort(v_ans.begin(), v_ans.end(), [&](string a, string b) {
        if(a.size()==b.size()) return a < b;
        return a.size() < b.size();
    });

    cout << v_ans[0] << '\n';

    return 0;
}