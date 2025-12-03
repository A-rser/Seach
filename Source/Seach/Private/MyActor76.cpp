// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor76.h"

// Sets default values
AMyActor76::AMyActor76()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor76::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp,)
}

// Called every frame
void AMyActor76::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

