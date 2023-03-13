// Fill out your copyright notice in the Description page of Project Settings.

#include "BackendCommunicationComponent.h"

//--------HTTP & JSON includes--------
#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/Json/Public/Serialization/JsonReader.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"
#include "ConfigFileLoad.h"


DEFINE_LOG_CATEGORY(ViroBackendCommunication);

// Sets default values for this component's properties
UBackendCommunicationComponent::UBackendCommunicationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	FString StrToNull;
	int IntToNull;
	bool BoolToNull;
	UConfigFileLoad::LoadConfigFile(baseURL, StrToNull, StrToNull, StrToNull, StrToNull, IntToNull, BoolToNull, BoolToNull);
	if (baseURL == "") {
		baseURL = "http://viro-staging.westeurope.cloudapp.azure.com:6003/api/";
	}
	baseURLIhrsa = "http://192.168.0.139:5000/api/ ";

	// ...
}


// Called when the game starts
void UBackendCommunicationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UBackendCommunicationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBackendCommunicationComponent::StartTrainingUnitGame(FCallbackBinding callbackBinding, FStartTrainingUnitActivityRequest request, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FStartActivityResponse"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FStartTrainingUnitActivityRequest>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Games/StartTrainingUnitGame", ContentJsonString,headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FStartActivityResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::StartFreeRideGame(FCallbackBinding callbackBinding, FStartFreeRideActivityRequest request, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FStartActivityResponse"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FStartFreeRideActivityRequest>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Games/StartFreeRideGame", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FStartActivityResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::StartTestingUnitGame(FCallbackBinding callbackBinding, FStartTestingUnitActivityRequest request, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FStartActivityResponse"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FStartTestingUnitActivityRequest>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Games/StartTestingUnitGame", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FStartActivityResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::StartRaceGame(FCallbackBinding callbackBinding, FStartChallengeActivityRequest request, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FStartActivityResponse"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FStartChallengeActivityRequest>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Games/StartRaceGame", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FStartActivityResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::EndGame(FCallbackBinding callbackBinding, FEndActivityRequest endActivityRequest, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FEndActivityResponse"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FEndActivityRequest>(endActivityRequest, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Games/EndGame", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FEndActivityResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::AddGhostPayload(FCallbackBinding callbackBinding, FAddGhostPayloadRequest payloadRequest, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "void"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FAddGhostPayloadRequest>(payloadRequest, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Users/CalibrateUser", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived_void, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::AddGamePayload(FCallbackBinding callbackBinding, FAddGamePayloadRequest payloadRequest, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "void"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FAddGamePayloadRequest>(payloadRequest, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Users/CalibrateUser", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived_void, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetMaps(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetMapsResponse"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("Maps/GetMaps", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FGetMapsResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetMapSets(FCallbackBinding callbackBinding, bool activeOnly, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetMapSetsResponse"))
		return;
	FString activeOnlyString =  activeOnly ? "true" : "false";
	TSharedRef<IHttpRequest> Request = GetRequest("Maps/GetMapSets?ActiveOnly=" + activeOnlyString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FGetMapSetsResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetGhostsForMapSet(FCallbackBinding callbackBinding, FString mapSetGuid, bool isArcade, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetGhostsForMapSetResponse"))
		return;

	FString content = "Maps/GetGhostsForMapSet";
	FString isArcadeString = isArcade ? "true" : "false";
	content += "?MapSetGuid=" + mapSetGuid + "&IsArcade=" + isArcadeString;
	TSharedRef<IHttpRequest> Request = GetRequest(content, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FGetGhostsForMapSetResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetGhostsPayloads(FCallbackBinding callbackBinding, TArray<FString> ghostGuids, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetGhostsPayloadsResponse"))
		return;
	FString content = "Maps/GetGhostsPayloads?";
	for (int i = 0; i < ghostGuids.Num(); i++)
	{
		content += "GhostGuids=" + ghostGuids[i];
		if (i != ghostGuids.Num() - 1) content += "&";
	}
	TSharedRef<IHttpRequest> Request = GetRequest(content, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FGetGhostsPayloadsResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetStation(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	UE_LOG(ViroBackendCommunication, Log, TEXT("URL: %s"), *baseURL);
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetStationResponse"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("Stations/GetStation", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FGetStationResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetStationContext(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FStationContextResponse"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("Stations/GetStationContext", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FStationContextResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::StartSessionForGuest(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FStartSessionForGuestResponse"))
		return;
	TSharedRef<IHttpRequest> Request = PostRequestNoJson("Stations/StartSessionForGuest", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FStartSessionForGuestResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::EndSession(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "void"))
		return;
	TSharedRef<IHttpRequest> Request = PostRequestNoJson("Stations/EndStationSession", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived_void, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetNextAerobicTrainingUnit(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FAerobicTrainingUnitResponse"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("TrainingPlans/GetNextAerobicTrainingUnit", headers);
	Request->OnProcessRequestComplete().BindUObject(this, 
		&UBackendCommunicationComponent::OnResponseReceived<FAerobicTrainingUnitResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetNextFintessTrainingUnit(FCallbackBinding callbackBinding, FString stationGuid, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FFitnessTraining"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("TrainingPlans/GetNextFitnessTrainingUnit?StationGuid=" + stationGuid, headers);
	Request->OnProcessRequestComplete().BindUObject(this,
		&UBackendCommunicationComponent::OnResponseReceived<FFitnessTraining>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetTestingUnitsForStation(FCallbackBinding callbackBinding, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FTestingUnitsResponse"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("Trainings/GetTestingUnitsForStation", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FTestingUnitsResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::GetTestingUnitScenario(FCallbackBinding callbackBinding, FString testingUnitGuid, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetTestingUnitScenarioResponse"))
		return;
	FString content = "Trainings/GetTestingUnitScenario?TestingUnitGuid=" + testingUnitGuid;
	content += "&TestingUnitGuid=" + testingUnitGuid;
	TSharedRef<IHttpRequest> Request = GetRequest(content, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FTestingUnitsResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::CalibrateUser(FCallbackBinding callbackBinding, FCalibrateGamerRequest request, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "void"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FCalibrateGamerRequest>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("Users/CalibrateUser", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived_void, callbackBinding);
	Request->ProcessRequest();
}



void UBackendCommunicationComponent::GetActiveUser(FCallbackBinding callbackBinding, FString stationGuid, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FActiveUser"))
		return;
	TSharedRef<IHttpRequest> Request = GetRequest("GameManagement/GetActiveUser?StationGuid=" + stationGuid, headers);
	Request->OnProcessRequestComplete().BindUObject(this,
		&UBackendCommunicationComponent::OnResponseReceived<FActiveUser>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::AerobicGameSummary(FCallbackBinding callbackBinding, FAerobicGameSummary request, const TMap<FString, FString> &headers)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FleaderboardPosition"))
		return;
	FString ContentJsonString;
	GetJsonStringFromStruct<FAerobicGameSummary>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("GameManagement/FitnessGameSummary", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UBackendCommunicationComponent::OnResponseReceived<FleaderboardPosition>, callbackBinding);
	Request->ProcessRequest();
}

void UBackendCommunicationComponent::RemoveActiveUser(FRemoveUser request, const TMap<FString, FString> &headers)
{
	FString ContentJsonString;
	GetJsonStringFromStruct<FRemoveUser>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("GameManagement/RemoveActiveUser", ContentJsonString, headers);
	Request->OnProcessRequestComplete();
	Request->ProcessRequest();
}
