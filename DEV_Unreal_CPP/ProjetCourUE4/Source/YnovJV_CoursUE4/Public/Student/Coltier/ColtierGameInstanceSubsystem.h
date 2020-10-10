// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Common/ExerciceSubsystemInterface.h"
#include "Common/IdentificationInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ColtierGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class YNOVJV_COURSUE4_API UColtierGameInstanceSubsystem : public UGameInstanceSubsystem, public IExerciceSubsystemInterface, public IIdentificationInterface
{
	GENERATED_BODY()
	UColtierGameInstanceSubsystem();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void SpawnStudentCharacter(FTransform Transform) const override;
	virtual EStudent GetAuthorStudent() const override;
	TSubclassOf<class ACharacter> BP_CharacterColtier;
};
