#include <stdio.h>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Baby.h"

int main() {
	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();
	Animal* animal3 = new Baby();

	printf("\nいぬ:　\n");
	animal1->Sound();

	printf("\nねこ:　\n");
	animal2->Sound();

	printf("\n赤さん:　\n");
	animal3->Sound();

	// メモリ解放
	delete animal1;
	delete animal2;
	delete animal3;

	return 0;
}