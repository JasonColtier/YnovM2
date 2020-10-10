// Fill out your copyright notice in the Description page of Project Settings.


#include "Integration/IntegrationSubsystem.h"

TScriptInterface<IExerciceSubsystemInterface> UIntegrationSubsystem::GetExerciceSubSystemByStudent(EStudent Student)
{
    TScriptInterface<IExerciceSubsystemInterface> ScriptInterface;

    for(TObjectIterator<UClass> It; It; ++It)
    {
        if(It->IsChildOf(UGameInstanceSubsystem::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract) && It->ImplementsInterface(UExerciceSubsystemInterface::StaticClass()))
        {

            const auto Subsystem = GetGameInstance()->GetSubsystemBase(*It);
            const auto IdentificationInterface = Cast<IIdentificationInterface>(Subsystem);

            if (IdentificationInterface->GetAuthorStudent() == Student)
            {
                UE_LOG(LogTemp, Warning, TEXT("Subsystem : %s"),	*Subsystem->GetName());
                ScriptInterface.SetObject(Subsystem);

                // UE_LOG(LogTemp, Warning, TEXT("Scriptinterface : %s"),	*ScriptInterface.GetObject()->GetName());

                
                ScriptInterface.SetInterface(Cast<IExerciceSubsystemInterface>(Subsystem));
                UE_LOG(LogTemp, Warning, TEXT("It name : %s"),	*It->GetName());


            }
        }
    }


    return ScriptInterface;
}
