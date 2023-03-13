// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfigFileLoad.h"
FString UConfigFileLoad::VIROtationFileString;
DEFINE_LOG_CATEGORY(ViroConfigFile);

void UConfigFileLoad::LoadConfigFile(FString &Url, FString &LeaderboardURL, FString &ApiKey, FString &BuildType, FString &ControllerType, int &CSAFE_Port, bool &DebugLog, bool &DebugScreen)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ViroStationFile = FPlatformProcess::UserSettingsDir();
	ViroStationFile.Append("FitReality/station.json");
	FPaths::RemoveDuplicateSlashes(ViroStationFile);

	//FString ViroStationFile = "%AppData%/FitReality/station.json";
	if (PlatformFile.FileExists(*ViroStationFile))
	{
		UE_LOG(ViroConfigFile, Log, TEXT("Loading config from: %s"), *ViroStationFile);
		FFileHelper::LoadFileToString(VIROtationFileString, *ViroStationFile);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(VIROtationFileString);
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			if (JsonObject->TryGetStringField("ApiKey", ApiKey))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded ApiKey: %s"), *ApiKey);
			}
			if(JsonObject->TryGetStringField("Url", Url))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded Url: %s"),*Url);
			}
			if (JsonObject->TryGetStringField("LeaderboardURL", LeaderboardURL))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded Leaderboard URL: %s"), *LeaderboardURL);
			}
			if(JsonObject->TryGetStringField("BuildType", BuildType))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded BuildType: %s"), *BuildType);
			}
			if(JsonObject->TryGetStringField("ControllerType", ControllerType))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded ControllerType: %s"), *ControllerType);
			}
			if(JsonObject->TryGetNumberField("CSAFE Port", CSAFE_Port))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded CSAFE_Port: %d"), CSAFE_Port);
			}
			if (JsonObject->TryGetBoolField("DebugLog", DebugLog))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded DebugLog: %d"), DebugLog);
			}
			if (JsonObject->TryGetBoolField("DebugScreen", DebugScreen))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded DebugScreen: %d"), DebugScreen);
			}
		}
	}
	else {
		UE_LOG(ViroConfigFile, Log, TEXT("Cannot find file: %s"), *ViroStationFile);
	}
}

void UConfigFileLoad::LoadStringFromConfigFile(FString ParameterName, FString &Value)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ViroStationFile = FPlatformProcess::UserSettingsDir();
	ViroStationFile.Append("FitReality/station.json");
	FPaths::RemoveDuplicateSlashes(ViroStationFile);

	if (PlatformFile.FileExists(*ViroStationFile))
	{
		UE_LOG(ViroConfigFile, Log, TEXT("Loading config from: %s"), *ViroStationFile);
		FFileHelper::LoadFileToString(VIROtationFileString, *ViroStationFile);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(VIROtationFileString);
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			if (JsonObject->TryGetStringField(ParameterName, Value))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded %s: %s"), *ParameterName, *Value);
			}
			else
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Parameter %s not found in config file."), *ParameterName);
			}
		}
	}
	else {
		UE_LOG(ViroConfigFile, Log, TEXT("Cannot find file: %s"), *ViroStationFile);
	}
}

void UConfigFileLoad::LoadIntFromConfigFile(FString ParameterName, int &Value)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ViroStationFile = FPlatformProcess::UserSettingsDir();
	ViroStationFile.Append("FitReality/station.json");
	FPaths::RemoveDuplicateSlashes(ViroStationFile);

	if (PlatformFile.FileExists(*ViroStationFile))
	{
		UE_LOG(ViroConfigFile, Log, TEXT("Loading config from: %s"), *ViroStationFile);
		FFileHelper::LoadFileToString(VIROtationFileString, *ViroStationFile);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(VIROtationFileString);
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			if (JsonObject->TryGetNumberField(ParameterName, Value))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded %s: %d"), *ParameterName, Value);
			}
			else
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Parameter %s not found in config file."), *ParameterName);
			}
		}
	}
	else {
		UE_LOG(ViroConfigFile, Log, TEXT("Cannot find file: %s"), *ViroStationFile);
	}
}

void UConfigFileLoad::LoadFloatFromConfigFile(FString ParameterName, float &Value)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ViroStationFile = FPlatformProcess::UserSettingsDir();
	ViroStationFile.Append("FitReality/station.json");
	FPaths::RemoveDuplicateSlashes(ViroStationFile);

	if (PlatformFile.FileExists(*ViroStationFile))
	{
		UE_LOG(ViroConfigFile, Log, TEXT("Loading config from: %s"), *ViroStationFile);
		FFileHelper::LoadFileToString(VIROtationFileString, *ViroStationFile);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(VIROtationFileString);
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			double ValueD;
			if (JsonObject->TryGetNumberField(ParameterName, ValueD))
			{
				Value = (float)ValueD;
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded %s: %f"), *ParameterName, Value);
			}
			else
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Parameter %s not found in config file."), *ParameterName);
			}
		}
	}
	else {
		UE_LOG(ViroConfigFile, Log, TEXT("Cannot find file: %s"), *ViroStationFile);
	}
}

void UConfigFileLoad::LoadBoolFromConfigFile(FString ParameterName, bool &Value)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ViroStationFile = FPlatformProcess::UserSettingsDir();
	ViroStationFile.Append("FitReality/station.json");
	FPaths::RemoveDuplicateSlashes(ViroStationFile);

	if (PlatformFile.FileExists(*ViroStationFile))
	{
		UE_LOG(ViroConfigFile, Log, TEXT("Loading config from: %s"), *ViroStationFile);
		FFileHelper::LoadFileToString(VIROtationFileString, *ViroStationFile);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(VIROtationFileString);
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{

			if (JsonObject->TryGetBoolField(ParameterName, Value))
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Loaded %s: %s"), *ParameterName, (Value ? TEXT("True") : TEXT("False")));
			}
			else
			{
				UE_LOG(ViroConfigFile, Log, TEXT("Parameter %s not found in config file."), *ParameterName);
			}
		}
	}
	else {
		UE_LOG(ViroConfigFile, Log, TEXT("Cannot find file: %s"), *ViroStationFile);
	}
}


