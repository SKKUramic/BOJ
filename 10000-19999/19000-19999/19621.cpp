// 19621 회의실 배정 2
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int conference;
int answer;
vector<int> t;

void dfs(int cnt, int sum){
    if (cnt > conference - 1){
        answer = max(answer, sum);
        return;
    }
    dfs(cnt + 1, sum);
    dfs(cnt + 2, sum + t[cnt]);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> conference;
    t.resize(conference);

    for (int i = 0; i < conference; i++){
        cin >> t[i] >> t[i] >> t[i];
    }
    dfs(0, 0);
    cout << answer;
    return 0;
}
