// Fill out your copyright notice in the Description page of Project Settings.


#include "PBAttributeComponent.h"
#include "../GM_PlayerProperties.h"

void UPBAttributeComponent::OnBuildingEnded()
{
	bIsBuilding = false;
}

float UPBAttributeComponent::GetBuildingCost() const
{
	return BuildingCost;
}

void UPBAttributeComponent::Collect()
{
	StaticCast<AGM_PlayerProperties*>(GetWorld()->GetAuthGameMode())->Collect(CurrentResourceValue);
	CurrentResourceValue = 0.0f;
	FillingPercent = 0.0f;
}

UPBAttributeComponent::UPBAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UPBAttributeComponent::UpdateResourceValue(float DeltaTime)
{
	CurrentResourceValue += ProductionRate * DeltaTime;
	if (CurrentResourceValue > ResourceCapacity)
	{
		CurrentResourceValue = ResourceCapacity;
	}
	FillingPercent = CurrentResourceValue / ResourceCapacity;
}

void UPBAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!bIsBuilding)
	{
		UpdateResourceValue(DeltaTime);
	}
}

float UPBAttributeComponent::GetBuildingTime() const
{
	return BuildingTime;
}