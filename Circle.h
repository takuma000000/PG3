#pragma once
#include <stdio.h>
#include "IShape.h"
#define _USE_MATH_DEFINES
#include <math.h>


class Circle : public IShape {
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	void Size() override {
		double area = M_PI * radius * radius;
		printf("\nCircle‚Ì–ÊÏ: %.2f\n", area);
	}

	void Draw() override {
		printf("Circle‚ğ•`‰æ\n");
	}
};
