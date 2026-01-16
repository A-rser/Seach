// BP_Item.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Item.generated.h"

class USphereComponent;

UCLASS()
class SEACH_API ABP_Item : public AActor
{
	GENERATED_BODY()

public:
	ABP_Item();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
};