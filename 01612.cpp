#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n % 2 == 0 || n % 5 == 0){
		cout << "-1" << endl;
		return 0;
	}
	int ones = 1, places = 1;
	while(true){
		if(ones % n == 0){
			cout << places << endl;
			return 0;
		}
		ones = (10 * ones + 1) % n;
		++places;
	}
}
