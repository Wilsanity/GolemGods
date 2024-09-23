// Fill out your copyright notice in the Description page of Project Settings.

#include "DataManager.h"
#include "../GeneralData/Skill.h"
#include "../GeneralData/BaseCharacter.h"

#pragma region DataManager Constructor Definition

DataManager::DataManager() :
	skillData(),
	characterData()
{ // Reserve space for all required data structures.
	skillData.reserve(50);
	characterData.reserve(50);

	AddSkill(SKILL_FIRE_TEST, 30, 100, 5, TYPE_FIRE, 0, nullptr);
}

#pragma endregion

#pragma region Skill Data Management Functions

/// <summary>
/// 
/// </summary>
void DataManager::AddSkill(uint32_t _id, uint32_t _power, uint32_t _accuracy, uint32_t _critChance, uint32_t _type, uint32_t _flags,
								void(*_function)(BattleManager* _manager, Combatant* _caster, Combatant* _target)) {
	// Don't allow potential overwriting of existing skill data.
	if (skillData.find(_id) == skillData.end())
		return;

	// Create a new skill struct and then place it within the skill data map at the ID provided to the function.
	Skill _skill{};
	_skill.id			= _id;
	_skill.power		= _power;
	_skill.accuracy		= _accuracy;
	_skill.critChance	= _critChance;
	_skill.type			= _type;
	_skill.flags		= _flags;
	_skill.USE_Function = _function;

	skillData.emplace(_id, _skill);
}

/// <summary>
/// 
/// </summary>
/// <returns>A reference to the skill that was found with the matching ID value.</returns>
Skill& DataManager::GetSkill(uint32_t _skillID) {
	
}

/// <summary>
/// 
/// </summary>
void DataManager::RemoveSkill(uint32_t _skillID) {

}

#pragma endregion