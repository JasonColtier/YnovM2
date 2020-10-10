// Fill out your copyright notice in the Description page of Project Settings.


#include "Integration/IntegrationPlayerController.h"


#include "Common/CommonFunctionLibrary.h"
#include "Common/IdentificationInterface.h"


void AIntegrationPlayerController::BeginPlay()
{
    Super::BeginPlay();

    InputComponent->BindAction("ToggleStudentPossess", IE_Pressed, this, &AIntegrationPlayerController::ToggleStudentPossess);

    IntegrationPawn = GetPawn();
}

void AIntegrationPlayerController::ToggleStudentPossess()
{
    UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => START"))

    if (IntegrationPawn->IsPlayerControlled())
    {
        UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => Go ON"))
       
        FHitResult HitResult;
        FVector Start = GetPawn()->GetActorLocation();
        FVector End = Start + GetPawn()->GetActorForwardVector() * 500.f;
        FCollisionQueryParams Params;
        Params.AddIgnoredActor(GetPawn());
        Params.TraceTag = "COUCOU";

        if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Pawn, Params))
        {
            if (HitResult.GetActor()->IsA(APawn::StaticClass()) && HitResult.GetActor()->Implements<UIdentificationInterface>())
            {
                UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => Possess student : %s"), *GETENUMSTRING("EStudent", Cast<IIdentificationInterface>(HitResult.GetActor())->GetAuthorStudent()))
                Possess(Cast<APawn>(HitResult.GetActor()));            
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => Hit not a pawn or doesn't implement IIdentificationInterface : %s"), *HitResult.GetActor()->GetName())
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => no hit"))
        }
   }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => Go OFF"))

        Possess(IntegrationPawn);
    }

    UE_LOG(LogTemp, Warning, TEXT("AIntegrationPlayerController::ToggleStudentPossess => END"))
}
