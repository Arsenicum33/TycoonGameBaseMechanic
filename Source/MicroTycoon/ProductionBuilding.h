// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PBAttributeComponent.h"
#include "ProductionBuilding.generated.h"

UCLASS()
class MICROTYCOON_API AProductionBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	AProductionBuilding();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UPBAttributeComponent* ProductionBuildingAttributeComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* BuildingStaticMeshComponent;
private:
	FTimerHandle BuildingTimer;
	void OnBuildingTimerExpired();

};
