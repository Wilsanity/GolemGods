// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleManager.h"
#include "../GeneralData/Skill.h"

#pragma region Battle Manager Constructor and Destructor

BattleManager::BattleManager() :
	combatants(),
	turnOrder(),
	partyIndices(),
	enemyIndices() 
{ // Reserve space for all required data structures.
	combatants.reserve(10);
	turnOrder.reserve(10);
	partyIndices.reserve(3);
	enemyIndices.reserve(3);
}

BattleManager::~BattleManager() 
{}

#pragma endregion

#pragma region Battle Manager Initialization Functions

/// <summary>
/// 
/// </summary>
void BattleManager::BattleInitialize() {
	
}

#pragma endregion

#pragma region Battle Manager Turn Loop Functions

/// <summary>
///	Organizes the current turn order based on the current speed values of each Combatant; called at the start of each turn loop until the battle
/// has either been lost, won, or the player has successfully escaped from the battle prematurely.
/// </summary>
void BattleManager::SetTurnOrder() {

}

#pragma endregion

#pragma region Combatant Helper Functions

void BattleManager::UpdateBattleStat(Combatant* _combatant, uint32_t _stat, int32_t _modifier) {
	if (_stat >= BATTLE_STAT_COUNT)
		return;
}

#pragma endregion