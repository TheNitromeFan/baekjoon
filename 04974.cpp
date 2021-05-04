#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int sum = 0;
		int max = -100000, min = 100000;
		for(int i = 0; i < n; ++i){
			int score;
			cin >> score;
			sum += score;
			if(score > max){
				max = score;
			}
			if(score < min){
				min = score;
			}
		}
		cout << (sum - max - min) / (n - 2) << '\n';
	}
	return 0;
}
