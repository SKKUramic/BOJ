// 18114 블랙 프라이데이
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

int weight[5001];
bool check[100000001];
int answer;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
    int C;
    cin >> N >> C;
    for (int i = 0; i < N; i++){
        cin >> weight[i];
        check[weight[i]] = true;
    }
    bool isOK = check[C];
    int add;
    if (!isOK){
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                add = weight[i] + weight[j];
                if (add == C){
                    isOK = true;
                    break;
                }
                else if (add < C){
                    int diff = C - add;
                    if (check[diff] && diff != weight[i] && diff != weight[j]){
                        isOK = true;
                        break;
                    }
                }
            }
            if (isOK){
                break;
            }
        }
    }
    cout << isOK;
    return 0;
}
