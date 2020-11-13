#include <iostream>

using namespace std;

int main(){
	int e, f, c;
	cin >> e >> f >> c;
	int empty = e + f;
	int total = 0;
	while(empty >= c){
		int tmp = empty / c;
		total += tmp;
		empty = tmp + empty % c;
	}
	cout << total;
	return 0;
}
