// Fill out your copyright notice in the Description page of Project Settings.
#ifndef SKILL_H
#define SKILL_H

#include <cstdint>

#pragma region Important Skill Defines

// -------------------------------------------------------------------------------------------------------------------- //
//	Defines that show what numerical value within the code will represent which skill in the game.						//
// -------------------------------------------------------------------------------------------------------------------- //

#define	SKILL_INVLAID			0x00000000u
#define	SKILL_FIRE_TEST			0x00000001u
#define	SKILL_WATER_TEST		0x00000002u
#define SKILL_EARTH_TEST		0x00000003u
#define SKILL_AIR_TEST			0x00000004u

// -------------------------------------------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------------------------------------------- //
//	Defines that show what each of the numerical values in the code represent as types for skills/characters.			//
// -------------------------------------------------------------------------------------------------------------------- //

#define TYPE_NONE				0x00u
#define TYPE_FIRE				0x01u
#define	TYPE_WATER				0x02u
#define	TYPE_AIR				0x03u
#define	TYPE_EARTH				0x04u

// -------------------------------------------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------------------------------------------- //
//	Defines for each of the flags stored within a given Skill struct instance's "flags" variable; allowing 32 unique	//
//	boolean values to be stored instead of the normal 1 out of 32 bits that would be stored when using "bool".			//
// -------------------------------------------------------------------------------------------------------------------- //

#define SKILL_CANT_MISS			0x00000001u	// Completely bypasses the accuracy check to ensure the skill will always hit the target.
#define	SKILL_MAKES_CONTACT		0x00000002u	// Determines use of Strength stat vs Magic stat during damage calculations.

// -------------------------------------------------------------------------------------------------------------------- //

#pragma endregion

#pragma region Skill Struct

class BattleManager;
struct Combatant;

struct Skill {
	uint32_t id;			// Allows the skill to keep track of the ID that it represents within the skill data structure.
	uint32_t power;			// Stores the base power of the skill that will be utilized in damage calculations during battle.
	uint32_t accuracy;		// Stores a value between 0 and 100 that determines the chance the attack will connect with a target.
	uint32_t critChance;	// Another value between 0 and 100 that determines the chance of this skill inflicting a critical hit.
	uint32_t type;			// Determines the type of damage that this skill will inflict on its target(s) (Ex. Fire, Water, Earth, etc.)
	uint32_t flags;			// Value storing 32 bits that can be toggled on or off to enable/disable different characteristics of a given skill.
	void(*USE_Function)(BattleManager* _manager, Combatant* _caster, Combatant* _target);
};

#pragma endregion

#endif