#pragma once
#include <stdio.h>
#include "IShape.h"

class Rectangle : public IShape {
private:
	double width, height;

public:
	Rectangle(double w, double h) : width(w), height(h) {}

	void Size() override {
		double area = width * height;
		printf("\nRectangle‚Ì–ÊÏ: %.2f\n", area);
	}

	void Draw() override {
		printf("Rectangle‚ğ•`‰æ\nRectangle: ‹éŒ`\n");
	}
};
