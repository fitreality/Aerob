// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BackendTypes.generated.h"


UENUM(BlueprintType)
enum class ETrainingPhase : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	WarmUp UMETA(DisplayName = "warm up"),
	Training UMETA(DisplayName = "training"),
	CoolDown UMETA(DisplayName = "cooldown"),
	TestPMax UMETA(DisplayName = "test pmax"),
	TestVo2Max  UMETA(DisplayName = "test pmax")
};

//--------------------------ACTIVITIES----------------------------------//
#pragma region

USTRUCT(BlueprintType)
struct FGameData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game data")
		bool isArcadeMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game data")
		FString trainingUnitGuid;
};

USTRUCT(BlueprintType)
struct FTrainingData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training data")
		FString trainingScenarioType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training data")
		FString trainingUnitGuid;
};

USTRUCT(BlueprintType)
struct FFriendsChallengeRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> guids;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isHandicapGranted;
};

USTRUCT(BlueprintType)
struct FGhostsChallengeRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> guids;
};

USTRUCT(BlueprintType)
struct FGhostPosition {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int timeInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float z;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float absoluteSpilineDistanceInMeters;
};

USTRUCT(BlueprintType)
struct FGhostRow {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString mapId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int mapCompletionTimeInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGhostPosition> ghostPositions;
};

USTRUCT(BlueprintType)
struct FGhostRowTemp {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString mapId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int mapCompletionTimeInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGhostPosition> ghostPositions;
};

USTRUCT(BlueprintType)
struct FGhostData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int itemIntervalInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGhostRow> ghostRows;
};

USTRUCT(BlueprintType)
struct FGhostDataTemp {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int itemIntervalInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGhostRowTemp> ghostRows;
};

USTRUCT(BlueprintType)
struct FActivityPayloadItem {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int durationInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float realSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float inGameSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float rawSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float realDistancePassed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float inGameDistancePassed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int kcalBurnt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int cadence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int heartRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETrainingPhase trainingPhaseType;
};

USTRUCT(BlueprintType)
struct FStartActivityRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString accountGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString stationSessionGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTrainingData trainingData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameData gameData;
};
USTRUCT(BlueprintType)
struct FStartActivityResponse {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString gameGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString startDateTime;
};

USTRUCT(BlueprintType)
struct FStartTrainingUnitActivityRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isArcadeMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString trainingUnitGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localStartDateTime;
};

USTRUCT(BlueprintType)
struct FStartFreeRideActivityRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isArcadeMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localStartDateTime;
};
USTRUCT(BlueprintType)
struct FStartTestingUnitActivityRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString testingUnitGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localStartDateTime;
};
USTRUCT(BlueprintType)
struct FStartChallengeActivityRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isArcadeMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString mapSetGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localStartDateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FFriendsChallengeRequest friends;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGhostsChallengeRequest ghosts;
};

USTRUCT(BlueprintType)
struct FGameSummary {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float durationInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float averageRealSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float averageInGameSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float averageRawSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float averageHeartRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float realDistancePassed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float inGameDistancePassed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float kcalBurnt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> unrankedReasons;
};

USTRUCT(BlueprintType)
struct FEndActivityRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString gameGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int itemIntervalInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameSummary gameSummary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localEndDateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FActivityPayloadItem> payloadItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGhostDataTemp ghostData;
};

USTRUCT(BlueprintType)
struct FEndActivityResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString gameGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString startDateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString endDateTime;
};

USTRUCT(BlueprintType)
struct FAddGhostPayloadRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString gameGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGhostDataTemp ghostData;
};

USTRUCT(BlueprintType)
struct FAddGamePayloadRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString gameGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int itemIntervalInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FActivityPayloadItem> payloadItems;
};

USTRUCT(BlueprintType)
struct FStartSessionForGuestResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString stationSessionGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int bookingDurationMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isBookingRequired;
};


#pragma endregion activities endpoints

