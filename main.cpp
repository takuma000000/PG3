#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <functional> // std::function

int main() {
	// ランダムシードを設定
	srand((unsigned int)time(NULL));

	// サイコロを振る（1〜6のランダムな整数を生成）
	int dice = rand() % 6 + 1;

	// std::functionでゲームのロジックをラムダ式として定義
	std::function<void()> game = [&]() {
		printf("サイコロを振りました！奇数か偶数かを当ててください。\n");
		printf("1: 奇数, 2: 偶数 (数字で入力) -> ");

		// ユーザーの入力を受け取る
		int userGuess;
		scanf_s("%d", &userGuess);

		// サイコロの目が奇数かどうかを判定
		bool isOdd = dice % 2 == 1;
		bool userIsCorrect = (userGuess == 1 && isOdd) || (userGuess == 2 && !isOdd);

		// 3秒待つ
		printf("果たして正解は...!?\n");
		std::this_thread::sleep_for(std::chrono::seconds(3));

		// 結果を表示
		if (userIsCorrect) {
			printf("正解！\n");
		} else {
			printf("不正解...\n");
		}

		// サイコロの出目を表示
		printf("サイコロの目は: %d でした。\n", dice);
	};

	// ゲームを実行
	game();

	return 0;
}
