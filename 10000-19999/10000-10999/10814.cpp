// 10814 나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct human{
	int age;
	string name;
	int rank;
}human;

vector<human> person;
int age_rank[201] = {0, };

bool compare_only_age(struct human x, struct human y){
	if (x.age == y.age)
		return x.rank < y.rank;
	return x.age < y.age;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, age;
	string name;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> age >> name;
		//person.push_back(make_pair<age, name>);
		person.push_back({age, name, age_rank[age]});
		age_rank[age]++;
	}
	sort(person.begin(), person.end(), compare_only_age);
	for (int x = 0; x < person.size(); x++)
		cout << person[x].age << ' ' << person[x].name << '\n';
	return 0;
}