//--------------------------MAPS----------------------------------//

#pragma region 

UENUM(BlueprintType)
enum class EMapSetDifficulty : uint8
{
	None UMETA(DisplayName = "None"),
	Easy UMETA(DisplayName = "Easy"),
	Medium UMETA(DisplayName = "Medium"),
	Hard UMETA(DisplayName = "Hard")
};

USTRUCT(BlueprintType)
struct FMapQuery {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int completionTimeInMinutes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString photoUrl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isAvailableInFreeRide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isAvailableForMapSets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EMapSetDifficulty difficulty;
};

USTRUCT(BlueprintType)
struct FGetMapsResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMapQuery> maps;
};

USTRUCT(BlueprintType)
struct FMapOrder {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int order;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isForward;
};

USTRUCT(BlueprintType)
struct FMapSetQuery {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int averageCompletionTimeInMinutes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isAvailableInBattles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString promoGraphicUrl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EMapSetDifficulty difficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMapOrder> maps;
};

UENUM(BlueprintType)
enum class EGhostType : uint8
{
	PlayersBest  UMETA(DisplayName = "PlayersBest"),
	PlayersLatest	UMETA(DisplayName = "PlayersLatest"),
	WorldsBest	UMETA(DisplayName = "WorldsBest"),
	WorldsLatest  UMETA(DisplayName = "WorldsLatest"),
	FriendsBest	UMETA(DisplayName = "FriendsBest"),
	BetterThanPlayerAverage	UMETA(DisplayName = "BetterThanPlayerAverage"),
	SecondDecile	UMETA(DisplayName = "SecondDecile"),
	FourthDecile 	UMETA(DisplayName = "FourthDecile"),
	SixthDecile	UMETA(DisplayName = "SixthDecile"),
	EighthDecile 	UMETA(DisplayName = "EighthDecile"),
	OneDecileBetterThanPlayersBest	UMETA(DisplayName = "OneDecileBetterThanPlayersBest")
};

USTRUCT(BlueprintType)
struct FGetMapSetsResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMapSetQuery> mapSets;
};

USTRUCT(BlueprintType)
struct FGhostItem {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int completionTimeInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EGhostType ghostType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString gamerNickname;
};

USTRUCT(BlueprintType)
struct FGetGhostsForMapSetResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGhostItem> ghosts;
};

USTRUCT(BlueprintType)
struct FGetGhostPayloadResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ghostGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int itemIntervalInMiliseconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGhostRow> ghostRows;
};

USTRUCT(BlueprintType)
struct FGetGhostsPayloadsResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGetGhostPayloadResponse> payloads;
};

#pragma endregion maps endpoints

//--------------------------STATIONS----------------------------------//

#pragma region

UENUM(BlueprintType)
enum class EStationType : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	Fitness UMETA(DisplayName = "Fitness"),
	Aerobic UMETA(DisplayName = "Aerobic")
};

UENUM(BlueprintType)
enum class EAerobicEquipmentType : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	UprightBike UMETA(DisplayName = "UprightBike"),
	RecumbentBike UMETA(DisplayName = "RecumbentBike"),
	Stepper UMETA(DisplayName = "Stepper"),
	EllipticalCrossTrainer UMETA(DisplayName = "EllipticalCrossTrainer"),
	Rower UMETA(DisplayName = "Rower")
};

USTRUCT(BlueprintType)
struct FAerobicEquipmentParameters {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int lowestLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int highestLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maxWatsPossibleToGenerate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasHeartRateMeasurement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int lowerBoundryOfOptimalRevolutionsPerMinuteRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int higherBoundryOfOptimalRevolutionsPerMinuteRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float decreaseLevelTimeFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float increaseLevelTimeFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float resistanceValueOnLowestLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float resistanceValueOnHighestLevel;
};

USTRUCT(BlueprintType)
struct FAerobicEquipment {
	GENERATED_BODY()
	//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	FString guid;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	FString consoleIdentifier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString machineIdentifier;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAerobicEquipmentType aerobicEquipmentType;
};

