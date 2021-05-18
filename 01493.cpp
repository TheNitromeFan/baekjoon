#include <iostream>
#define MAX 21

using namespace std;

int f(int cubes[MAX], long long length, long long width, long long height, bool &found){
	if(length == 0 || width == 0 || height == 0){
		return 0;
	}
	int i = 0;
	long long j = 1;
	while(j < length && j < width && j < height){
		++i;
		j <<= 1;
	}
	for(; i >= 0; --i, j >>= 1){
		if(cubes[i] == 0){
			continue;
		}
		--cubes[i];
		int x = f(cubes, length - j, j, height, found);
		int y = f(cubes, length, width - j, height, found);
		int z = f(cubes, j, j, height - j, found);
		return x + y + z + 1;
	}
	found = false;
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long length, width, height;
	int n;
	cin >> length >> width >> height >> n;
	int cubes[MAX] = {};
	for(int i = 0; i < n; ++i){
		int ai, bi;
		cin >> ai >> bi;
		cubes[ai] = bi;
	}
	bool found = true;
	int ans = f(cubes, length, width, height, found);
	if(found){
		cout << ans;
	}else{
		cout << -1;
	}
	return 0;
}
