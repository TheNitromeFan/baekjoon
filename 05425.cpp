#include <iostream>

using namespace std;

void calc(long long n, long long ten, long long &sum){
	while(n){
		sum += n % 10 * ten;
		n /= 10;
	}
}

long long digit_sum(long long end){
	long long start = 1, ten = 1;
	long long ret = 0;
	while(start <= end){
		while(start % 10 != 0 && start <= end){
			calc(start, ten, ret);
			++start;
		}
		if(start > end){
			break;
		}
		while(end % 10 != 9 && start <= end){
			calc(end, ten, ret);
			--end;
		}
		long long cnt = end / 10 - start / 10 + 1;
		for(int i = 0; i < 10; ++i){
			ret += i * cnt * ten;
		}
		start /= 10;
		end /= 10;
		ten *= 10;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long start, end;
		cin >> start >> end;
		cout << digit_sum(end) - digit_sum(start - 1) << '\n';
	}
	return 0;
}
