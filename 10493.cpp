#include <cstdio>
#include <cstdlib>
#include <cmath>


double max(double a, double b){
	
	if(a > b) return a;
	else return b;
}

double min(double a, double b){
	
	if(a < b) return a;
	else return b;
}

double f(double x, double *c){
	
	return *c + *(c+1) * x + *(c+2) * x * x + *(c+3) * x * x * x;
}

double fit_quality(double *c){
	
	double maximum = max(f(0.0, c), f(1.0, c));
	double minimum = min(f(0.0, c), f(1.0, c));
	if(*(c+3) == 0.0 && *(c+2) == 0.0){
	}else if(*(c+3) == 0.0){
		double critical = -*(c+1) / (2 * *(c+2));
		if(critical > 0 && critical < 1){
			maximum = max(maximum, f(critical, c));
			minimum = min(minimum, f(critical, c));
		}
	}else if(*(c+2) * *(c+2) - 3 * *(c+3) * *(c+1) >= 0.0){
		double critical1 = (-*(c+2) - sqrt(*(c+2) * *(c+2) - 3 * *(c+3) * *(c+1))) / (3 * *(c+3));
		double critical2 = (-*(c+2) + sqrt(*(c+2) * *(c+2) - 3 * *(c+3) * *(c+1))) / (3 * *(c+3));
		if(critical1 > 0 && critical1 < 1){
			maximum = max(maximum, f(critical1, c));
			minimum = min(minimum, f(critical1, c));
		}
		if(critical2 > 0 && critical2 < 1){
			maximum = max(maximum, f(critical2, c));
			minimum = min(minimum, f(critical2, c));
		}
	}
	return maximum - minimum;
}

int main(void){
	
	double b[4], t[4];
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &b[0], &b[1], &b[2], &b[3], &t[0], &t[1], &t[2], &t[3]) != EOF){
		double *a = (double *)malloc(4 * sizeof(double));
		for(int i = 0; i < 4; i++) *(a+i) = t[i] - b[i];
		printf("%.16lf\n", fit_quality(a));
		free(a);
	}
	return 0;
}
