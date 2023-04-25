// Fill out your copyright notice in the Description page of Project Settings.


#include "RadStormController.h"

// Sets default values for this component's properties
URadStormController::URadStormController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	//shouldActivateStorm = false;
}


// Called when the game starts
void URadStormController::BeginPlay()
{
	Super::BeginPlay();

	// ...

	stormStartCountdown = TimeBetweenStorms;
	stormEndCountdown = StormDuration;
	stormCurrentlyActive = false;
	
	stormEffectInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StormSystem, GetOwner()->GetActorLocation());
}


// Called every frame
void URadStormController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...


	if (!stormCurrentlyActive) //if there is still time left to count down
	{
		stormStartCountdown -= DeltaTime;
		bool activateStorm = stormStartCountdown >= 0.0f;

		if (activateStorm)
		{
			stormCurrentlyActive = true;
			stormEffectInstance->Activate();

			//reset between timer
			stormStartCountdown = TimeBetweenStorms;
		}
	}
	else //the storm IS active
	{
		stormEndCountdown -= DeltaTime;
		bool endStorm = stormEndCountdown >= 0.0f;

		if (endStorm)
		{
			stormEffectInstance->Deactivate();
			stormCurrentlyActive = false;

			//reset duration timer
			stormEndCountdown = StormDuration;

		}

	}
}

