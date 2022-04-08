// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "PickupableItem.generated.h"

UCLASS(Abstract)
class JOYWAYTTDMITRY_API APickupableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupableItem();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool GiveItem(APawn* ReceivingPawn);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponPickup")
	UCapsuleComponent* CollisionVolume;

private:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool Equipped = false;

};
