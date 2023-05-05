// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Dom/JsonObject.h"
#include "InventoryJSON.generated.h"




//USTRUCT(BlueprintType)
//struct FInvJSON 
//{
//	GENERATED_BODY()
//
//public:
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//		int StimsMade = 0;
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//		int StimsUsed = 0;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//		float PeakRadiation = 0.0f;
//
//};

/**
 * 
 */
UCLASS()
class MELTDOWN_API UInventoryJSON : public UBlueprintFunctionLibrary
{
	class FJsonObject;

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SoldierJSONWrite")
		static void WriteStringToFile(FString FilePath, FString StimsCrafted, FString StimsUsed, FString PeakRadiation, bool& bOutSuccess, FString& OutInfoMessage);
	//
	//UFUNCTION(BlueprintCallable, Category = "SoldierWrite")
	//	static void WriteJSON(FString FilePath, TSharedPtr<FJsonObject> JSONObject, bool& bOutSuccess, FString& OutInfoMessage);


	//UFUNCTION(BlueprintCallable, Category = "SoldierWrite")
	//	static void WriteJSONToFile(FString FilePath, FInvJSON JSONObject, bool& bOutSuccess, FString& OutInfoMessage);
};
