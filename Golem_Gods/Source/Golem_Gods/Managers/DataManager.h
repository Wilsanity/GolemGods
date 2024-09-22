// Fill out your copyright notice in the Description page of Project Settings.
#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "CoreMinimal.h"

#include <unordered_map>

#pragma region Important Data Manager Defines

#define MAJOR_STAT_COUNT		0x06u

#pragma endregion

#pragma region Data Manager Class

class BattleManager;
struct Combatant;

struct Skill;
struct BaseCharacter;

class GOLEM_GODS_API DataManager {
public: // Singleton reference function for the DataManager class.
	static DataManager& GetInstance() {
		static DataManager instance;
		return instance;
	}

public: // Constructor declaration and more Singleton setup.
	DataManager();
	DataManager(const DataManager&) = delete;
	void operator=(const DataManager&) = delete;

public:

// -------------------------------------------------------------------------------------------------------------------- //
//	Skill data management functions																						//
// -------------------------------------------------------------------------------------------------------------------- //

	void AddSkill(uint32_t _id, uint32_t _power, uint32_t _accuracy, uint32_t _critChance, uint32_t _type, uint32_t _flags, 
						void(*_function)(BattleManager* _manager, Combatant* _caster, Combatant* _target));
	Skill& GetSkill(uint32_t _skillID);
	void RemoveSkill(uint32_t _skillID);

// -------------------------------------------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------------------------------------------- //
//	Character data management functions																					//
// -------------------------------------------------------------------------------------------------------------------- //

	void AddCharacter(uint32_t _id, uint32_t _level, uint32_t _variance, uint32_t _baseStats[MAJOR_STAT_COUNT]);
	BaseCharacter& GetCharacter(uint32_t _characterID);
	void RemoveCharacter(uint32_t _characterID);

// -------------------------------------------------------------------------------------------------------------------- //

public:
	std::unordered_map<uint32_t, Skill> skillData;					// Stores all currently loaded Skill structs.
	std::unordered_map<uint32_t, BaseCharacter> characterData;		// Stores all currently loaded party/enemy character structs.
};

#pragma endregion

#endif