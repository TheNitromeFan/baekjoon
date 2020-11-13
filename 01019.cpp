#include <iostream>

using namespace std;

long long ans[10];

void calc(long long n, long long ten){
	while(n){
		ans[n % 10] += ten;
		n /= 10;
	}
}

int main(){
	long long start = 1, end, ten = 1;
	cin >> end;
	while(start <= end){
		while(start % 10 != 0 && start <= end){
			calc(start, ten);
			++start;
		}
		if(start > end){
			break;
		}
		while(end % 10 != 9 && start <= end){
			calc(end, ten);
			--end;
		}
		long long cnt = end / 10 - start / 10 + 1;
		for(int i = 0; i < 10; ++i){
			ans[i] += cnt * ten;
		}
		start /= 10;
		end /= 10;
		ten *= 10;
	}
	for(int i = 0; i < 10; ++i){
		cout << ans[i] << ' ';
	}
	return 0;
}
