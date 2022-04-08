// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupableItem.h"

// Sets default values
APickupableItem::APickupableItem()
{
	RootComponent = CollisionVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionVolume"));
	CollisionVolume->InitCapsuleSize(80.f, 80.f);
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &APickupableItem::OnOverlapBegin);
}

void APickupableItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	APawn* OverlappingPawn = Cast<APawn>(OtherActor);
	if (OverlappingPawn != nullptr)
	{
		GiveItem(OverlappingPawn);
	}
}

