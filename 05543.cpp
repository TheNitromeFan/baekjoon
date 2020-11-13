#include <iostream>

using namespace std;

int main(){
	int burger, soda;
	int min_burger = 2000, min_soda = 2000;
	for(int i = 0; i < 3; ++i){
		cin >> burger;
		if(burger < min_burger){
			min_burger = burger;
		}
	}
	for(int i = 0; i < 2; ++i){
		cin >> soda;
		if(soda < min_soda){
			min_soda = soda;
		}
	}
	cout << min_burger + min_soda - 50 << endl;
	return 0;
}
