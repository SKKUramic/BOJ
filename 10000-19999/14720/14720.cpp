// 14720 우유 축제
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int milk[1001];
    int stores;
    int cnt = 0;
    cin >> stores;
    for (int i = 0; i < stores; i++){
        cin >> milk[i];
    }
    for (int a = 0; a < stores; a++){
        if (cnt % 3 == milk[a]){
            cnt++;
        }
    }
    cout << cnt;
}