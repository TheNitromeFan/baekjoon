#include <cstdio>
#include <vector>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	std::vector<int> v;
	for(int i = 1; i <= n; ++i){
		v.push_back(i);
	}
	printf("<");
	int current = k-1;
	int survivors = n;
	while(true){
		printf("%d", v[current]);
		v.erase(v.begin() + current);
		--survivors;
		if(survivors == 0){
			break;
		}
		printf(", ");
		current = (current + k-1) % survivors;
	}
	printf(">");
	return 0;
}
