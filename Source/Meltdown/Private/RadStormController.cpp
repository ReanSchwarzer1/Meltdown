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
	stormEffectInstance->Deactivate();

}


// Called every frame
void URadStormController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	//UE_LOG(LogTemp, Warning, TEXT("Start cd: %f"), stormStartCountdown);
	//UE_LOG(LogTemp, Warning, TEXT("End cd: %f"), stormEndCountdown); 
	//UE_LOG(LogTemp, Warning, TEXT("Is the storm active? %s"), (stormCurrentlyActive ? TEXT("true") : TEXT("false")));
	
	if (!stormCurrentlyActive) //if there is still time left to count down
	{
		stormStartCountdown -= DeltaTime;
		bool activateStorm = stormStartCountdown <= 0.0f;

	

		if (activateStorm)
		{
			stormCurrentlyActive = true;
			//UE_LOG(LogTemp, Warning, TEXT("exist? %s"), (stormEffectInstance ? TEXT("true") : TEXT("false")));
			//stormEffectInstance->Activate(); //this DOESNT WORK >:(
			stormEffectInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StormSystem, GetOwner()->GetActorLocation());

			//well i guess this exists, probably should remove the reference? do these variables work like that? i hate pointers

			//reset between timer
			stormStartCountdown = TimeBetweenStorms;
		}
	}
	else //the storm IS active
	{
		stormEndCountdown -= DeltaTime;
		bool endStorm = stormEndCountdown <= 0.0f;

		if (endStorm)
		{
			stormEffectInstance->Deactivate();
			stormCurrentlyActive = false;


			//reset duration timer
			stormEndCountdown = StormDuration;

		}

	}
}

