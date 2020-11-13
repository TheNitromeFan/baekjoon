#include <iostream>

using namespace std;

long long step(int size, int row, int col){
	if(size == 0){
		return 0;
	}
	if(row < (1 << (size - 1)) && col < (1 << (size - 1))){
		return step(size-1, row, col);
	}else if(row < (1 << (size - 1))){
		return step(size-1, row, col - (1 << (size - 1))) + (1 << (2 * (size - 1)));
	}else if(col < (1 << (size - 1))){
		return step(size-1, row - (1 << (size - 1)), col) + (2 << (2 * (size - 1)));
	}else{
		return step(size-1, row - (1 << (size - 1)), col - (1 << (size - 1))) + (3 << (2 * (size - 1)));
	}
}

int main(){
	int n, r, c;
	cin >> n >> r >> c;
	cout << step(n, r, c) << endl;
	return 0;
}
