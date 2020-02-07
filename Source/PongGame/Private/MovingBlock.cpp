// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBlock.h"
#include"Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"




// Sets default values
AMovingBlock::AMovingBlock()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMovingBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMovingBlock::Move(float moving) {
	FVector direction = GetActorLocation();
	direction.X += moving *Speed ;
	SetActorLocation(direction);
}

// Called to bind functionality to input
void AMovingBlock::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move",this, &AMovingBlock::Move);
}

