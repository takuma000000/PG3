#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	void Sound() override {
		printf("ニャーニャー\n");
	}
};