UENUM(BlueprintType)
enum class EProcessingUnitType : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	Bridgeless UMETA(DisplayName = "Fitness"),
	WithBridge  UMETA(DisplayName = "Aerobic")
};

USTRUCT(BlueprintType)
struct FProcessingUnit {
	GENERATED_BODY()
		/*	UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FString identifier;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FString bluetoothServerMacAddress;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			EProcessingUnitType processingUnitType;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localNetworkIp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString localNetworkName;
};

USTRUCT(BlueprintType)
struct FTestingUnit {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString trainingScenarioName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int durationInSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAerobicEquipmentType aerobicEquipmentType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString guid;
};

USTRUCT(BlueprintType)
struct FTestingUnitsResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FTestingUnit> testingUnits;
};

USTRUCT(BlueprintType)
struct FStationResponseParameters {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int lowestLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int highestLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxWatsPossibleToGenerate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasHeartRateMeasurement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int lowerBoundryOfOptimalRevolutionsPerMinuteRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int higherBoundryOfOptimalRevolutionsPerMinuteRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float decreaseLevelTimeFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float increaseLevelTimeFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float resistanceValueOnLowestLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float resistanceValueOnHighestLevel;
};


USTRUCT(BlueprintType)
struct FGetStationResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EStationType stationType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAerobicEquipment aerobicEquipment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FProcessingUnit processingUnit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTestingUnitsResponse testingUnits;
};

USTRUCT(BlueprintType)
struct FSession {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString sessionGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString endDateTimeInUtc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString accountGuid;
};

UENUM(BlueprintType)
enum class EBodyModel : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	Masculine UMETA(DisplayName = "Masculine"),
	Feminine   UMETA(DisplayName = "Feminine")
};

USTRUCT(BlueprintType)
struct FFitnessHighScore {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int movesCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int movesAccuracy;
};

USTRUCT(BlueprintType)
struct FAerobicHighScoreOnEquipment {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAerobicEquipmentType aerobicEquipmentType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float distanceTraveledInKilometers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxSpeedInKilometersPerHour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxPowerInWatts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maxHeartRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int averagePaceInSecondsPerKilometer;
};

USTRUCT(BlueprintType)
struct FAerobicHighScore {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float dailyDistanceTraveledInKilometers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int aerobicHighScoreOnEquipment;
};

USTRUCT(BlueprintType)
struct FAthleteHighScores {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int dailyCaloriesBurnt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int dailyTrainingTimeInSeconds;
};

USTRUCT(BlueprintType)
struct FAthleteMeasurments {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float weightInKilograms;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int heightInCentimeters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float vo2Max;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maximalHeartRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int powerForLactateThresholdInWattsOnUprightBike;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int averagePowerForVo2MaxInWattsOnUprightBike;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maximalPowerInWattsOnUprightBike;
};

USTRUCT(BlueprintType)
struct FGamerAvatarQuery {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString renderUrl;
};

USTRUCT(BlueprintType)
struct FGamerEndedGamesStatisticQuery {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int endedRacesCount;
};

USTRUCT(BlueprintType)
struct FGamerCalibrationDataQuery {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int calibrationHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int calibrationHorizontalRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int calibrationVerticalRange;
};

USTRUCT(BlueprintType)
struct FGamer {
	GENERATED_BODY()
	/*	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EBodyModel bodyModel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString birthDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int age;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString nickname;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float energyCoinsAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString iconGraphicUrl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAthleteHighScores highScores;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAthleteMeasurments measurements;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGamerEndedGamesStatisticQuery endedGamesStatistics;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGamerCalibrationDataQuery calibration;*/
};

UENUM(BlueprintType)
enum class ETrainingType : uint8
{
	Ivalid  UMETA(DisplayName = "Invalid data"),
	Aerobic UMETA(DisplayName = "Aerobic"),
	Fitness	UMETA(DisplayName = "Fitness ")
};

