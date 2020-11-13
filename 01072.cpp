#include <iostream>

using namespace std;

long long parametric_search(long long x, long long y, long long z, long long start, long long end){
	if(start > end){
		return start;
	}
	long long middle = (start + end) / 2;
	if(100 * (y+middle) / (x+middle) > z){
		return parametric_search(x, y, z, start, middle-1);
	}else{
		return parametric_search(x, y, z, middle+1, end);
	}
}

int main(){
	long long x, y;
	while(cin >> x >> y){
		long long z = 100 * y / x;
		if(z >= 99LL){
			cout << -1 << '\n';
		}else{
			cout << parametric_search(x, y, z, 0LL, 99*x) << '\n';
		}
	}
	return 0;
}
