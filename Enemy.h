#pragma once
#include <cstdio>

// EnemyƒNƒ‰ƒX’è‹`
class Enemy {
public:
	// ó‘Ô‚ğ•\‚·—ñ‹“Œ^
	enum Phase {
		APPROACH,// Ú‹ß
		ATTACK,// ËŒ‚
		ESCAPE// —£’E
	};

	Enemy() : currentPhase(APPROACH) {}

	// ó‘Ô‘JˆÚŠÖ”
	void ChangePhase() {
		(this->*phaseFunctions[currentPhase])();
	}

	// ó‘Ô‚Ì•ÏX
	void NextPhase() {
		currentPhase = static_cast<Phase>((currentPhase + 1) % 3);
	}

private:
	Phase currentPhase;
	void (Enemy::* phaseFunctions[3])() = {
		&Enemy::Approach,
		&Enemy::Attack,
		&Enemy::Escape,
	};

	// ó‘Ô‚²‚Æ‚Ìˆ—
	void Approach() {
		printf("Ú‹ß\n");
		NextPhase();
	}

	void Attack() {
		printf("ËŒ‚\n");
		NextPhase();
	}

	void Escape() {
		printf("—£’E\n");
		NextPhase();
	}
};
