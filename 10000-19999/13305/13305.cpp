// 13305 주유소
#include <iostream>
using namespace std;

unsigned long long int city_oil_price[100001] = {0, };
unsigned long long int city_distance[100001] = {0, };
unsigned long long int total_price = 0;

int main(){
	int city_count, city_index = 0, previous_price = -1;
	cin >> city_count;
	for (int i = 0; i < city_count - 1; i++)
		cin >> city_distance[i];
	for (int i = 0; i < city_count; i++)
		cin >> city_oil_price[i];
	while (city_index != city_count - 1){
		if (city_oil_price[city_index] <= previous_price){
			previous_price = city_oil_price[city_index];
		}
		/*
		if (city_index == 0){
			total_price += city_oil_price[city_index] * city_distance[city_index];
			previous_price = city_oil_price[city_index];
		}
		else {
			if (city_oil_price[city_index] > previous_price){
				total_price += previous_price * city_distance[city_index];
			}
			else {
				total_price += city_oil_price[city_index] * city_distance[city_index];
				previous_price = city_oil_price[city_index];
			}
		}
		*/
		total_price += previous_price * city_distance[city_index];
		city_index++;
	}
	cout << total_price;
}