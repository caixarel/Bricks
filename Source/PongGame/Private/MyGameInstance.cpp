// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include"Engine/World.h"
#include"Kismet/GameplayStatics.h"


void UMyGameInstance::CountBlocks(int block)
{
	//TotalBlocksMap is equal to the total of blocks stored on the array MapBlockCount.MapNumber will acess the
	//index of the current level
	TotalBlocksMap = MapBlockCount[MapNumber];
	//when a block is destroyed Blocks is incremented
	Blocks++;
	//when the player destroys all the block in a level
	if (Blocks==TotalBlocksMap)
	{
		//the map is finished
		Victory = true;
		//MapNumber id incremented and will serve as index for the Level array and also for the number of blocks present in the map
		MapNumber++;
		//Bloks is reset when starting the new map
		Blocks = 0;
		FName newLevel = Level[MapNumber];
		//new level will be loaded
		UGameplayStatics::OpenLevel(this, newLevel, false);
		Victory = false;

	}
}

void UMyGameInstance::ChangeMap()
{
	//when the ball hits the bottom of the screen the game resets
	FName newLevel = Level[MapNumber];
	UGameplayStatics::OpenLevel(this, newLevel, false);

}
