// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Common/ExerciceSubsystemInterface.h"
#include "UObject/ScriptInterface.h"
#include "Common/IdentificationInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IntegrationSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class YNOVJV_COURSUE4_API UIntegrationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	TScriptInterface<IExerciceSubsystemInterface> GetExerciceSubSystemByStudent(EStudent Student);
};
