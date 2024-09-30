#include <stdio.h>

// テンプレート関数
template <typename Type>
Type Min(Type a, Type b) {
	if (a < b) {
		return static_cast<Type>(a);
	} else if (a > b) {
		return static_cast<Type>(b);
	}
}

// char 型専用の関数
template<>
const char* Min(const char* a, const char* b) {
	const char* point = "数字以外は代入できません";
	return point;
}

int main() {
	printf("%d\n", Min<int>(3, 9));
	printf("%f\n", Min<float>(7.0f, 4.0f));
	printf("%f\n", Min<double>(9.7, 9.8));
	printf("%s\n", Min<const char*>("は", "ひ"));

	return 0;
}
