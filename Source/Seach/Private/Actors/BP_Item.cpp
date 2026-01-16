// BP_Item.cpp

#include "Actors/BP_Item.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h" // 引入 Engine 头文件以使用 GEngine

// Sets default values
ABP_Item::ABP_Item() // 确保类名是 ABP_Item
{
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);
}

void ABP_Item::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABP_Item::OnSphereOverlap);
	//用Sphere的重叠时，触发事件，绑定委托到Onsphereoverlap
}

// Called every frame
void ABP_Item::Tick(float DeltaTime) //
{
	Super::Tick(DeltaTime);
}

void ABP_Item::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) 
	{
		const FString OtherActorName = OtherActor->GetName();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
		}
	}
}