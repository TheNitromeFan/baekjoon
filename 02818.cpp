#include <cstdio>
#include <algorithm>

int main(){
	int top = 1, front = 2, right = 3, left = 4, back = 5, bottom = 6;
	int r, c;
	scanf("%d %d", &r, &c);
	long long sum = 0, tmp;
	int i = 1;
	while(true){
		sum += (top + left + bottom + right) * ((c - 1) / 4);
		for(int j = 1; j < (c - 1) % 4 + 1; ++j){
			sum += top;
			tmp = top;
			top = left;
			left = bottom;
			bottom = right;
			right = tmp;
		}
		sum += top;
		tmp = top;
		top = back;
		back = bottom;
		bottom = front;
		front = tmp;
		++i;
		if(i > r){
			break;
		}
		sum += (top + right + bottom + left) * ((c - 1) / 4);
		for(int j = 1; j < (c - 1) % 4 + 1; ++j){
			sum += top;
			tmp = top;
			top = right;
			right = bottom;
			bottom = left;
			left = tmp;
		}
		sum += top;
		tmp = top;
		top = back;
		back = bottom;
		bottom = front;
		front = tmp;
		++i;
		if(i > r){
			break;
		}
	}
	printf("%lld", sum);
	return 0;
}
