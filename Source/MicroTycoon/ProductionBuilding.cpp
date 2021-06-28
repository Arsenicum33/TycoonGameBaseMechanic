// Fill out your copyright notice in the Description page of Project Settings.


#include "ProductionBuilding.h"

// Sets default values
AProductionBuilding::AProductionBuilding()
{
	ProductionBuildingAttributeComponent = CreateDefaultSubobject<UPBAttributeComponent>(TEXT("AttributeComponent"));
	BuildingStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	BuildingStaticMeshComponent->SetupAttachment(RootComponent);
}

void AProductionBuilding::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	GetWorld()->GetTimerManager().SetTimer(BuildingTimer, this, &AProductionBuilding::OnBuildingTimerExpired, ProductionBuildingAttributeComponent->GetBuildingTime(), false);
}

void AProductionBuilding::OnBuildingTimerExpired()
{
	ProductionBuildingAttributeComponent->OnBuildingEnded();
}

