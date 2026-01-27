#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent; 
class AItem;

UCLASS()
class SEACH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);    
	void LookUP(float Value);
	void Turn(float Value);
	void MoveRight(float Value);
	void EKeyPressed();

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere,Category=Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere,Category = Hair)
	UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)//只会在细节面板看到
	AItem* OverlappingItem;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const{ return CharacterState; } //让外部可以访问到私有变量 CharacterState
};
