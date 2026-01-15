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

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	
}

// Called every frame
void ABP_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::OnSphereOverlap(UPrimitiveComponent OnComponentBeginOverlap, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessge(1, 30.f, FColor::Red, OtherActorName);
		}
}
