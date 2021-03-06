// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);
		// Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// Fire at William 
		ControlledTank->Fire();
	}
}
