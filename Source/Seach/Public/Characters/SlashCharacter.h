#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent; 
class AItem;
class UAnimMontage;
class AWeapon;
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

	/*
	* Callbacks for input
	*/

	void MoveForward(float Value);    
	void LookUP(float Value);
	void Turn(float Value);
	void MoveRight(float Value);
	void EKeyPressed();
	void Attack();

	/*
	* Play Montage Functions
	*/
	void PlayAttackMontage();
	UFUNCTION(BlueprintCallable)//BlueprintCallable 蓝图可调用
	void AttackEnd();
	bool CanAttack();

	void PlayEquipMontage(FName SectionName);
	bool CanDisarm();
	bool CanArm();

	UFUNCTION(BlueprintCallable)
	void Disarm();

	UFUNCTION(BlueprintCallable)
	void Arm();

	UFUNCTION(BlueprintCallable)
	void FinishedEquipping();

	
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

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	AWeapon* EquippedWeapon;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite,meta=(AllowPrivateAccess="true")) //允许在蓝图中读写，AllowPrivateAccess允许私有访问
	EActionState Actionstate = EActionState::EAS_Unoccupied;

	// Animation Montage
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const{ return CharacterState; } //让外部可以访问到私有变量 CharacterState
};
