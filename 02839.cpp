#include <iostream>

using std::cin;
using std::cout;

int main(){
	int weight = 0;
	cin >> weight;
	int threes = weight * 2 % 5;
	int fives = (weight - 3 * threes) / 5;
	if(fives < 0)
		cout << -1;
	else
		cout << threes + fives;
	return 0;
}
