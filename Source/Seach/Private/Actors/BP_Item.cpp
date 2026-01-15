	// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BP_Item.h"
#include "Components/SphereComponent.h"

// Sets default values
ABP_Item::ABP_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ABP_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

