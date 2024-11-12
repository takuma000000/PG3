#pragma once
#include "Animal.h"

class Baby : public Animal {
public:
	void Sound() override {
		printf("うﾞわﾞわﾞわﾞわﾞわﾞーﾞーﾞーﾞーﾞんﾞ\n");
	}
};

