#include <iostream>
#include <cstring>

using namespace std;

int lagrange(int squares[][200][4], int n, int prev, int square_cnt){
	if(n == 0){
		return 1;
	}else if(prev * prev > (1 << 15) || square_cnt >= 4){
		return 0;
	}
	if(squares[n][prev][square_cnt] != -1){
		return squares[n][prev][square_cnt];
	}
	squares[n][prev][square_cnt] = lagrange(squares, n, prev + 1, square_cnt);
	if(n - prev * prev >= 0){
		squares[n][prev][square_cnt] += lagrange(squares, n - prev * prev, prev, square_cnt + 1);
	}
	return squares[n][prev][square_cnt];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int squares[40000][200][4];
	memset(squares, -1, sizeof(squares));
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		cout << lagrange(squares, n, 1, 0) << "\n";
	}
	return 0;
}
