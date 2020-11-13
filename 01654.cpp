#include <cstdio>

bool enough(int required, long long* wires, int number, long long cut_length){
	long long sum = 0;
	for(int i = 0; i < number; ++i){
		sum += wires[i] / cut_length;
	}
	return sum >= required;
}

int main(){
	int k, n;
	scanf("%d %d", &k, &n);
	static long long wires[1000000];
	long long max = 1, min = 1;
	for(int i = 0; i < k; ++i){
		scanf("%lld", &wires[i]);
		if(max < wires[i]){
			max = wires[i];
		}
	}
	while(min < max){
		long long mid = (min + max + 1) / 2;
		if(enough(n, wires, k, mid)){
			min = mid;
		}else{
			max = mid-1;
		}
	}
	printf("%d", max);
	return 0;
}
