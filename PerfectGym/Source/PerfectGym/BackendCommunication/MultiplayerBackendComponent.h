// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BackendCommunication/WebCommunicationBaseComponent.h"
#include "BackendCommunication/BackendTypes.h"
#include "MultiplayerBackendComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), config = Game)
class PERFECTGYM_API UMultiplayerBackendComponent : public UWebCommunicationBaseComponent
{
	GENERATED_BODY()


	
public:
	//----------------Local backend--------------------------------------------------------------------------//
	UMultiplayerBackendComponent();
//Response type: FCreateJoinResponse
	UFUNCTION(BlueprintCallable, Category = "Local backend")
		void CreateGame(FCreateRequest request, FCallbackBinding callbackBinding);

	//Response type: FCreateJoinResponse
	UFUNCTION(BlueprintCallable, Category = "Local backend")
		void JoinGame(FCallbackBinding callbackBinding);

	//Response type: FIsServerEmptyResponse
	UFUNCTION(BlueprintCallable, Category = "Local backend")
		void IsServerEmpty(FCallbackBinding callbackBinding);

	//There's no response
	UFUNCTION(BlueprintCallable, Category = "Local backend")
		void ServerReady();

	//Response type: FGetTrackIndexResponse
	UFUNCTION(BlueprintCallable, Category = "Local backend")
		void GetTrackIndex(FCallbackBinding callbackBinding);

	//There's no response
	UFUNCTION(BlueprintCallable, Category = "Local backend")
		void ClientLeft();

protected:
	UPROPERTY(Config, BlueprintReadOnly)
	FString localMasterServerIp;
	UPROPERTY(Config, BlueprintReadOnly)
	FString localMasterServerPort;
};
