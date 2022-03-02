// 4641 Doubles
// https://www.acmicpc.net/problem/4641
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int num = 100, count;
	vector<int> v;
	while (1){
		count = 0;
		while (1){
			cin >> num;
			if (num == -1){return 0;}
			else if (num == 0) {break;}
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++){
			for (int j = i + 1; j < v.size(); j++){
				if (v[i] * 2 == v[j]){
					count++;
				}
			}
		}
		cout << count << '\n';
		v.clear();
	}
}