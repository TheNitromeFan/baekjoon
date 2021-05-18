#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double t[10];
	double sum = 0;
	for(int i = 0; i < 10; ++i){
		cin >> t[i];
		sum += t[i];
	}
	double avg = sum / 10.0;
	double sum_of_squares = 0;
	for(int i = 0; i < 10; ++i){
		sum_of_squares += (t[i] - avg) * (t[i] - avg);
	}
	cout << (sum_of_squares <= 9 ? "COMFY" : "NOT COMFY");
	return 0;
}
