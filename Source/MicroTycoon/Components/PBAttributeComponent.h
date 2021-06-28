// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PBAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MICROTYCOON_API UPBAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	float GetBuildingTime() const;
	void OnBuildingEnded();
	float GetBuildingCost() const;
	UFUNCTION(BlueprintCallable)
	void Collect();
	UPBAttributeComponent();
	void UpdateResourceValue(float DeltaTime);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0.0f))
	float BuildingTime = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0.0f))
	float ResourceCapacity = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0.0f))
	float ProductionRate = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0.0f))
	float BuildingCost = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0.0f))
	float FillingPercent = 0.0f;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	bool bIsBuilding=true;
	float CurrentResourceValue = 0.0f;

		
};
