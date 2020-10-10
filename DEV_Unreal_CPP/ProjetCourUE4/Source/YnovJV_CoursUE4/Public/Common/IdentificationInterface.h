// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IdentificationInterface.generated.h"

UENUM(BlueprintType)
enum class EStudent : uint8
{
	ES_NONE			UMETA(DisplayName = "NONE"),
	ES_PROF			UMETA(DisplayName = "PROF"),
	ES_Andral		UMETA(DisplayName = "Julien Andral"),
	ES_Aubineau		UMETA(DisplayName = "Alexis Aubineau"),
	ES_Barrand		UMETA(DisplayName = "Théo Barrand"),
	ES_Canteloup	UMETA(DisplayName = "Anthony Canteloup"),
	ES_Coltier		UMETA(DisplayName = "Jason Coltier"),
	ES_Croquefer	UMETA(DisplayName = "Gaetan Croquefer"),
	ES_Curvat		UMETA(DisplayName = "Jean-Baptiste Curvat"),
	ES_Deshayes		UMETA(DisplayName = "Gaultier Deshayes"),
	ES_Ghizzardi	UMETA(DisplayName = "Thomas Ghizzardi"),
	ES_Monnier		UMETA(DisplayName = "Alan Monnier"),
	ES_Persh		UMETA(DisplayName = "Mel Persh"),
	ES_Relin		UMETA(DisplayName = "Vincent Relin"),
	ES_Theodore		UMETA(DisplayName = "Sylvain Theodore"),
	ES_Vretman		UMETA(DisplayName = "Maxence Vretman"),
	ES_Yoteau		UMETA(DisplayName = "Nicolas Yoteau"),
	ES_Dymarski		UMETA(DisplayName = "Paul-Emile Dymarski"),
	ES_Ngoran		UMETA(DisplayName = "Ange Patrick N'goran"),
	ES_MAX			UMETA(DisplayName = "MAX")
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UIdentificationInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class YNOVJV_COURSUE4_API IIdentificationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable)
	virtual EStudent GetAuthorStudent() const = 0;
};
