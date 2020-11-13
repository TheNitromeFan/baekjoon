#include <cstdio>

int main(){
	while(true){
		long long a[4];
		for(int i = 0; i < 4; ++i){
			scanf("%lld", &a[i]);
		}
		long long x;
		if(a[0] == -1 && a[1] == -1 && a[2] == -1 && a[3] == -1){
			break;
		}else if(a[0] == -1){
			if(a[2] % a[1] == 0 && a[2] * a[2] == a[1] * a[3]){
				if(a[1] * a[1] % a[2] != 0){
					x = -1;
				}else{
					x = a[1] * a[1] / a[2];
					if(x > 10000){
						x = -1;
					}
				}
			}else if(2 * a[2] == a[1] + a[3]){
				x = 2 * a[1] - a[2];
				if(x <= 0 || x > 10000){
					x = -1;
				}
			}else{
				x = -1;
			}
		}else if(a[1] == -1){
			if(a[3] % a[2] == 0 && a[2] * a[2] * a[2] == a[0] * a[3] * a[3]){
				if(a[2] * a[2] % a[3] != 0){
					x = -1;
				}else{
					x = a[2] * a[2] / a[3];
					if(x > 10000){
						x = -1;
					}
				}
			}else if(3 * a[2] == a[0] + 2 * a[3]){
				x = 2 * a[2] - a[3];
			}else{
				x = -1;
			}
		}else if(a[2] == -1){
			if(a[1] % a[0] == 0 && a[1] * a[1] * a[1] == a[0] * a[0] * a[3]){
				if(a[1] * a[1] % a[0] != 0){
					x = -1;
				}else{
					x = a[1] * a[1] / a[0];
					if(x > 10000){
						x = -1;
					}
				}
			}else if(3 * a[1] == 2 * a[0] + a[3]){
				x = 2 * a[1] - a[0];
			}else{
				x = -1;
			}
		}else if(a[3] == -1){
			if(a[1] % a[0] == 0 && a[1] * a[1] == a[0] * a[2]){
				if(a[2] * a[2] % a[1] != 0){
					x = -1;
				}else{
					x = a[2] * a[2] / a[1];
					if(x > 10000){
						x = -1;
					}
				}
			}else if(2 * a[1] == a[0] + a[2]){
				x = 2 * a[2] - a[1];
				if(x <= 0 || x > 10000){
					x = -1;
				}
			}else{
				x = -1;
			}
		}
		printf("%lld\n", x);
	}
	return 0;
}
