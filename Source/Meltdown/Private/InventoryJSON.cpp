// Fill out your copyright notice in the Description page of Project Settings.


#include "Serialization/JsonSerializer.h"
#include "Templates/SharedPointer.h"
#include "JsonObjectConverter.h"
#include "InventoryJSON.h"



void UInventoryJSON::WriteStringToFile(FString FilePath, FString StimsCrafted, FString StimsUsed, FString PeakRadiation, bool& bOutSuccess, FString& OutInfoMessage)
{
	FString tempString = "{\n\t\"Stims Crafted\": " + StimsCrafted + "\n\t\"Stims Used\" : " + StimsUsed + "\n\t\"Peak Radiation\" : " + PeakRadiation + "\n}";
	if (!FFileHelper::SaveStringToFile(tempString, *FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Write String to File failed"), *FilePath);
		return;
	}
	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write String to File Was Successful! "), *FilePath);
}

//void UInventoryJSON::WriteJSONToFile(FString FilePath, FInvJSON JSONObject, bool& bOutSuccess, FString& OutInfoMessage)
//{
//	TSharedPtr<FJsonObject> JsonConv = FJsonObjectConverter::UStructToJsonObject(JSONObject);
//	if (JsonConv == nullptr) {
//		bOutSuccess = false;
//		OutInfoMessage = FString::Printf(TEXT("Converting from JSON to string failed"));
//		return;
//	}
//	WriteJSON(FilePath, JsonConv, bOutSuccess, OutInfoMessage);
//	bOutSuccess = true;
//	OutInfoMessage = FString::Printf(TEXT("Write String to File Was Successful! "), *FilePath);
//}
//void UInventoryJSON::WriteJSON(FString FilePath, TSharedPtr<FJsonObject> JSONObject, bool& bOutSuccess, FString& OutInfoMessage)
//{
//	FString JSONSerialized;
//	//FJsonObjectConverter::JsonObjectToUStruct<FString>(JSONObject.ToSharedRef(), &JSONSerialized);
//	if (!FJsonSerializer::Serialize(JSONObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JSONSerialized, 0))) {
//		bOutSuccess = false;
//		OutInfoMessage = FString::Printf(TEXT("Converting from JSON to string failed"));
//		return;
//	}
//	if (!FFileHelper::SaveStringToFile(JSONSerialized, *FilePath)) {
//		bOutSuccess = false;
//		OutInfoMessage = FString::Printf(TEXT("Write String to File failed"), *FilePath);
//		return;
//	}
//	bOutSuccess = true;
//	OutInfoMessage = FString::Printf(TEXT("Write String to File Was Successful! "), *FilePath);
//}