USTRUCT(BlueprintType)
struct FNextTrainingUnitContext {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETrainingType trainingType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAerobicEquipmentType aerobicEquipmentType;
};

USTRUCT(BlueprintType)
struct FActiveSession {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSession session;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGamer gamer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FNextTrainingUnitContext trainingUnit;
};

USTRUCT(BlueprintType)
struct FStationContextResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasActiveSession;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FActiveSession activeSession;
};

#pragma endregion stations endpoints

//--------------------------TRAINING PLANS----------------------------------//

#pragma region

UENUM(BlueprintType)
enum class EAerobicMoveType : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	HeartRateAerobicMove UMETA(DisplayName = "HeartRateAerobicMove"),
	PowerAerobicMove  UMETA(DisplayName = "PowerAerobicMove ")
};

USTRUCT(BlueprintType)
struct FAerobicMoveResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAerobicMoveType aerobicMoveType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int durationInSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int valueMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int valueMax;
};

USTRUCT(BlueprintType)
struct FAerobicSetResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETrainingPhase trainingPhase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAerobicMoveResponse> aerobicMoves;
};

USTRUCT(BlueprintType)
struct FAerobicTrainingUnitResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAerobicEquipmentType aerobicEquipmentType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int powerChangeScenarioPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int heartRateChangeScenarioPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAerobicSetResponse> aerobicSets;
};


UENUM(BlueprintType)
enum class EFitnesssChallenge : uint8
{
	Ivalid UMETA(DisplayName = "Invalid data"),
	Exercising UMETA(DisplayName = "Exercising"),
	Shooting UMETA(DisplayName = "Shooting"),
	Boxing UMETA(DisplayName = "Boxing"),
	Slashing  UMETA(DisplayName = "Slashing ")
};
USTRUCT(BlueprintType)
struct FFitnessMove {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		int repetitionNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		int moveNumber;
};

USTRUCT(BlueprintType)
struct FFitnessExercise {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		EFitnesssChallenge fitnesssChallenge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		int durationInSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		int beatsPerMinute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		TArray<FFitnessMove> fitnessMoves;
};

USTRUCT(BlueprintType)
struct FFitnessSet {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		ETrainingPhase trainingPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		TArray<FFitnessExercise> fitnessExercises;
};

USTRUCT(BlueprintType)
struct FFitnessUnit {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		TArray<FFitnessSet> fitnessSets;
};

USTRUCT(BlueprintType)
struct FFitnessTraining {

	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		FString trainingGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training plan")
		TArray<FFitnessSet> fitnessSets;
};

#pragma endregion TrainingPlans endpoints

//--------------------------TRAININGS----------------------------------//

USTRUCT(BlueprintType)
struct FGetTestingUnitScenarioResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAerobicSetResponse> aerobicSets;
};


//--------------------------USERS----------------------------------//

USTRUCT(BlueprintType)
struct FCalibrateGamerRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString accountGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int calibrationHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int calibrationVerticalRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int calibrationHorizontalRange;
};

USTRUCT(BlueprintType)
struct FActiveUser {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		FString userGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		FString nickname;
};

USTRUCT(BlueprintType)
struct FAerobicGameSummary {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		FString stationGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		FString userGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		FString nickname;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		int score;
};

USTRUCT(BlueprintType)
struct FleaderboardPosition {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		int leaderboardPosition;
};

USTRUCT(BlueprintType)
struct FRemoveUser {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IHRSA")
		FString stationGuid;
};

//----------------Local backend--------------------------------------------------------------------------//

USTRUCT(BlueprintType)
struct FCreateRequest {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TrackIndex;
};

USTRUCT(BlueprintType)
struct FCreateJoinResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Port;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsReady;
	
};

USTRUCT(BlueprintType)
struct FIsServerEmptyResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsServerEmpty;
};

USTRUCT(BlueprintType)
struct FGetTrackIndexResponse {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TrackIndex;
};