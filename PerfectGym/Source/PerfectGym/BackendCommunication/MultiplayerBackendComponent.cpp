// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerBackendComponent.h"

UMultiplayerBackendComponent::UMultiplayerBackendComponent() 
{	
	localMasterServerPort = "8000";
	localMasterServerIp = "192.168.142.207";
	baseURL = "192.168.142.207:8000";
}

//----------------Local backend--------------------------------------------------------------------------//

void UMultiplayerBackendComponent::CreateGame(FCreateRequest request, FCallbackBinding callbackBinding)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FCreateJoinResponse"))
		return;
	TMap<FString, FString> headers;
	FString ContentJsonString;
	GetJsonStringFromStruct<FCreateRequest>(request, ContentJsonString);
	TSharedRef<IHttpRequest> Request = PostRequest("/createGame", ContentJsonString, headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UMultiplayerBackendComponent::OnResponseReceived<FCreateJoinResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UMultiplayerBackendComponent::JoinGame(FCallbackBinding callbackBinding)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FCreateJoinResponse"))
		return;
	TMap<FString, FString> headers;
	TSharedRef<IHttpRequest> Request = GetRequest("/joinGame", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UMultiplayerBackendComponent::OnResponseReceived<FCreateJoinResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UMultiplayerBackendComponent::IsServerEmpty(FCallbackBinding callbackBinding)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FIsServerEmptyResponse"))
		return;
	TMap<FString, FString> headers;
	TSharedRef<IHttpRequest> Request = GetRequest("/isServerEmpty", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UMultiplayerBackendComponent::OnResponseReceived<FIsServerEmptyResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UMultiplayerBackendComponent::ServerReady()
{
	TMap<FString, FString> headers;
	TSharedRef<IHttpRequest> Request = PostRequestNoJson("/serverReady", headers);
	Request->ProcessRequest();
}

void UMultiplayerBackendComponent::GetTrackIndex(FCallbackBinding callbackBinding)
{
	if (!CheckIfCallbackIsCorrect(callbackBinding, "FGetTrackIndexResponse"))
		return;
	TMap<FString, FString> headers;
	TSharedRef<IHttpRequest> Request = GetRequest("/getTrackIndex", headers);
	Request->OnProcessRequestComplete().BindUObject(this, &UMultiplayerBackendComponent::OnResponseReceived<FGetTrackIndexResponse>, callbackBinding);
	Request->ProcessRequest();
}

void UMultiplayerBackendComponent::ClientLeft()
{
	TMap<FString, FString> headers;
	TSharedRef<IHttpRequest> Request = PostRequestNoJson("/clientLeft", headers);
	Request->ProcessRequest();
}