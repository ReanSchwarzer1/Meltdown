// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MELTDOWN_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(FString itemName);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(FString itemName);

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TMap<FString, int> inventoryContents; //maybe make this an enum class instead of fstring later but not important right now


};
