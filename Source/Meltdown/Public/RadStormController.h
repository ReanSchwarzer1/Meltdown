// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "RadStormController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MELTDOWN_API URadStormController : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URadStormController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UNiagaraComponent* stormEffectInstance;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	float TimeBetweenStorms;
	float StormDuration;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* StormSystem;

private:
	bool stormCurrentlyActive;
	//bool shouldActivateStorm;

	float stormStartCountdown;
	float stormEndCountdown;
};
