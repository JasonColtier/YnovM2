// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Common/IdentificationInterface.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CharacterColtier.generated.h"



UCLASS()
class YNOVJV_COURSUE4_API ACharacterColtier : public ACharacter, public IIdentificationInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterColtier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USpringArmComponent* SpringArm;

	UCameraComponent* OurCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual EStudent GetAuthorStudent() const override;

	//fonction inputs
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void Turn(float AxisValue);
	void StartCrouch();
	void EndCrouch();
};
