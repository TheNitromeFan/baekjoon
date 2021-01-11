#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int low = 0, high = a[1];
	int alternating_difference = a[1];
	for(int i = 2; i <= n; ++i){
		if(i % 2 == 0){
			alternating_difference -= a[i];
			if(alternating_difference > low){
				low = alternating_difference;
			}
		}else{
			alternating_difference += a[i];
			if(alternating_difference < high){
				high = alternating_difference;
			}
		}
	}
	cout << (low <= high ? high - low + 1 : 0);
	return 0;
}
