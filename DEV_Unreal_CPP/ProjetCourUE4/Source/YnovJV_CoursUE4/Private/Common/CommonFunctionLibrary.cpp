// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/CommonFunctionLibrary.h"

TArray<EStudent> UCommonFunctionLibrary::GetAllStudents()
{
    TArray<EStudent> AllStudents;
    
    for (int i = 1; i < (int)EStudent::ES_MAX; ++i)
    {
        AllStudents.Add((EStudent)i);
    }
    
    return AllStudents;
}