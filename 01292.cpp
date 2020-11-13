#include <iostream>

using namespace std;

int main(){
	int arr[1001];
	int index = 1;
	for(int i = 1; i <= 44; ++i){
		for(int j = 1; j <= i; ++j){
			arr[index] = i;
			++index;
		}
	}
	for(; index <= 1000; ++index){
		arr[index] = 45;
	}
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for(index = a; index <= b; ++index){
		sum += arr[index];
	}
	cout << sum << endl;
	return 0;
}
