#include <stdio.h>
#include "MinClass.h"

int main() {

	MinClass<int> minInt;
	MinClass<float> minFloat;
	MinClass<double> minDouble;

	// 比較
	printf("Min(2, 16) = %d\n", minInt.Min(2, 16));
	printf("Min(7.0, 20.0) = %.1f\n", minFloat.Min(7.0f, 20.0f));
	printf("Min(1.2, 2.3) = %.1f\n", minDouble.Min(1.2, 2.3));

	return 0;
}