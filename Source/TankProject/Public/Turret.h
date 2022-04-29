// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTarget.h"
#include "TankPawn.h"
#include "TurretCannon.h"
#include "GameFramework/Actor.h"
#include "TankProject/Parent class/ParentStarterClass.h"
#include "IScorable.h"
#include "Turret.generated.h"



UCLASS()
class TANKPROJECT_API ATurret : public AParentStarterClass, public IScorable
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* RangeSphere;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire params")
	TSubclassOf<ATurretCannon>CannonClass;
	
	UPROPERTY()
	ATurretCannon* TurretCannon;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Fire params")
	float TargetingSpeed = 0.1f;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Fire params")
	float TargetingRate = 0.005f;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Fire params")
	float AimSlack = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Score")
	int ScorePoints = 100;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UParticleSystemComponent* DeadEffect2;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UAudioComponent* AudioDeadEffect2;

	//UPROPERTY(VisibleAnywhere)
//	class UWidgetComponent* HealthWidgetComp;
	
	int AmmoII = 9999;
	
	// Sets default values for this actor's properties
	ATurret();
	
	virtual void TakeDamage(FDamageData Damage) override;

	virtual int GetPoint() const override;

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void Destroyed() override;

	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I);
	
	UFUNCTION(BlueprintCallable)
	void FireAnyway();
	
public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void OnHealthChanged(float CurrentHealth);

	float S = 1100.0f / 100;
	float S2 = FMath::Pow(S, 2);
	float S4 = FMath::Pow(S, 4);
	
	float G = 9.81f;
	
	float TurretZ{};
	float TargetZ{};
	
	FVector TurretPosition{};

private:
	
	void FindNextTarget();
	
	virtual void Targeting();
	
	void Fire();
	
	void OnDeath();
	
    void SelfDestroed();
	
	UPROPERTY()
	TArray<AActor*> OtherActors;
	TWeakObjectPtr<AActor> Target;
	
	class AMortirProjectile* MortirProjectile;
	
	FTimerHandle TimerDestroed;
	
};
