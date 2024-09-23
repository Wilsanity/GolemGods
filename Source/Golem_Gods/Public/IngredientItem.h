// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IngredientItem.generated.h"

/**
 * 
 */


UENUM(BlueprintType)
enum ItemType
{
	Item_Stone_Ore UMETA(DisplayName = "Stone Ore"),
	Item_Water_Gem UMETA(DisplayName = "Water Gem"),
	Item_Lava_Rock UMETA(DisplayName = "Lava Rock"),
	Item_Slime_Ball UMETA(DisplayName = "Slime Ball")
};


UCLASS(DefaultToInstanced, EditInLineNew, BlueprintType)
class GOLEM_GODS_API UIngredientItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere)
	TEnumAsByte<ItemType> IngredientType;
	



};
