#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int low = 1, high = n;
	int mid = 0;
	while(low <= high){
		mid = (low + high) / 2;
		cout << "? " << mid << endl;
		int ans;
		cin >> ans;
		if(ans == 0){
			break;
		}else if(ans > 0){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	cout << "= " << mid << endl;
	return 0;
}
