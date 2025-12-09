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


	UPROPERTY(EditAnyWhere,BlueprintReadWrite,Category="Sine Parameters")  
	//BlueprintReadWrite 蓝图中可以更改    Category 在蓝图类默认的分类
	float Amplitude = 0.25f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite,Category="Sine Parameters")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintCallable)
		float TransformedSin(float Value);

private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))//meta==元说明符的语法
			//AllowPrivateAccess 当这个 值为true，meta 就可以修改Running Time
	float RunningTime;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};