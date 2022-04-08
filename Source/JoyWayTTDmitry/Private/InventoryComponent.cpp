// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

void UInventoryComponent::NextItem()
{
	if (ItemsInInventory.Num() > 1)
	{
		if (SelectedItemIndex + 1 >= ItemsInInventory.Num())
		{
			SelectItem(0);
		}
		else
			SelectItem(SelectedItemIndex + 1);
	}
}

void UInventoryComponent::PrevItem()
{
	if (ItemsInInventory.Num() > 1)
	{
		if (SelectedItemIndex - 1 < 0)
		{
			SelectItem(ItemsInInventory.Num() - 1);
		}
		else
			SelectItem(SelectedItemIndex - 1);
	}
}

void UInventoryComponent::SelectItem(int Index)
{
	ItemsInInventory[SelectedItemIndex]->SetActorHiddenInGame(true);
	ItemsInInventory[Index]->SetActorHiddenInGame(false);
	SelectedItemIndex = Index;
}

void UInventoryComponent::AddItem(APickupableItem* Item)
{
	if (!ClassesInInventory.Contains(Item->GetClass()))
	{
		ClassesInInventory.Add(Item->GetClass());
		ItemsInInventory.Add(Item);
		if (ItemsInInventory.Num() > 1)
		{
			SelectItem(ItemsInInventory.Num() - 1);
		}
	}
	else if(!ItemsInInventory.Contains(Item))
		Item->Destroy();
}

TArray<TSubclassOf<APickupableItem>> UInventoryComponent::GetItemsClasses()
{
	return ClassesInInventory;
}

APickupableItem* UInventoryComponent::GetCurrentItem()
{
	if(ItemsInInventory.Num()>0)
		return ItemsInInventory[SelectedItemIndex];
	return nullptr;
}

int UInventoryComponent::GetCurrentItemIndex()
{
	return SelectedItemIndex;
}