#include "Item.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "DrawDebugHelpers.h"
#include "Seach/Seach.h"

#define THIRTY 30


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshCommponet")); //创建一个Default root component对象
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	
	Super::BeginPlay();
}

float AItem::TransformedSin(float Value)
{
	return Amplitude * FMath::Sin(Value * TimeConstant);
}

float AItem::TransformedCos(float Value)
{
	return Amplitude * FMath::Cos(Value * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{  
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;


	
}


