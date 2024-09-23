// Fill out your copyright notice in the Description page of Project Settings.
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <cstdint>

#pragma region Important Character Defines

// -------------------------------------------------------------------------------------------------------------------- //
//	Defines that show which indices in the BaseCharacter's "stat" array represent what stat within the actual game.		//
// -------------------------------------------------------------------------------------------------------------------- //

#define	STAT_STRENGTH			0x00u
#define STAT_MAGIC				0x01u
#define STAT_ENDURANCE			0x02u
#define STAT_INTELLIGENCE		0x03u
#define STAT_AGILITY			0x04u
#define STAT_LUCK				0x05u
#define MAJOR_STAT_COUNT		0x06u		// Simply stores the total number of major stat each character hasas a convenient macro.

// -------------------------------------------------------------------------------------------------------------------- //

#pragma endregion

struct BaseCharacter {
	BaseCharacter(uint32_t _id, uint32_t _level, uint32_t _variance, uint32_t _baseStat[MAJOR_STAT_COUNT]) :
		id(_id),
		level(_level),
		variance(_variance)
	{ // Calculates the character's maximum HP and MP upon creation
		for (uint32_t i = 0u; i < MAJOR_STAT_COUNT; i++) // Perform initial major stat calculation.
			stat[i]		= (_baseStat[i] * 2 * _level / 50) + 5;

		// Then, calculate the maximum HP and MP for the character (Variance is applied later and differently depending on if the character
		// is an enemy or a party member for the player). The current HP and MP are set at the same time the variance value is applied.
		maxHitpoints	= (stat[STAT_ENDURANCE] * 3) + (level * 2) + 10;
		maxMagicpoints	= (stat[STAT_MAGIC] * 3) + (level * 2) + 10;
	}

	uint32_t id;							// Allows a character to know what ID value it represents within the character data structure.
	uint32_t level;							// Represents the overall quality of a character, which is used to determine its stats through formulas.
	uint32_t variance;						// Determines the percent range of possible stats based on the calculated stats of the character.
	uint32_t maxHitpoints, maxMagicpoints;	// Stores the character's maximum hitpoints and magicpoints, respectively.
	uint32_t curHitpoints, curMagicpoints;	// Stores the current hitpoints and magicpoints available to the character.
	uint32_t stat[MAJOR_STAT_COUNT];		// An array that stores the values for each of the character's six major stat values.
};

#endif