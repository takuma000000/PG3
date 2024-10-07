#include <stdio.h>

//再帰的な賃金
int Recursive(int n) {
	//最初の1時間の時給は100円
	if (n == 1) {
		return 100;
	}
	//次の時間は前の時給 * 2 - 50円
	return Recursive(n - 1) * 2 - 50;
}

//再帰的な賃金の合計
int TotalRecursive(int n) {
	if (n == 1) {
		return Recursive(1); //最初の時間の時給
	}
	//各時間の時給を合計
	return Recursive(n) + TotalRecursive(n - 1);
}

int main() {

	//一般的な賃金体系
	int general = 1072;
	//再帰的
	int recursive;

	//時間
	int time = 8;

	recursive = TotalRecursive(time);

	printf("一般的な賃金体系の合計: %d\n", general * time);//一般的な賃金体系の合計
	printf("再帰的な賃金体系の合計: %d\n", recursive);//再帰的な賃金体系の合計
	printf("\n'8'時間働くと、再帰的な賃金体系の方が儲かる\n");

	return 0;
}