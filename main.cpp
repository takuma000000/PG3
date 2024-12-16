#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;  // ミューテックス
std::condition_variable cv;  // 条件変数
int currentThread = 1;  // 現在のスレッド順

// thread 1 の処理
void thread1() {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [] { return currentThread == 1; });  // 順番が来るのを待つ
	printf("thread 1\n");
	currentThread = 2;  // 次のスレッドに移行
	cv.notify_all();  // 全てのスレッドを通知
}

// thread 2 の処理
void thread2() {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [] { return currentThread == 2; });
	printf("thread 2\n");
	currentThread = 3;
	cv.notify_all();
}

// thread 3 の処理
void thread3() {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [] { return currentThread == 3; });
	printf("thread 3\n");
	cv.notify_all();
}

int main() {
	// 3つのスレッドを作成
	std::thread t1(thread1);
	std::thread t2(thread2);
	std::thread t3(thread3);

	// スレッドの終了を待機
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
