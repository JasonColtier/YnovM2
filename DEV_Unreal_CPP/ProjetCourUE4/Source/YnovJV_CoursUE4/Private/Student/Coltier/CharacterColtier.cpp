// Fill out your copyright notice in the Description page of Project Settings.


#include "Student/Coltier/CharacterColtier.h"
#include "Components/InputComponent.h"

// Sets default values
ACharacterColtier::ACharacterColtier()//le constructeur de ma classe
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));//création du spring arm
	SpringArm->SetupAttachment(RootComponent);//je l'attache au root de mon character
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-30.0f, 0.0f, 0.0f));//je dis qu'il sera 5m au dessus du sol et avec un angle
	SpringArm->TargetArmLength = 400.f;// à une distance de 4m de mon perso
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACharacterColtier::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GI name : %s"),	*GetGameInstance()->GetName());

}

// Called every frame
void ACharacterColtier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACharacterColtier::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ACharacterColtier::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACharacterColtier::MoveRight);
	InputComponent->BindAxis("LookUp", this, &ACharacterColtier::LookUp);
	InputComponent->BindAxis("Turn", this, &ACharacterColtier::Turn);
	InputComponent->BindAction("Jump",IE_Pressed,this,&ACharacterColtier::Jump);
	InputComponent->BindAction("Crouch",IE_Pressed,this,&ACharacterColtier::StartCrouch);
	InputComponent->BindAction("Crouch",IE_Released,this,&ACharacterColtier::EndCrouch);
}

EStudent ACharacterColtier::GetAuthorStudent() const
{
	return EStudent::ES_Coltier;
}

void ACharacterColtier::MoveForward(float AxisValue)
{
	if(AxisValue !=0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move forward ! %f"),AxisValue );
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void ACharacterColtier::MoveRight(float AxisValue)
{
	if(AxisValue !=0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move Right ! %f"),AxisValue );
	
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}

	// AddControllerYawInput(AxisValue * 30 * GetWorld()->GetDeltaSeconds());

}

void ACharacterColtier::LookUp(float AxisValue)
{
	if(AxisValue !=0)
	{
		FRotator rot = SpringArm->GetRelativeRotation();
		rot.Pitch += AxisValue *-1.f;
		SpringArm->SetRelativeRotation(rot);
	}
}

void ACharacterColtier::Turn(float AxisValue)
{
	if(AxisValue !=0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Turn !"),AxisValue );
		AddControllerYawInput(AxisValue * 30 * GetWorld()->GetDeltaSeconds());
	}
	
}

void ACharacterColtier::StartCrouch()
{
	Crouch();
}

void ACharacterColtier::EndCrouch()
{
	UnCrouch();
}


