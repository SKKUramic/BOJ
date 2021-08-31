// 3183 Dates
// https://www.acmicpc.net/problem/3183
#include <iostream>
using namespace std;

bool leap_year(int year){
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool valid_day(int day, int month, bool leap){
	if (month == 4 || month == 6 || month == 9 || month == 11){
		return (0 < day && day < 31);
	}
	else if (month == 2){
		if (leap == true){
			return (0 < day && day < 30);
		}
		else {
			return (0 < day && day < 29);
		}
	}
	else {
		return (0 < day && day < 32);
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int day, month, year;
	bool valid, leap;
	cin >> day >> month >> year;
	while (day != 0 || month != 0 || year != 0){
		valid = true;
		leap = leap_year(year);
		if ((day == 0 || day > 31) || (month == 0 || month > 12)){valid = false;}
		else {valid = valid_day(day, month, leap);}
		if (valid == true){cout << "Valid\n";}
		else {cout << "Invalid\n";}
		cin >> day >> month >> year;
	}
}