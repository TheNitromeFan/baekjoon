#include <cstdio>

void roots(int a, int b, int c){
	for(int x1 = -100; x1 <= 100; ++x1){
		for(int x2 = -100; x2 <= 100; ++x2){
			if(a * (x1 + x2) == -b && a * x1 * x2 == c){
				if(x1 != x2
				&& (x1 == 2 || x1 == 4 || x1 == 8 || x1 == 16 || x1 == 32 || x1 == 64)
				&& (x2 == 2 || x2 == 4 || x2 == 8 || x2 == 16 || x2 == 32 || x2 == 64)){
					printf("�̼���");
				}else if(x1 != x2){
					printf("������");
				}else{
					printf("�Ѵ�Ʋ�ȱ�");
				}
				return;
			}
		}
	}
	printf("�Ѵ�Ʋ�ȱ�");
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	roots(a, b, c);
	return 0;
}
