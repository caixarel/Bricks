// Fill out your copyright notice in the Description page of Project Settings.


#include "destructableBlock.h"
#include"Components/StaticMeshComponent.h"
#include"TimerManager.h"
#include"Components/BoxComponent.h"


// Sets default values
AdestructableBlock::AdestructableBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Mesh;
	Mesh->SetLinearDamping(0.0f);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Mesh->SetMobility(EComponentMobility::Static);
	Mesh->SetEnableGravity(false);

	OnActorHit.AddDynamic(this, &AdestructableBlock::Collision);
	//4 sides of the Block
	//when a side gets hit by the ball it will give a diferent direction to the ball
	Bot = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisorBot"));
	Top = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisorTop"));
	LeftSide = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisorLeft"));
	RightSide = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisorRight"));
	Bot->SetupAttachment(RootComponent);
	Top->SetupAttachment(RootComponent);
	RightSide->SetupAttachment(RootComponent);
	LeftSide->SetupAttachment(RootComponent);

	Top->ComponentHasTag("Top");
	Bot->ComponentHasTag("Bot");
	LeftSide->ComponentHasTag("Left");
	RightSide->ComponentHasTag("Right");

	Top->SetSimulatePhysics(true);
	Bot->SetSimulatePhysics(true);
	LeftSide->SetSimulatePhysics(true);
	RightSide->SetSimulatePhysics(true);

	Top->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Bot->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	LeftSide->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RightSide->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

// Called when the game starts or when spawned
void AdestructableBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

void AdestructableBlock::Collision(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	GetWorldTimerManager().SetTimer(Temp, this, &AdestructableBlock::Destroying, 0.1f, false);
}



// Called every frame
void AdestructableBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

