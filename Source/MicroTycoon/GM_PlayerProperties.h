// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_PlayerProperties.generated.h"

/**
 * 
 */
UCLASS()
class MICROTYCOON_API AGM_PlayerProperties : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void Collect(float Value);

	UFUNCTION(BlueprintCallable)
	void Spend(float Value);

	UFUNCTION(BlueprintCallable)
	float GetPlayerResourceValue() const;
private:
	float PlayerResourceValue = 100.0f;
};
