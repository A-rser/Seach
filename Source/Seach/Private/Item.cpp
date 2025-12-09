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
	 
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0.f, 45.f, 0.f));

	SetActorLocation(FVector(0.f, 0.f, 50.f));

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Vector = GetActorForwardVector();
	

}

float AItem::TransformedSin(float Value)
{
	return Amplitude * FMath::Sin(Value * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	

}


