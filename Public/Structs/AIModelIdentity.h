#pragma once

#include "CoreMinimal.h"
#include "AIModelIdentity.generated.h"

/**
* A struct representing the identity of a model.
 *
 * This struct contains information such as the language ISO code, model name, and quality of a model.
 */
USTRUCT(BlueprintType)
struct FAIModelIdentity
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Neural")
	FString LanguageIsoCode;
	UPROPERTY(BlueprintReadOnly, Category = "Neural")
	FString ModelName;
	UPROPERTY(BlueprintReadOnly, Category = "Neural")
	FString Quality;

	FAIModelIdentity() = default;

	FAIModelIdentity(const FString& InLanguageIsoCode, const FString& InModelName, const FString& InQuality)
		: LanguageIsoCode(InLanguageIsoCode), ModelName(InModelName), Quality(InQuality)
	{
	}

	bool operator==(const FAIModelIdentity& Other) const
	{
		return LanguageIsoCode == Other.LanguageIsoCode &&
			ModelName == Other.ModelName &&
			Quality == Other.Quality;
	}

	friend uint32 GetTypeHash(const FAIModelIdentity& Identity)
	{
		return HashCombine(
			HashCombine(
				GetTypeHash(Identity.LanguageIsoCode),
				GetTypeHash(Identity.ModelName)
			),
			GetTypeHash(Identity.Quality)
		);
	}

	FString ToString() const
	{
		return FString::Printf(TEXT("LanguageIsoCode: %s, ModelName: %s, Quality: %s"), *LanguageIsoCode, *ModelName, *Quality);
	}

	FString MakeSimplifiedName() const
	{
		// Create a copy of ModelName.
		FString InputString = ModelName;
		InputString = InputString.Replace(TEXT(" "), TEXT("_")); // Replace spaces with underscores
		InputString = InputString.Replace(TEXT("."), TEXT("_")); // Replace periods with underscores

		// Now we can create FName from sanitized string
		return InputString;
	}
};