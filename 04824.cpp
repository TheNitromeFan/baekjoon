#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	while(true){
		double a[3];
		for(int i = 0; i < 3; ++i){
			scanf("%lf", &a[i]);
		}
		if(a[0] == 0 && a[1] == 0 && a[2] == 0){
			break;
		}
		sort(a, a + 3, greater<int>());
		if(a[0] >= 125 && a[0] <= 290 && a[1] >= 90 && a[1] <= 155 && a[2] >= 0.25 && a[2] <= 7){
			printf("letter\n");
		}else if(((a[0] > 290 && a[1] >= 90 && a[2] >= 0.25)
		|| (a[0] >= 125 && a[1] > 155 && a[2] >= 0.25)
		|| (a[0] >= 125 && a[1] >= 90 && a[2] > 7))
		&& a[0] <= 380 && a[1] <= 300 && a[2] <= 50){
			printf("packet\n");
		}else if(((a[0] > 380 && a[1] >= 90 && a[2] >= 0.25)
		|| (a[0] >= 125 && a[1] > 300 && a[2] >= 0.25)
		|| (a[0] >= 125 && a[1] >= 90 && a[2] > 50))
		&& a[0] + 2 * a[1] + 2 * a[2] <= 2100){
			printf("parcel\n");
		}else{
			printf("not mailable\n");
		}
	}
	return 0;
}
