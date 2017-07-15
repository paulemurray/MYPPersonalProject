// Copyright 2017 Paul Murray GPLv3

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy_AIController.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class RPGPROJECT_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void Fire();

	UFUNCTION(BlueprintCallable)
		void Dead();

	UFUNCTION(BlueprintCallable)
		void Damage(float Damage);

private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* GunComp;

	UPROPERTY()
		float Health = 1;

	UPROPERTY()
		float DamagePerRound;

	UPROPERTY()
		float RateOfFire;

	UPROPERTY()
		float ShootRaycastRange = -10000.f;

	UPROPERTY()
		bool bIsDeadCalled;

	UFUNCTION()
		void CastForPlayer();
};
