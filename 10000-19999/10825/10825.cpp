// 10825 국영수
// https://www.acmicpc.net/problem/10825
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Student{
	string name;
	int language;
	int english;
	int math;
}student;

vector<student> school;

bool cmp(student A, student B){
	if (A.language == B.language){
		if (A.english == B.english){
			if (A.math == B.math){
				return A.name < B.name;
			}
			else {
				return A.math > B.math;
			}
		}
		else {
			return A.english < B.english;
		}
	}
	else {
		return A.language > B.language;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	student temp;
	for (int i = 0; i < N; i++){
		cin >> temp.name >> temp.language >> temp.english >> temp.math;
		school.push_back(temp);
	}
	sort(school.begin(), school.end(), cmp);
	for (int i = 0; i < N; i++){
		cout << school[i].name << '\n';
	}
}