#include <iostream>

using namespace std;

int power_to_bill(int power){
	int ret = 0;
	if(power <= 100){
		ret += 2 * power;
		return ret;
	}else{
		ret += 2 * 100;
	}
	if(power <= 10000){
		ret += 3 * (power - 100);
		return ret;
	}else{
		ret += 3 * (10000 - 100);
	}
	if(power <= 1000000){
		ret += 5 * (power - 10000);
		return ret;
	}else{
		ret += 5 * (1000000 - 10000);
	}
	ret += 7 * (power - 1000000);
	return ret;
}

int bill_to_power(int bill){
	int ret = 0;
	if(bill <= 2 * 100){
		ret += bill / 2;
		return ret;
	}else{
		ret += 100;
	}
	bill -= 2 * 100;
	if(bill <= 3 * (10000 - 100)){
		ret += bill / 3;
		return ret;
	}else{
		ret += 10000 - 100;
	}
	bill -= 3 * (10000 - 100);
	if(bill <= 5 * (1000000 - 10000)){
		ret += bill / 5;
		return ret;
	}else{
		ret += 1000000 - 10000;
	}
	bill -= 5 * (1000000 - 10000);
	ret += bill / 7;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int a, b;
		cin >> a >> b;
		if(a == 0 && b == 0){
			break;
		}
		int total_power = bill_to_power(a);
		int low = 0, high = total_power / 2;
		int x, y;
		int c, d;
		while(low <= high){
			int mid = (low + high) / 2;
			x = mid;
			y = total_power - mid;
			c = power_to_bill(x);
			d = power_to_bill(y);
			if(d - c == b){
				break;
			}else if(d - c > b){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		cout << c << '\n';
	}
	return 0;
}
