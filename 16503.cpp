#include <cstdio>
#include <cstdlib>
#include <algorithm>

int add(int a, int b){
	return a + b;
}

int sub(int a, int b){
	return a - b;
}

int mul(int a, int b){
	return a * b;
}

int divide(int a, int b){
	if(a * b >= 0){
		return abs(a) / abs(b);
	}else{
		return -(abs(a) / abs(b));
	}
}

int main(){
	int k1, k2, k3;
	char o1, o2;
	scanf("%d %c %d %c %d", &k1, &o1, &k2, &o2, &k3);
	int ans1, ans2;
	switch(o1){
		case '+':
			ans1 = add(k1, k2);
			break;
		case '-':
			ans1 = sub(k1, k2);
			break;
		case '*':
			ans1 = mul(k1, k2);
			break;
		case '/':
			ans1 = divide(k1, k2);
			break;
	}
	switch(o2){
		case '+':
			ans1 = add(ans1, k3);
			break;
		case '-':
			ans1 = sub(ans1, k3);
			break;
		case '*':
			ans1 = mul(ans1, k3);
			break;
		case '/':
			ans1 = divide(ans1, k3);
			break;
	}
	switch(o2){
		case '+':
			ans2 = add(k2, k3);
			break;
		case '-':
			ans2 = sub(k2, k3);
			break;
		case '*':
			ans2 = mul(k2, k3);
			break;
		case '/':
			ans2 = divide(k2, k3);
			break;
	}
	switch(o1){
		case '+':
			ans2 = add(k1, ans2);
			break;
		case '-':
			ans2 = sub(k1, ans2);
			break;
		case '*':
			ans2 = mul(k1, ans2);
			break;
		case '/':
			ans2 = divide(k1, ans2);
			break;
	}
	if(ans1 > ans2){
		std::swap(ans1, ans2);
	}
	printf("%d\n%d", ans1, ans2);
	return 0;
}
