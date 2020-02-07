// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "stick.generated.h"

UCLASS()
class PONGGAME_API Astick : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Astick();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		float Speed = 50.f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		UStaticMeshComponent* CenterBlock;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		UStaticMeshComponent* Angle45Box;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		UStaticMeshComponent* Angle45BoxLeft;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		UStaticMeshComponent* Angle30Box;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "components")
		UStaticMeshComponent* Angle30BoxLeft;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void Move(float moving);
	UFUNCTION()
		void componentHitCenter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void componentHit45(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void componentHit30(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void componentHit45Left(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void componentHit30Left(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
