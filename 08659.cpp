#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int right_count = 0;
	long long passes = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x == 0){
			++right_count;
		}else{
			passes += right_count;
		}
	}
	cout << passes;
	return 0;
}
