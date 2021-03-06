/**
 * SCILL API
 * SCILL gives you the tools to activate, retain and grow your user base in your app or game by bringing you features well known in the gaming industry: Gamification. We take care of the services and technology involved so you can focus on your game and content.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@scillgame.com
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#include "ScillApiWrapper/ScillApiLeaderboardsV2ApiOperations.h"

#include "ScillSDKModule.h"
#include "ScillApiWrapper/ScillApiHelpers.h"

#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"
#include "HttpModule.h"
#include "PlatformHttp.h"

namespace ScillSDK
{

FString ScillApiLeaderboardsV2Api::GetLeaderboardV2Request::ComputePath() const
{
	TMap<FString, FStringFormatArg> PathParams = { 
	{ TEXT("leaderboardId"), ToStringFormatArg(LeaderboardId) } };

	FString Path = FString::Format(TEXT("/api/v2/leaderboards/{leaderboardId}"), PathParams);

	TArray<FString> QueryParams;
	if(StartDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("startDate=")) + ToUrlString(StartDate.GetValue()));
	}
	if(EndDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("endDate=")) + ToUrlString(EndDate.GetValue()));
	}
	if(Aggregate.IsSet())
	{
		QueryParams.Add(FString(TEXT("aggregate=")) + ToUrlString(Aggregate.GetValue()));
	}
	if(CurrentPage.IsSet())
	{
		QueryParams.Add(FString(TEXT("currentPage=")) + ToUrlString(CurrentPage.GetValue()));
	}
	if(CurrentPosition.IsSet())
	{
		QueryParams.Add(FString(TEXT("currentPosition=")) + ToUrlString(CurrentPosition.GetValue()));
	}
	if(PageSize.IsSet())
	{
		QueryParams.Add(FString(TEXT("pageSize=")) + ToUrlString(PageSize.GetValue()));
	}
	if(Language.IsSet())
	{
		QueryParams.Add(FString(TEXT("language=")) + ToUrlString(Language.GetValue()));
	}
	Path += TCHAR('?');
	Path += FString::Join(QueryParams, TEXT("&"));

	return Path;
}

void ScillApiLeaderboardsV2Api::GetLeaderboardV2Request::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("GET"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogScillSDK, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ScillApiLeaderboardsV2Api::GetLeaderboardV2Response::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("A Leaderboard object with information about the leaderboard and current rankings"));
		break;
	case 403:
		SetResponseString(TEXT("Unauthorized"));
		break;
	case 404:
		SetResponseString(TEXT("The specified resource was not found"));
		break;
	}
}

bool ScillApiLeaderboardsV2Api::GetLeaderboardV2Response::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

FString ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingRequest::ComputePath() const
{
	TMap<FString, FStringFormatArg> PathParams = { 
	{ TEXT("memberType"), ToStringFormatArg(MemberType) },
	{ TEXT("memberId"), ToStringFormatArg(MemberId) },
	{ TEXT("leaderboardId"), ToStringFormatArg(LeaderboardId) } };

	FString Path = FString::Format(TEXT("/api/v2/leaderboards-members/{memberType}/{memberId}/{leaderboardId}"), PathParams);

	TArray<FString> QueryParams;
	if(StartDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("startDate=")) + ToUrlString(StartDate.GetValue()));
	}
	if(EndDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("endDate=")) + ToUrlString(EndDate.GetValue()));
	}
	if(Aggregate.IsSet())
	{
		QueryParams.Add(FString(TEXT("aggregate=")) + ToUrlString(Aggregate.GetValue()));
	}
	if(Language.IsSet())
	{
		QueryParams.Add(FString(TEXT("language=")) + ToUrlString(Language.GetValue()));
	}
	Path += TCHAR('?');
	Path += FString::Join(QueryParams, TEXT("&"));

	return Path;
}

void ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("GET"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogScillSDK, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("A LeaderboardMemberRankings object with information about the leaderboard and current rankings"));
		break;
	case 403:
		SetResponseString(TEXT("Unauthorized"));
		break;
	case 404:
		SetResponseString(TEXT("The specified resource was not found"));
		break;
	}
}

bool ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

FString ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingsRequest::ComputePath() const
{
	TMap<FString, FStringFormatArg> PathParams = { 
	{ TEXT("memberType"), ToStringFormatArg(MemberType) },
	{ TEXT("memberId"), ToStringFormatArg(MemberId) } };

	FString Path = FString::Format(TEXT("/api/v2/leaderboards-members/{memberType}/{memberId}"), PathParams);

	TArray<FString> QueryParams;
	if(StartDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("startDate=")) + ToUrlString(StartDate.GetValue()));
	}
	if(EndDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("endDate=")) + ToUrlString(EndDate.GetValue()));
	}
	if(Aggregate.IsSet())
	{
		QueryParams.Add(FString(TEXT("aggregate=")) + ToUrlString(Aggregate.GetValue()));
	}
	if(Language.IsSet())
	{
		QueryParams.Add(FString(TEXT("language=")) + ToUrlString(Language.GetValue()));
	}
	Path += TCHAR('?');
	Path += FString::Join(QueryParams, TEXT("&"));

	return Path;
}

void ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingsRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("GET"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogScillSDK, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingsResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("An array of LeaderboardV2MemberRanking objects with information about all the leaderboard and current rankings"));
		break;
	case 403:
		SetResponseString(TEXT("Unauthorized"));
		break;
	case 404:
		SetResponseString(TEXT("The specified resource was not found"));
		break;
	}
}

bool ScillApiLeaderboardsV2Api::GetLeaderboardV2RankingsResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

FString ScillApiLeaderboardsV2Api::GetLeaderboardsV2Request::ComputePath() const
{
	FString Path(TEXT("/api/v2/leaderboards"));
	TArray<FString> QueryParams;
	if(StartDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("startDate=")) + ToUrlString(StartDate.GetValue()));
	}
	if(EndDate.IsSet())
	{
		QueryParams.Add(FString(TEXT("endDate=")) + ToUrlString(EndDate.GetValue()));
	}
	if(Aggregate.IsSet())
	{
		QueryParams.Add(FString(TEXT("aggregate=")) + ToUrlString(Aggregate.GetValue()));
	}
	if(CurrentPage.IsSet())
	{
		QueryParams.Add(FString(TEXT("currentPage=")) + ToUrlString(CurrentPage.GetValue()));
	}
	if(CurrentPosition.IsSet())
	{
		QueryParams.Add(FString(TEXT("currentPosition=")) + ToUrlString(CurrentPosition.GetValue()));
	}
	if(PageSize.IsSet())
	{
		QueryParams.Add(FString(TEXT("pageSize=")) + ToUrlString(PageSize.GetValue()));
	}
	if(Language.IsSet())
	{
		QueryParams.Add(FString(TEXT("language=")) + ToUrlString(Language.GetValue()));
	}
	Path += TCHAR('?');
	Path += FString::Join(QueryParams, TEXT("&"));

	return Path;
}

void ScillApiLeaderboardsV2Api::GetLeaderboardsV2Request::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("GET"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogScillSDK, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ScillApiLeaderboardsV2Api::GetLeaderboardsV2Response::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("A Leaderboard object with information about the leaderboard and current rankings"));
		break;
	case 403:
		SetResponseString(TEXT("Unauthorized"));
		break;
	case 404:
		SetResponseString(TEXT("The specified resource was not found"));
		break;
	}
}

bool ScillApiLeaderboardsV2Api::GetLeaderboardsV2Response::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

FString ScillApiLeaderboardsV2Api::ResetLeaderboardV2RankingsRequest::ComputePath() const
{
	TMap<FString, FStringFormatArg> PathParams = { 
	{ TEXT("appId"), ToStringFormatArg(AppId) },
	{ TEXT("leaderboardId"), ToStringFormatArg(LeaderboardId) } };

	FString Path = FString::Format(TEXT("/api/v2/leaderboards-reset/{appId}/{leaderboardId}"), PathParams);

	return Path;
}

void ScillApiLeaderboardsV2Api::ResetLeaderboardV2RankingsRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("DELETE"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogScillSDK, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ScillApiLeaderboardsV2Api::ResetLeaderboardV2RankingsResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("The action has been successful"));
		break;
	case 403:
		SetResponseString(TEXT("Unauthorized"));
		break;
	case 404:
		SetResponseString(TEXT("The specified resource was not found"));
		break;
	}
}

bool ScillApiLeaderboardsV2Api::ResetLeaderboardV2RankingsResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

}
