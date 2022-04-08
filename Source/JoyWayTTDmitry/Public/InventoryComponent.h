// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickupableItem.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JOYWAYTTDMITRY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		void NextItem();

	UFUNCTION(BlueprintCallable)
		void PrevItem();

	UFUNCTION(BlueprintCallable)
		void SelectItem(int Index);

	UFUNCTION(BlueprintCallable)
		void AddItem(APickupableItem* Item);

	UFUNCTION(BlueprintPure)
		TArray<TSubclassOf<APickupableItem>> GetItemsClasses();

	UFUNCTION(BlueprintPure)
		APickupableItem* GetCurrentItem();

	UFUNCTION(BlueprintPure)
		int GetCurrentItemIndex();
	
private:
	
	int SelectedItemIndex = 0;
	TArray<APickupableItem*> ItemsInInventory;
	TArray<TSubclassOf<APickupableItem>> ClassesInInventory;
};
