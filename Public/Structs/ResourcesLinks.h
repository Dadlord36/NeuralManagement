// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResourcesLinks.generated.h"

/**
 * Structure representing a file link.
 */
USTRUCT()
struct NEURALMANAGEMENT_API FFileLink
{
	GENERATED_BODY()

	const FString& GetLink() const
	{
		return Link;
	}

	void SetLink(const FString& InLink)
	{
		Link = InLink;
	}

	bool IsURL() const
	{   
		return Link.StartsWith(TEXT("http://")) || Link.StartsWith(TEXT("https://"));
	}
	
private:
	UPROPERTY()
	FString Link;
};

/**
 * @struct FResourcesLinks
 * @brief Structure representing a collection of resource links.
 *
 * This structure contains a map of named resource links.
 */
USTRUCT(BlueprintType)
struct NEURALMANAGEMENT_API FResourcesLinks
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FName, FFileLink> NamedLinksMap;
};
