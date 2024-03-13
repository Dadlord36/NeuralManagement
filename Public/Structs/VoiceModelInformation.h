// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIModelIdentity.h"
#include "ResourcesLinks.h"
#include "VoiceModelInformation.generated.h"


/**
 * 
 */
USTRUCT()
struct NEURALMANAGEMENT_API FVoiceModelInformation
{
	GENERATED_BODY()

	FVoiceModelInformation() = default;

	FVoiceModelInformation(const FString& LanguageIsoCode, const FString& ModelName, const FString& Quality,
	                       const FResourcesLinks&& ResourcesLinks, const int32 InFileSize):
		Identity(LanguageIsoCode, ModelName, Quality), ResourcesLinks(ResourcesLinks), FileSize(InFileSize)
	{
		ensureMsgf(!LanguageIsoCode.IsEmpty(), TEXT("LanguageIsoCode must not be empty."));
		ensureMsgf(!ModelName.IsEmpty(), TEXT("ModelName must not be empty."));
		ensureMsgf(!Quality.IsEmpty(), TEXT("Quality must not be empty."));
	}

	FVoiceModelInformation(const FAIModelIdentity Identity, const FResourcesLinks& ResourcesLinks, const uint32 FileSize)
		: Identity(Identity),
		  ResourcesLinks(ResourcesLinks),
		  FileSize(FileSize)
	{
	}


	UPROPERTY()
	FAIModelIdentity Identity;
	UPROPERTY()
	FResourcesLinks ResourcesLinks;
	UPROPERTY()
	uint32 FileSize;

	bool operator==(const FVoiceModelInformation& Other) const
	{
		return Identity == Other.Identity;
	}

	friend uint32 GetTypeHash(const FVoiceModelInformation& Info)
	{
		return GetTypeHash(Info.Identity);
	}
};
