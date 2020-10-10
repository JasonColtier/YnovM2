// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "ExerciceSubSystemInterface.h"
#include "IdentificationInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ObjectMacros.h"

#include "CommonFunctionLibrary.generated.h"

#define GETENUMSTRING(etype, evalue) ( (FindObject<UEnum>(ANY_PACKAGE, TEXT(etype), true) != nullptr) ? FindObject<UEnum>(ANY_PACKAGE, TEXT(etype), true)->GetNameStringByIndex((int32)evalue) : FString("Invalid - are you sure enum uses UENUM() macro?") )

/**
 * 
 */
UCLASS()
class YNOVJV_COURSUE4_API UCommonFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<EStudent> GetAllStudents();
};
