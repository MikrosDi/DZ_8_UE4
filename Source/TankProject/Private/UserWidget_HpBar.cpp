// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget_HpBar.h"



void UUserWidget_HpBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	
	if(!OwnerTurret.IsValid())
	{
		return;
	}
	
}