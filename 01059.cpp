#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::sort;

static int intervals(int lucky[51], size_t len, int unlucky){
	sort(lucky, lucky+len+1);
	for(size_t i = 0; i < len; ++i){
		if(lucky[i] < unlucky && lucky[i+1] > unlucky)
			return (unlucky - lucky[i]) * (lucky[i+1] - unlucky) - 1;
		else if(lucky[i] == unlucky || lucky[i+1] == unlucky)
			return 0;
	}
	return 0;
}

int main(){
	size_t l = 0;
	cin >> l;
	int numbers[51] = {0};
	for(size_t i = 1; i <= l; ++i){
		cin >> numbers[i];
	}
	int n = 0;
	cin >> n;
	cout << intervals(numbers, l, n);
	return 0;
}
