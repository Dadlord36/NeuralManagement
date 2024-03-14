// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/NeuralModelAsset.h"

#if WITH_EDITOR

const FAIModelIdentity& UNeuralModelAsset::GetModelIdentity() const
{
	return ModelIdentity;
}

void UNeuralModelAsset::SetNamedDataMap(const TMap<FName, FRawData>& InNamedDataMap)
{
	NamedDataMap = InNamedDataMap;
}

void UNeuralModelAsset::SetRawDataBy(const FName EntryTag, const TArray<uint8>& RawData)
{
	NamedDataMap[EntryTag] = FRawData(RawData);
	MarkPackageDirty();
}

const FRawData& UNeuralModelAsset::GetRawDataBy(const FName EntryTag)
{
	return NamedDataMap[EntryTag];
}

void UNeuralModelAsset::LoadFileInto(const FFilePath Path, TArray<uint8>& FileData)
{
	if (ensureAlwaysMsgf(!Path.FilePath.IsEmpty(), TEXT("Path is empty")) == false) return;
	if (ensureAlwaysMsgf(FPaths::FileExists(Path.FilePath), TEXT("There is no file at the given path: %s"), *Path.FilePath) == false)
	{
		return;
	}
	FileData.Empty();
	ensureAlwaysMsgf(FFileHelper::LoadFileToArray(FileData, *Path.FilePath), TEXT("Neural model data was not loaded."));
}
#endif
