#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		char ion[4], equals[4];
		double concentration;
		scanf("%s %s %lf", ion, equals, &concentration);
		double ph;
		if(ion[0] == 'H'){
			ph = -log10(concentration);
		}else{
			ph = 14 + log10(concentration);
		}
		printf("%.2f\n", ph);
	}
}
