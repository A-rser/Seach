// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SEACH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float RunningTime;

	UPROPERTY(EditDefaultsOnly)
	float Amplitude = 0.25f;
	float TimeConstant = 5.f;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
s