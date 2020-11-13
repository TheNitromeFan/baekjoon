#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	while(true){
		int call, data;
		scanf("%d %d", &call, &data);
		if(call == 0 && data == 0){
			break;
		}
		printf("%d\n", min(min(30 * call + 40 * data, 35 * call + 30 * data), 40 * call + 20 * data));
	}
	return 0;
}
