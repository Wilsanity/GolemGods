// Fill out your copyright notice in the Description page of Project Settings.
#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "CoreMinimal.h"
#include <vector>

#pragma region Battle Manager Class

// -------------------------------------------------------------------------------------------------------------------- //
//	
// -------------------------------------------------------------------------------------------------------------------- //

#define	STAT_MINIMUM_LIMIT	   -2
#define STAT_MAXIMUM_LIMIT		2

// -------------------------------------------------------------------------------------------------------------------- //

struct Combatant;

class GOLEM_GODS_API BattleManager {
public: // Default Constructor and Destructor
	BattleManager();
	~BattleManager();
private:

// -------------------------------------------------------------------------------------------------------------------- //
//	Battle State Functions																								//
// -------------------------------------------------------------------------------------------------------------------- //

	void BattleInitialize();	// <-- Called at the very beginning of the battle to set up Combatants.

	void SetTurnOrder();		// <-- Start of the main turn loop; determines turn order for next loop of battle.
	void DetermineNextTurn();	//		Check if an enemy or a player are going next.
	void ExecutePlayerTurn();	//			Perform a player character's turn.
	void ExecuteEnemyTurn();	//			Execute the script for the enemy's turn AI.
	void EndSubTurn();			// <-- End of "subturn" loop; if loop is finished, return to top of the loop. Otherwise, return to "DetermineNextTurn" and continue.

	void BattleEscape();		// <-- Player successfully escaped from battle; end without them receiving any rewards.
	void BattleLose();			// <-- Player's team was completely wiped out; move to game over state.
	void BattleWin();			// <-- Player's team defeated all enemies; give out rewards for winning and return to regular gameplay.

// -------------------------------------------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------------------------------------------- //
//	Combatant Modification Functions																					//
// -------------------------------------------------------------------------------------------------------------------- //

	// Applies a given modifier to one of the five Combatant battle stats; reseting that stat's duration back its default maximum unless the stat is set back to 0.
	void UpdateBattleStat(Combatant* _combatant, uint32_t _stat, int32_t _modifier);

// -------------------------------------------------------------------------------------------------------------------- //

public:
	std::vector<Combatant*>	combatants;		// Pointers to reference all Combatants within the battle; both alive and dead.
	std::vector<uint32_t>	turnOrder;		// Stores indices that reference the combatants currently within the turn order.
	std::vector<uint32_t>	partyIndices;	// Stores indices that point to player party combatants.
	std::vector<uint32_t>	enemyIndices;	// Stores indices that point to enemy combatants.
private:
	
};

#pragma endregion

#pragma region Combatant Struct

// -------------------------------------------------------------------------------------------------------------------- //
//	Macros to represent what each index into the Combatant's "battleStat" represents within a battle. The first group	//
//	is for the 1st dimension of the array, and the second group is for the 2nd dimension so the 0 and 1 are replaced	//
//	with what those two rows contain within the array.																	//
// -------------------------------------------------------------------------------------------------------------------- //

#define STAT_ATTACK				0x00u
#define STAT_DEFENSE			0x01u
#define	STAT_ACCURACY			0x02u
#define STAT_EVASION			0x03u
#define STAT_SPEED				0x04u
#define BATTLE_STAT_COUNT		0x05u		// <-- Stores total number of battle stats which is also the width of the array.

#define STAT_CURRENT_VALUE		0x00u
#define STAT_REMAINING_TURNS	0x01u

// -------------------------------------------------------------------------------------------------------------------- //

struct Combatant {
	int32_t battleStat[BATTLE_STAT_COUNT][2];	// 5 by 2 array to track current stat value and turn counter for stat's remaining duration.
	uint32_t speedBase;							// Stores the character's base speed value which is calculated at the start of the battle.
};

#pragma endregion

#endif