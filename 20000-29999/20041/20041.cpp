// 20041 Escaping
// https://www.acmicpc.net/problem/20041
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> Police;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool East = true, West = true, South = true, North = true;
	int N;
	ll x, y, theifX, theifY, diffX, diffY;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> x >> y;
		Police.push_back({x, y});
	}
	cin >> theifX >> theifY;
	for (int n = 0; n < N; n++){
		diffX = Police[n].first - theifX;
		diffY = Police[n].second - theifY;
		if (diffX >= abs(diffY)){
			East = false;
		}
		if (-diffX >= abs(diffY)){
			West = false;
		}
		if (diffY >= abs(diffX)){
			North = false;
		}
		if (-diffY >= abs(diffX)){
			South = false;
		}
	}
	if (South || North || West || East){cout << "YES";}
	else {cout << "NO";}
}