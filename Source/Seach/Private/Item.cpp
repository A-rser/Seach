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
	SetActorRotation(FRotattor(0.f, 45.f, 0.f));

	SetActorLocation(FVector(0.f, 0.f, 50.f));

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Vector = GetActorForwardVector();
	
	DRAW_VECTOR(Location, Location+Vector*100.f);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}


