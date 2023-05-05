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

	//UPROPERTY(BlueprintReadWrite)
	UPROPERTY(EditAnywhere)
	float TimeBetweenStorms;
	UPROPERTY(EditAnywhere)
	float StormDuration;
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* StormSystem;



	UPROPERTY(EditAnywhere)
	/// <summary>
	/// If true, it will run on a continuous start/stop timer and be located on the actor that it's attached to
	/// </summary>
	bool SimpleTimer;

	UFUNCTION(BlueprintCallable, Category = "Storm")
	void StartStormAtPosition(float duration, FVector position);
	UFUNCTION(BlueprintCallable, Category = "Storm")
	void StartStorm(float duration);
	//void StartStorm(FVector position);


	UFUNCTION(BlueprintCallable, Category = "Storm")
	void EndStorm();

private:
	bool stormCurrentlyActive;
	//bool shouldActivateStorm;

	float stormStartCountdown;
	float stormEndCountdown;

	void StormTimerControl(float DeltaTime);

	void CheckStartStorm(float DeltaTime);
	void CheckEndStorm(float DeltaTime);
};
