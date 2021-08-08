// 1339 단어 수학
#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
vector<string> v;
map<char, int> alpha;
map<char, int> num;
vector<pair<int, char>> rev_alpha;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  v.resize(n);
  for (auto &i : v) cin >> i;
	
	for (auto str : v) {
		int len = str.length();
		for (int i = 0; i < len; i++) {
			alpha[str[i]] += pow(10, len - i - 1);
		}
	}
	for (auto i : alpha) {
		rev_alpha.emplace_back(i.second, i.first);
	}
	sort(rev_alpha.rbegin(), rev_alpha.rend());
	int temp = 9;
	for (auto i : rev_alpha){
		num[i.second] = temp--;
	}
	for (auto i : alpha){
		ans += num[i.first] * i.second;
	}
	cout << ans << endl;
}