// Fill out your copyright notice in the Description page of Project Settings.


#include "stick.h"
#include"Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include"Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include"Components/BoxComponent.h"
#include"Ball.h"

// Sets default values
Astick::Astick()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//5 static meshes where created to give different directions to the ball
	CenterBlock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("center"));
	Angle45Box= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("angle45"));
	Angle45BoxLeft= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("angle45left"));
	Angle30Box= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("angle30"));
	Angle30BoxLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("angle30left"));

	RootComponent = CenterBlock;
	Angle30Box->SetupAttachment(CenterBlock);
	Angle30BoxLeft->SetupAttachment(CenterBlock);
	Angle45Box->SetupAttachment(CenterBlock);
	Angle45BoxLeft->SetupAttachment(CenterBlock);

	CenterBlock->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	Angle30Box-> SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	Angle30BoxLeft-> SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	Angle45Box->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	Angle45BoxLeft->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));

	Angle30Box->SetRelativeLocation(FVector(200.f, 0.f, 0.f));
	Angle30BoxLeft->SetRelativeLocation(FVector(-200.f, 0.f, 0.f));
	Angle45Box->SetRelativeLocation(FVector(100.f, 0.f, 0.f));
	Angle45BoxLeft->SetRelativeLocation(FVector(-100.f, 0.f, 0.f));

	CenterBlock->SetSimulatePhysics(true);
	
	CenterBlock->SetEnableGravity(false);
	

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	//each mesh has a function when Hit
	CenterBlock->OnComponentHit.AddDynamic(this, &Astick::componentHitCenter);
	Angle30Box->OnComponentHit.AddDynamic(this, &Astick::componentHit30);
	Angle30BoxLeft->OnComponentHit.AddDynamic(this, &Astick::componentHit30Left);
	Angle45Box->OnComponentHit.AddDynamic(this, &Astick::componentHit45);
	Angle45BoxLeft->OnComponentHit.AddDynamic(this, &Astick::componentHit45Left);


	ConstructorHelpers::FObjectFinder<UStaticMesh>BlockCenter(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (BlockCenter.Succeeded())
	{
		CenterBlock->SetStaticMesh(BlockCenter.Object);
		Angle30Box->SetStaticMesh(BlockCenter.Object);
		Angle30BoxLeft->SetStaticMesh(BlockCenter.Object);
		Angle45Box->SetStaticMesh(BlockCenter.Object);
		Angle45BoxLeft->SetStaticMesh(BlockCenter.Object);
	}
}

// Called when the game starts or when spawned
void Astick::BeginPlay()
{
	Super::BeginPlay();
	
}

void Astick::Move(float moving)
{
	//movement for the stick
	FVector direction = GetActorLocation();
	direction.X += moving * Speed;
	SetActorLocation(direction);
}

void Astick::componentHitCenter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//when this component hits the ball it will change the ball's direction
	ABall* ball = Cast<ABall>(OtherActor);
	ball->speedX = 0;
	ball->speedY = -30;
}

void Astick::componentHit45(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//when this component hits the ball it will change the ball's direction
	ABall* ball = Cast<ABall>(OtherActor);
	ball->speedX = 30;
	ball->speedY = -30;
}

void Astick::componentHit30(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//when this component hits the ball it will change the ball's direction
	ABall* ball = Cast<ABall>(OtherActor);
	ball->speedX = -17.5;
	ball->speedY = 30;
}

void Astick::componentHit45Left(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ABall* ball = Cast<ABall>(OtherActor);

	if (OtherActor==ball)
	{
		//when this component hits the ball it will change the ball's direction
		ball->speedX = -30;
		ball->speedY = -30;
	}
	
}

void Astick::componentHit30Left(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//when this component hits the ball it will change the ball's direction
	ABall* ball = Cast<ABall>(OtherActor);
	ball->speedX = -17.5;
	ball->speedY = -30;
}




// Called every frame
void Astick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Astick::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move", this, &Astick::Move);

}

