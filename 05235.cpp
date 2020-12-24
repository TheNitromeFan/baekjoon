#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int k;
		cin >> k;
		int even = 0, odd = 0;
		for(int j = 0; j < k; ++j){
			int x;
			cin >> x;
			if(x % 2 == 0){
				even += x;
			}else{
				odd += x;
			}
		}
		if(even > odd){
			cout << "EVEN";
		}else if(even < odd){
			cout << "ODD";
		}else{
			cout << "TIE";
		}
		cout << "\n";
	}
	return 0;
}
