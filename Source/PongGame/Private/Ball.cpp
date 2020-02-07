// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/PrimitiveComponent.h"
#include"Components/SphereComponent.h"
#include"MyGameInstance.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("sphere"));
	RootComponent = sphere;
	//sphere->OnComponentHit.AddDynamic(this, &ABall::componentHit);
}



void ABall::componentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//when the ball hits the blocks or the stick will change direction
	//the dirextion will be different depending on wich component the balls hits
	UMyGameInstance* gameinstance = Cast<UMyGameInstance>(GetGameInstance());
	 if (OtherComp->ComponentHasTag("Top")) {
	speedY = -30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
	UE_LOG(LogTemp, Warning, TEXT("top"), );
	}
	else if (OtherComp->ComponentHasTag("Bot")) {
	speedY = 30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
	UE_LOG(LogTemp, Warning, TEXT("bot"));

	}
	else if (OtherComp->ComponentHasTag("Right")) {
	speedX = 30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
	UE_LOG(LogTemp, Warning, TEXT("right"));

	}
	else if (OtherComp->ComponentHasTag("Left")) {
	speedX = -30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
	UE_LOG(LogTemp, Warning, TEXT("left"));

	}
	else if (OtherComp->ComponentHasTag("90"))
	{
		UE_LOG(LogTemp, Warning, TEXT("hit "));

		speedX = 0;
		speedY = -30;
	}
	else if (OtherComp->ComponentHasTag("45"))
	{
		UE_LOG(LogTemp, Warning, TEXT("45 "));
		speedX = 30;
		speedY = -30;
	}
	else if (OtherComp->ComponentHasTag("45L"))
	{
		UE_LOG(LogTemp, Warning, TEXT("45L %f"),speedX/speedY);

		speedX = -30;
		speedY = -30;
	}

	else if (OtherComp->ComponentHasTag("30"))
	{
		speedY = -17.5;
		speedX = 30;
		UE_LOG(LogTemp, Warning, TEXT("30 "));

	}
	else if (OtherComp->ComponentHasTag("30L"))
	{

		speedY = -17.5;
		speedX = -30;
		UE_LOG(LogTemp, Warning, TEXT("30L %f"),(-17.5/30));

	}
	



}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	sphere->OnComponentBeginOverlap.AddDynamic(this, &ABall::Overlapp);

}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector clamp = GetActorLocation();
	clamp.X +=speedX;
	clamp.Y +=speedY;
	SetActorLocation(clamp);
	//the must stay inside the game screen
	//when the ball reach the limits of the screen will change direction
	if (clamp.X>1480)
	{
		speedX = -30;
	}
	else if (clamp.X<(-1780.5))
	{
		speedX = 30;
	}
	else if (clamp.Y<-2670)
	{
		speedY = 30;
	}
	else if (clamp.Y>470)
	{// when the ball hits the bottom of the screen is Game Over , and the game restarts
		UMyGameInstance* gameinstance = Cast<UMyGameInstance>(GetGameInstance());
		gameinstance->MapNumber = 0;
		gameinstance->Blocks = 0;
		gameinstance->ChangeMap();
		//speedY = -30;
	}

}

void ABall::Overlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UMyGameInstance* gameinstance = Cast<UMyGameInstance>(GetGameInstance());
	if (OtherComp->ComponentHasTag("Top")) {
		speedY = -30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
		UE_LOG(LogTemp, Warning, TEXT("top"), );
	}
	else if (OtherComp->ComponentHasTag("Bot")) {
		speedY = 30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
		UE_LOG(LogTemp, Warning, TEXT("bot"));

	}
	else if (OtherComp->ComponentHasTag("Right")) {
		speedX = 30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
		UE_LOG(LogTemp, Warning, TEXT("right"));

	}
	else if (OtherComp->ComponentHasTag("Left")) {
		speedX = -30; OtherActor->Destroy(); gameinstance->CountBlocks(1);
		UE_LOG(LogTemp, Warning, TEXT("left"));

	}
}



