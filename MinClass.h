#pragma once
#include <cstdio>

template <typename T>
class MinClass {
public:
	// 2‚Â‚Ìˆø”‚Ì‚¤‚¿¬‚³‚¢’l‚ğ•Ô‚·
	T Min(T a, T b) {
		if (a < b) {
			return a;
		} else {
			return b;
		}
	}
};