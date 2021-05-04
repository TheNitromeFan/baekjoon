#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int min = 1000000003;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(min > x){
			min = x;
		}
	}
	cout << fixed << setprecision(2) << (double)min;
	return 0;
}
