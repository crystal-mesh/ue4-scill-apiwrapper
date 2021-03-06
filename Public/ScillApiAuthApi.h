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

#pragma once

#include "CoreMinimal.h"
#include "ScillApiBaseModel.h"

namespace ScillSDK
{

class SCILLSDK_API ScillApiAuthApi
{
public:
	ScillApiAuthApi();
	~ScillApiAuthApi();

	/* Sets the URL Endpoint.
	* Note: several fallback endpoints can be configured in request retry policies, see Request::SetShouldRetry */
	void SetURL(const FString& Url);

	/* Adds global header params to all requests */
	void AddHeaderParam(const FString& Key, const FString& Value);
	void ClearHeaderParams();

	/* Sets the retry manager to the user-defined retry manager. User must manage the lifetime of the retry manager.
	* If no retry manager is specified and a request needs retries, a default retry manager will be used.
	* See also: Request::SetShouldRetry */
	void SetHttpRetryManager(FHttpRetrySystem::FManager& RetryManager);
	FHttpRetrySystem::FManager& GetHttpRetryManager();

	class GenerateAccessTokenRequest;
	class GenerateAccessTokenResponse;
	class GetLeaderboardNotificationTopicRequest;
	class GetLeaderboardNotificationTopicResponse;
	class GetUserBattlePassNotificationTopicRequest;
	class GetUserBattlePassNotificationTopicResponse;
	class GetUserChallengeNotificationTopicRequest;
	class GetUserChallengeNotificationTopicResponse;
	class GetUserChallengesNotificationTopicRequest;
	class GetUserChallengesNotificationTopicResponse;
	class GetUserInfoRequest;
	class GetUserInfoResponse;
	class SetUserInfoRequest;
	class SetUserInfoResponse;
	
    DECLARE_DELEGATE_OneParam(FGenerateAccessTokenDelegate, const GenerateAccessTokenResponse&);
    DECLARE_DELEGATE_OneParam(FGetLeaderboardNotificationTopicDelegate, const GetLeaderboardNotificationTopicResponse&);
    DECLARE_DELEGATE_OneParam(FGetUserBattlePassNotificationTopicDelegate, const GetUserBattlePassNotificationTopicResponse&);
    DECLARE_DELEGATE_OneParam(FGetUserChallengeNotificationTopicDelegate, const GetUserChallengeNotificationTopicResponse&);
    DECLARE_DELEGATE_OneParam(FGetUserChallengesNotificationTopicDelegate, const GetUserChallengesNotificationTopicResponse&);
    DECLARE_DELEGATE_OneParam(FGetUserInfoDelegate, const GetUserInfoResponse&);
    DECLARE_DELEGATE_OneParam(FSetUserInfoDelegate, const SetUserInfoResponse&);
    
    FHttpRequestPtr GenerateAccessToken(const GenerateAccessTokenRequest& Request, const FGenerateAccessTokenDelegate& Delegate = FGenerateAccessTokenDelegate()) const;
    FHttpRequestPtr GetLeaderboardNotificationTopic(const GetLeaderboardNotificationTopicRequest& Request, const FGetLeaderboardNotificationTopicDelegate& Delegate = FGetLeaderboardNotificationTopicDelegate()) const;
    FHttpRequestPtr GetUserBattlePassNotificationTopic(const GetUserBattlePassNotificationTopicRequest& Request, const FGetUserBattlePassNotificationTopicDelegate& Delegate = FGetUserBattlePassNotificationTopicDelegate()) const;
    FHttpRequestPtr GetUserChallengeNotificationTopic(const GetUserChallengeNotificationTopicRequest& Request, const FGetUserChallengeNotificationTopicDelegate& Delegate = FGetUserChallengeNotificationTopicDelegate()) const;
    FHttpRequestPtr GetUserChallengesNotificationTopic(const GetUserChallengesNotificationTopicRequest& Request, const FGetUserChallengesNotificationTopicDelegate& Delegate = FGetUserChallengesNotificationTopicDelegate()) const;
    FHttpRequestPtr GetUserInfo(const GetUserInfoRequest& Request, const FGetUserInfoDelegate& Delegate = FGetUserInfoDelegate()) const;
    FHttpRequestPtr SetUserInfo(const SetUserInfoRequest& Request, const FSetUserInfoDelegate& Delegate = FSetUserInfoDelegate()) const;
    
private:
    void OnGenerateAccessTokenResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGenerateAccessTokenDelegate Delegate) const;
    void OnGetLeaderboardNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLeaderboardNotificationTopicDelegate Delegate) const;
    void OnGetUserBattlePassNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserBattlePassNotificationTopicDelegate Delegate) const;
    void OnGetUserChallengeNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserChallengeNotificationTopicDelegate Delegate) const;
    void OnGetUserChallengesNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserChallengesNotificationTopicDelegate Delegate) const;
    void OnGetUserInfoResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserInfoDelegate Delegate) const;
    void OnSetUserInfoResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetUserInfoDelegate Delegate) const;
    
	FHttpRequestRef CreateHttpRequest(const Request& Request) const;
	bool IsValid() const;
	void HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const;

	FString Url;
	TMap<FString,FString> AdditionalHeaderParams;
	mutable FHttpRetrySystem::FManager* RetryManager = nullptr;
	mutable TUniquePtr<HttpRetryManager> DefaultRetryManager;
};

}
