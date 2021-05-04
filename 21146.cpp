#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for(int i = 0; i < k; ++i){
		int score;
		cin >> score;
		sum += score;
	}
	cout << fixed << setprecision(8) << (sum - 3 * (n - k)) / (double)n
	<< ' ' << (sum + 3 * (n - k)) / (double)n;
	return 0;
}
