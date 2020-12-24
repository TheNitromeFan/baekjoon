#include <iostream>

using namespace std;

int binary_steps(int n, int i){
	int left = 0, right = n - 1;
	int ret = 0;
	while(true){
		int mid = (left + right) / 2;
		if(mid == i){
			break;
		}else if(i < mid){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
		++ret;
	}
	return ret;
}

int ternary_steps(int n, int i){
	int left = 0, right = n - 1;
	int ret = 0;
	while(true){
		int left_third = left + (right - left) / 3;
		int right_third = right - (right - left) / 3;
		if(left_third == i){
			break;
		}else if(right_third == i){
			++ret;
			break;
		}else if(i < left_third){
			ret += 2;
			right = left_third - 1;
		}else if(i < right_third){
			ret += 2;
			left = left_third + 1;
			right = right_third - 1;
		}else{
			ret += 2;
			left = right_third + 1;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int smaller = 0, equal = 0, bigger = 0;
	for(int i = 0; i < n; ++i){
		int bi = binary_steps(n, i), ti = ternary_steps(n, i);
		if(bi < ti){
			++smaller;
		}else if(bi == ti){
			++equal;
		}else{
			++bigger;
		}
	}
	cout << smaller << '\n' << equal << '\n' << bigger;
	return 0;
}
