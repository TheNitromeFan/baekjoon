#include <cstdio>

int main(){
	int c, n;
	scanf("%d %d", &c, &n);
	int load = 0;
	bool possible = true;
	for(int i = 0; i < n; ++i){
		int leave, enter, stay;
		scanf("%d %d %d", &leave, &enter, &stay);
		load -= leave;
		if(load < 0){
			possible = false;
			break;
		}
		load += enter;
		if(load > c){
			possible = false;
			break;
		}
		if(stay > 0 && load < c){
			possible = false;
			break;
		}
	}
	if(load > 0){
		possible = false;
	}
	printf("%s", possible ? "possible" : "impossible");
	return 0;
}
