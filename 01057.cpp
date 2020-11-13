#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, k, i;
	cin >> n >> k >> i;
	if(k > i){
		swap(k, i);
	}
	int rounds = 0;
	while(i-k > 0){
		++rounds;
		i = (i+1)/2;
		k = (k+1)/2;
	}
	cout << rounds << endl;
	return 0;
}
