// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MovingBlock.generated.h"

UCLASS()
class PONGGAME_API AMovingBlock : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovingBlock();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		float Speed = 50.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void Move(float moving);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
