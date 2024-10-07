#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>

//正解時の関数
void correct() {
	printf("正解です！\n");
}

//不正解時の関数
void incorrect() {
	printf("不正解です...\n");
}

//結果を表示するためのコールバック関数
void checkAnswer(bool isCorrect, void (*callback)()) {
	if (isCorrect) {
		callback = correct;
	} else {
		callback = incorrect;
	}
	callback();  //選択されたコールバック関数を実行
}

int main() {
	//ランダムシードを設定
	srand((unsigned int)time(NULL));

	//1から6のサイコロの目をランダムに生成
	int dice = rand() % 6 + 1;

	printf("サイコロを振りました！奇数か偶数かを当ててください。\n");
	printf("1: 奇数, 2: 偶数 ( 数字で入力 ) -> ");

	//ユーザーからの入力を受け取る
	int userGuess;
	scanf_s("%d", &userGuess);

	//サイコロの目が奇数かどうか
	bool isOdd = dice % 2 == 1;

	//ユーザーが正解かどうかを判定
	bool userIsCorrect = (userGuess == 1 && isOdd) || (userGuess == 2 && !isOdd);

	//3秒待つ
	printf("結果を待っています...\n");
	std::this_thread::sleep_for(std::chrono::seconds(3));

	//結果をコールバック関数で表示
	checkAnswer(userIsCorrect, correct);

	//サイコロの目を表示
	printf("サイコロの目は: %d でした。\n", dice);

	return 0;
}
