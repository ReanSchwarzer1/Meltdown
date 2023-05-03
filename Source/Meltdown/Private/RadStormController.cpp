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

	if (SimpleTimer)
	{
		StormTimerControl(DeltaTime);

	}
	else if (stormCurrentlyActive) //the storm is not on a timer for on/off, so it's being turned on externally. We need to check if it should be turned off
	{
		CheckEndStorm(DeltaTime);
	}

	// ...



	//UE_LOG(LogTemp, Warning, TEXT("Start cd: %f"), stormStartCountdown);
	//UE_LOG(LogTemp, Warning, TEXT("End cd: %f"), stormEndCountdown); 
	//UE_LOG(LogTemp, Warning, TEXT("Is the storm active? %s"), (stormCurrentlyActive ? TEXT("true") : TEXT("false")));
	//
	//if (!stormCurrentlyActive) //if there is still time left to count down
	//{
	//	stormStartCountdown -= DeltaTime;
	//	bool activateStorm = stormStartCountdown <= 0.0f;

	//

	//	if (activateStorm)
	//	{
	//		stormEffectInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StormSystem, GetOwner()->GetActorLocation());

	//		stormCurrentlyActive = true;

	//		//reset between timer
	//		stormStartCountdown = TimeBetweenStorms;
	//	}
	//}
	//else //the storm IS active
	//{
	//	stormEndCountdown -= DeltaTime;
	//	bool endStorm = stormEndCountdown <= 0.0f;

	//	if (endStorm)
	//	{
	//		stormEffectInstance->Deactivate();
	//		stormCurrentlyActive = false;


	//		//reset duration timer
	//		stormEndCountdown = StormDuration;

	//	}

	//}
}

void URadStormController::StartStormAtPosition(float duration, FVector position)
{

	stormEffectInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StormSystem, position);

	stormCurrentlyActive = true;

	StormDuration = duration;

	stormEndCountdown = StormDuration;
}

void URadStormController::StartStorm(float duration)
{
	StartStormAtPosition(duration, GetOwner()->GetActorLocation());
}


void URadStormController::EndStorm()
{
	if (stormCurrentlyActive)
	{
		stormEffectInstance->Deactivate();
		stormCurrentlyActive = false;

	}
}

void URadStormController::StormTimerControl(float DeltaTime)
{
	if (!stormCurrentlyActive) //if there is still time left to count down
	{
		CheckStartStorm(DeltaTime);
		//stormStartCountdown -= DeltaTime;
		//bool activateStorm = stormStartCountdown <= 0.0f;
		 


		//if (activateStorm)
		//{
		//	stormEffectInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StormSystem, GetOwner()->GetActorLocation());

		//	stormCurrentlyActive = true;

		//	//reset between timer
		//	stormStartCountdown = TimeBetweenStorms;
		//}
	}
	else //the storm IS active
	{
		CheckEndStorm(DeltaTime);
		//stormEndCountdown -= DeltaTime;
		//bool endStorm = stormEndCountdown <= 0.0f;

		//if (endStorm)
		//{
		//	stormEffectInstance->Deactivate();
		//	stormCurrentlyActive = false;


		//	//reset duration timer
		//	stormEndCountdown = StormDuration;

		//}

	}
}

void URadStormController::CheckStartStorm(float DeltaTime)
{
	stormStartCountdown -= DeltaTime;
	bool activateStorm = stormStartCountdown <= 0.0f;



	if (activateStorm)
	{
		stormEffectInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StormSystem, GetOwner()->GetActorLocation());

		stormCurrentlyActive = true;

		//reset between timer
		stormStartCountdown = TimeBetweenStorms;
	}
}

void URadStormController::CheckEndStorm(float DeltaTime)
{
	stormEndCountdown -= DeltaTime;
	bool endStorm = stormEndCountdown <= 0.0f;

	if (endStorm)
	{
		EndStorm();
		//stormEffectInstance->Deactivate();
		//stormCurrentlyActive = false;


		//reset duration timer
		stormEndCountdown = StormDuration;

	}
}

