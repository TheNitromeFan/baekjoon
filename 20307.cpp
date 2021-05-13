#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

class Fraction{
	public:
		long long num, den;
		void getvalue(long long n, long long d){
			num = n;
			den = d;
		}
		void getvalue(string x){
			size_t pos = x.find("/");
			if(pos == string::npos){
				num = stoll(x);
				den = 1;
			}else{
				num = stoll(x.substr(0, pos));
				den = stoll(x.substr(pos + 1, string::npos));
			}
		}
		void print(){
			if(num == 0 || den == 1){
				cout << num;
			}else{
				cout << num << "/" << den;
			}
		}
		void simplify(){
			if(den < 0){
				num *= -1;
				den *= -1;
			}
			long long g = gcd(llabs(num), llabs(den));
			num /= g;
			den /= g;
		}
		void add(Fraction rhs){
			getvalue(num * rhs.den + rhs.num * den, den * rhs.den);
			simplify();
		}
		void multiply(Fraction rhs){
			getvalue(num * rhs.num, den * rhs.den);
			simplify();
		}
};

void scale_row(Fraction matrix[][5], int n, int m, int row, Fraction alpha){
	for(int j = 0; j < m; ++j){
		matrix[row][j].multiply(alpha);
	}
}

void swap_rows(Fraction matrix[][5], int n, int m, int row1, int row2){
	for(int j = 0; j < m; ++j){
		swap(matrix[row1][j], matrix[row2][j]);
	}
}

void replace_row(Fraction matrix[][5], int n, int m, int row1, int row2, Fraction alpha){
	for(int j = 0; j < m; ++j){
		Fraction f;
		f.getvalue(-alpha.num, alpha.den);
		f.multiply(matrix[row2][j]);
		matrix[row1][j].add(f);
	}
}

int locate_nonzero_entry(Fraction matrix[][5], int n, int m, int col, int row1){
	for(int row = row1; row < n; ++row){
		if(matrix[row][col].num != 0){
			return row;
		}
	}
	return -1;
}

void print_matrix(Fraction matrix[][5], int n, int m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			matrix[i][j].print();
			cout << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Fraction matrix[5][5];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			string x;
			cin >> x;
			matrix[i][j].getvalue(x);
		}
	}
	int col = 0;
	for(int i = 0; i < n; ++i){
		int row = locate_nonzero_entry(matrix, n, m, col, i);
		while(row == -1){
			++col;
			if(col >= m){
				break;
			}
			row = locate_nonzero_entry(matrix, n, m, col, i);
		}
		if(col >= m){
			break;
		}
		swap_rows(matrix, n, m, row, i);
		Fraction f;
		f.getvalue(matrix[i][col].den, matrix[i][col].num);
		scale_row(matrix, n, m, i, f);
		for(int r = 0; r < n; ++r){
			if(r == i){
				continue;
			}
			replace_row(matrix, n, m, r, i, matrix[r][col]);
		}
		// print_matrix(matrix, n, m);
	}
	print_matrix(matrix, n, m);
	return 0;
}
