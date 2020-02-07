// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "destructableBlock.generated.h"

UCLASS()
class PONGGAME_API AdestructableBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AdestructableBlock();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "body")
		class UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "body")
		class UBoxComponent* Bot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "body")
		class UBoxComponent* Top;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "body")
		class UBoxComponent* LeftSide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "body")
		class UBoxComponent* RightSide;

	FTimerHandle Temp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void Collision(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
		void Destroying();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
