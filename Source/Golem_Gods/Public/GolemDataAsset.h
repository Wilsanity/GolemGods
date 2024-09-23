// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Golem_Gods/Public/IngredientItem.h"
#include "GolemDataAsset.generated.h"


/**
 * 
 */
UCLASS()
class GOLEM_GODS_API UGolemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	//Enum for class type (Attack, Defense, Support)
	//Function to set or get the attack type. Blueprint callable
	//FString Golem name (Get and Set)
	//Max Health (Get and Set)
	//Golem Parts (List of items that assembled Golem)
		//That means we need an item Data Asset
	//AttackDamage (Get and Set)

		//1. List of items needed to create this Golem	//Get
		//2. The 3D model to use for this Golem	//Get
		//3. The Material for this Golem	//Get
		//4. Maybe Max HP?	//Get
		//5. Default Name //Get


public:

protected:
	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte<ItemType>> IngredientItemList;

	UPROPERTY()
	int32 Testing;
};

UENUM(BlueprintType)
enum GolemCategoryType
{
	GolemCat_Offense UMETA(DisplayName = "Offense"),
	GolemCat_Defense UMETA(DisplayName = "Defense"),
	GolemCat_Support UMETA(DisplayName = "Support")
};

UENUM(BlueprintType)
enum GolemType
{
	GolemType_Stone UMETA(DisplayName = "Stone"),
	GolemType_Magma UMETA(DisplayName = "Magma"),
	GolemType_Water UMETA(DisplayName = "Water"),
	GolemType_Slime UMETA(DisplayName = "Slime")
};