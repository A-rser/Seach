// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ABird::ABird()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	
	SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh1"));
	BirdMesh->SetupAttachment(Capsule);
	//BirdMesh->SetupAttachment(GetRootComponent());
	//这两个都是设置BirdMesh附加到基组件的

	AutoPossessPlayer = EAutoReceiveInput::Player0; //默认控制
}


void ABird::BeginPlay()
{
	Super::BeginPlay();
	 

}

void ABird::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value:%f"), Value);
}
    
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
 
// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"),this,&ABird::MoveForward);
}

 