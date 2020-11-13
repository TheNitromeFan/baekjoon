#include <iostream>

int form_rects(int n){
	int cnt = 0;
	for(int p = 1; p*p <= n; ++p){
		if(n % p == 0){
			++cnt;
		}
	}
	return cnt;
}

int add_rects(int n){
	int total = 0;
	for(int i = 1; i <= n; ++i){
		total += form_rects(i);
	}
	return total;
}

int main(){
	int n;
	std::cin >> n;
	std::cout << add_rects(n);
	return 0;
}
