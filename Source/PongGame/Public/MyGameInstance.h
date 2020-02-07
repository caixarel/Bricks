// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PONGGAME_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
        
public:
   //this integer will contain the the initial number of blocks of the current map
    UPROPERTY(BlueprintReadWrite)
        int TotalBlocksMap;
    //will contain the number of blocks destroyed
    UPROPERTY(BlueprintReadWrite)
        int Blocks = 0;
    UPROPERTY(BlueprintReadWrite)
        bool Victory=false;

    //this integer will control the Map number
    int MapNumber = 0;
    //this array contains the number of blocks for the first and second map
    TArray<int> MapBlockCount = { 18,20 };
    //array contains the maps
    TArray<FName> Level = { TEXT("Mapa1"),TEXT("Mapa2") ,TEXT("Mapa3") };

    
    UFUNCTION()
        void CountBlocks(int block);
    UFUNCTION()
        void ChangeMap();
private:
protected:

};
