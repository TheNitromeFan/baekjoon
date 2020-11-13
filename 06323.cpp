#include <cstdio>
#include <cmath>

int main(){
	int sample = 0;
	while(true){
		int w, d;
		scanf("%d %d", &w, &d);
		if(w == 0 && d == 0){
			break;
		}
		++sample;
		double age = log2(810.0 * w / d) * 5730;
		int approx = 0;
		if(age < 10000){
			int r = (int)(age / 100) * 100;
			if(age - r < r + 100 - age){
				approx = r;
			}else{
				approx = r + 100;
			}
		}else{
			int r = (int)(age / 1000) * 1000;
			if(age - r < r + 1000 - age){
				approx = r;
			}else{
				approx = r + 1000;
			}
		}
		printf("Sample #%d\nThe approximate age is %d years.\n\n", sample, approx);
	}
	return 0;
}
