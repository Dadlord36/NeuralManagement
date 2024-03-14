// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Structs/AIModelIdentity.h"

#include "NeuralModelAsset.generated.h"


USTRUCT()
struct NEURALMANAGEMENT_API FRawData
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<uint8> Data;
};


UCLASS()
class NEURALMANAGEMENT_API UNeuralModelAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	const FAIModelIdentity& GetModelIdentity() const;
	const FRawData& GetRawDataBy(const FName EntryTag);
	void SetNamedDataMap(const TMap<FName, FRawData>& InNamedDataMap);
	void SetRawDataBy(const FName EntryTag, const TArray<uint8>& RawData);

private:
#if WITH_EDITOR
	static void LoadFileInto(const FFilePath Path, TArray<uint8>& FileData);
#endif

protected:
	UPROPERTY(EditDefaultsOnly)
	FAIModelIdentity ModelIdentity;
	UPROPERTY()
	TMap<FName, FRawData> NamedDataMap;
};
