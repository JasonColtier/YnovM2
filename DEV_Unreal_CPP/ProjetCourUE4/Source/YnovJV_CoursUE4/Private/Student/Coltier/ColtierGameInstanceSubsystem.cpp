// Fill out your copyright notice in the Description page of Project Settings.


#include "Student/Coltier/ColtierGameInstanceSubsystem.h"
#include "Student/Coltier/CharacterColtier.h"

UColtierGameInstanceSubsystem::UColtierGameInstanceSubsystem()
{
    static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Student/Coltier/BP_CharColtier.BP_CharColtier'"));
    if (ItemBlueprint.Object){
        BP_CharacterColtier = (UClass*)ItemBlueprint.Object->GeneratedClass;
    }
}

void UColtierGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    
}

void UColtierGameInstanceSubsystem::SpawnStudentCharacter(FTransform Transform) const
{
    FRotator Rotation(0.0f, 0.0f, 0.0f);
    FActorSpawnParameters SpawnInfo;
    GetWorld()->SpawnActor<ACharacterColtier>(BP_CharacterColtier.Get(),Transform.GetLocation(),Rotation,SpawnInfo);

     
}

EStudent UColtierGameInstanceSubsystem::GetAuthorStudent() const
{
    return EStudent::ES_Coltier;
}
