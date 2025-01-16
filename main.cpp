#include <cstdio>
#include <string>
#include <chrono>

int main() {
	// 100,000文字の文字列を初期化
	std::string a(100000, 'a');

	// コピーにかかる時間を計測
	auto start_copy = std::chrono::high_resolution_clock::now();
	std::string b = a; // コピー
	auto end_copy = std::chrono::high_resolution_clock::now();
	auto copy_time = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

	// 移動にかかる時間を計測
	auto start_move = std::chrono::high_resolution_clock::now();
	std::string c = std::move(a); // 移動
	auto end_move = std::chrono::high_resolution_clock::now();
	auto move_time = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

	// 結果を表示
	printf("100,000文字を移動とコピーで比較しました。\n");
	printf("コピー: %lldus\n", copy_time); // マイクロ秒で出力
	printf("移動: %lldus\n", move_time); // マイクロ秒で出力

	// 続行待ち
	printf("続行するには何かキーを押してください・・・\n");
	getchar(); // コンソールを閉じないための入力待ち

	return 0;
}
