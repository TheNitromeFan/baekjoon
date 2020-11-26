#include <cstdio>

int main(){
	char line[257];
	int dec[256] = {};
	char hex[256] = {};
	for(int i = 0; i < 10; ++i){
		dec[i + '0'] = i;
		hex[i] = i + '0';
	}
	for(int i = 10; i < 16; ++i){
		dec[i - 10 + 'A'] = i;
		hex[i] = i - 10 + 'A';
	}
	while(scanf("%s", line) == 1){
		if(line[0] == '8'){
			break;
		}
		int idx = 0;
		int mem[256] = {};
		for(int i = 0; i < 256; ++i){
			mem[i] = dec[line[i]];
		}
		int a = 0, b = 0;
		while(true){
			char c = line[idx];
			if(c == '0'){
				a = mem[16 * dec[line[idx + 1]] + dec[line[idx + 2]]];
				idx += 3;
			}else if(c == '1'){
				mem[16 * dec[line[idx + 1]] + dec[line[idx + 2]]] = a;
				idx += 3;
				
			}else if(c == '2'){
				int tmp = b;
				b = a;
				a = tmp;
				++idx;
			}else if(c == '3'){
				int sum = a + b;
				a = sum % 16;
				b = sum / 16;
				++idx;
			}else if(c == '4'){
				a = (a + 1) % 16;
				++idx;
			}else if(c == '5'){
				a = (a + 15) % 16;
				++idx;
			}else if(c == '6'){
				int address = 16 * dec[line[idx + 1]] + dec[line[idx + 2]];
				if(a == 0){
					idx = address;
				}else{
					idx += 3;
				}
			}else if(c == '7'){
				idx = 16 * dec[line[idx + 1]] + dec[line[idx + 2]];
			}else if(c == '8'){
				break;
			}
		}
		for(int i = 0; i < 256; ++i){
			printf("%c", hex[mem[i]]);
		}
		printf("\n");
	}
	return 0;
}
