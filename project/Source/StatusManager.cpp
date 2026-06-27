#include "StatusManager.h"

int StatusManager::Php = 100;
int StatusManager::Ehp = 100;
int StatusManager::PAtack = 10;
int StatusManager::EAtack = 10;

void StatusManager::Damage(bool AtackCharacter //Player = 1, Enemy = 0
)
{

	switch (AtackCharacter) {
		
	case true:
		Ehp -= PAtack;
		break;

	case false:
		Php -= EAtack;
		break;

	}

}
