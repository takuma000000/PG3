#include <stdio.h>
#include "IShape.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
	// Circle、Rectangleオブジェクト作成
	Circle circle(5.0);
	Rectangle rectangle(4.0, 3.0);

	// Circleの面積、描画
	circle.Size();
	circle.Draw();

	// Rectangleの面積、描画
	rectangle.Size();
	rectangle.Draw();

	return 0;
}