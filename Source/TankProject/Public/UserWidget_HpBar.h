// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turret.h"
#include "HealthComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "UserWidget_HpBar.generated.h"

UCLASS(Abstract)

class TANKPROJECT_API UUserWidget_HpBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	void SetOwnerTurret(ATurret* InTurret){OwnerTurret = InTurret;}
	
protected:

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	TWeakObjectPtr<ATurret>OwnerTurret;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComponent;
	
	UPROPERTY( meta = (BindWidget))
	class UProgressBar* HpBar;

	UPROPERTY( meta = (BindWidget))
	class UTextBlock* CurrentHealthLabel;

	UPROPERTY( meta = (BindWidget))
	class UTextBlock* MaxHealthLabel;
	
};
