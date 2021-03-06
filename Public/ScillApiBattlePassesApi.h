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

class SCILLSDK_API ScillApiBattlePassesApi
{
public:
	ScillApiBattlePassesApi();
	~ScillApiBattlePassesApi();

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

	class ActivateBattlePassLevelRequest;
	class ActivateBattlePassLevelResponse;
	class ClaimBattlePassLevelRewardRequest;
	class ClaimBattlePassLevelRewardResponse;
	class GetActiveBattlePassesRequest;
	class GetActiveBattlePassesResponse;
	class GetAllBattlePassLevelsRequest;
	class GetAllBattlePassLevelsResponse;
	class GetBattlePassRequest;
	class GetBattlePassResponse;
	class GetBattlePassLevelsRequest;
	class GetBattlePassLevelsResponse;
	class GetBattlePassesRequest;
	class GetBattlePassesResponse;
	class GetUnlockedBattlePassesRequest;
	class GetUnlockedBattlePassesResponse;
	class UnlockBattlePassRequest;
	class UnlockBattlePassResponse;
	
    DECLARE_DELEGATE_OneParam(FActivateBattlePassLevelDelegate, const ActivateBattlePassLevelResponse&);
    DECLARE_DELEGATE_OneParam(FClaimBattlePassLevelRewardDelegate, const ClaimBattlePassLevelRewardResponse&);
    DECLARE_DELEGATE_OneParam(FGetActiveBattlePassesDelegate, const GetActiveBattlePassesResponse&);
    DECLARE_DELEGATE_OneParam(FGetAllBattlePassLevelsDelegate, const GetAllBattlePassLevelsResponse&);
    DECLARE_DELEGATE_OneParam(FGetBattlePassDelegate, const GetBattlePassResponse&);
    DECLARE_DELEGATE_OneParam(FGetBattlePassLevelsDelegate, const GetBattlePassLevelsResponse&);
    DECLARE_DELEGATE_OneParam(FGetBattlePassesDelegate, const GetBattlePassesResponse&);
    DECLARE_DELEGATE_OneParam(FGetUnlockedBattlePassesDelegate, const GetUnlockedBattlePassesResponse&);
    DECLARE_DELEGATE_OneParam(FUnlockBattlePassDelegate, const UnlockBattlePassResponse&);
    
    FHttpRequestPtr ActivateBattlePassLevel(const ActivateBattlePassLevelRequest& Request, const FActivateBattlePassLevelDelegate& Delegate = FActivateBattlePassLevelDelegate()) const;
    FHttpRequestPtr ClaimBattlePassLevelReward(const ClaimBattlePassLevelRewardRequest& Request, const FClaimBattlePassLevelRewardDelegate& Delegate = FClaimBattlePassLevelRewardDelegate()) const;
    FHttpRequestPtr GetActiveBattlePasses(const GetActiveBattlePassesRequest& Request, const FGetActiveBattlePassesDelegate& Delegate = FGetActiveBattlePassesDelegate()) const;
    FHttpRequestPtr GetAllBattlePassLevels(const GetAllBattlePassLevelsRequest& Request, const FGetAllBattlePassLevelsDelegate& Delegate = FGetAllBattlePassLevelsDelegate()) const;
    FHttpRequestPtr GetBattlePass(const GetBattlePassRequest& Request, const FGetBattlePassDelegate& Delegate = FGetBattlePassDelegate()) const;
    FHttpRequestPtr GetBattlePassLevels(const GetBattlePassLevelsRequest& Request, const FGetBattlePassLevelsDelegate& Delegate = FGetBattlePassLevelsDelegate()) const;
    FHttpRequestPtr GetBattlePasses(const GetBattlePassesRequest& Request, const FGetBattlePassesDelegate& Delegate = FGetBattlePassesDelegate()) const;
    FHttpRequestPtr GetUnlockedBattlePasses(const GetUnlockedBattlePassesRequest& Request, const FGetUnlockedBattlePassesDelegate& Delegate = FGetUnlockedBattlePassesDelegate()) const;
    FHttpRequestPtr UnlockBattlePass(const UnlockBattlePassRequest& Request, const FUnlockBattlePassDelegate& Delegate = FUnlockBattlePassDelegate()) const;
    
private:
    void OnActivateBattlePassLevelResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FActivateBattlePassLevelDelegate Delegate) const;
    void OnClaimBattlePassLevelRewardResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FClaimBattlePassLevelRewardDelegate Delegate) const;
    void OnGetActiveBattlePassesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetActiveBattlePassesDelegate Delegate) const;
    void OnGetAllBattlePassLevelsResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetAllBattlePassLevelsDelegate Delegate) const;
    void OnGetBattlePassResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetBattlePassDelegate Delegate) const;
    void OnGetBattlePassLevelsResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetBattlePassLevelsDelegate Delegate) const;
    void OnGetBattlePassesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetBattlePassesDelegate Delegate) const;
    void OnGetUnlockedBattlePassesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUnlockedBattlePassesDelegate Delegate) const;
    void OnUnlockBattlePassResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnlockBattlePassDelegate Delegate) const;
    
	FHttpRequestRef CreateHttpRequest(const Request& Request) const;
	bool IsValid() const;
	void HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const;

	FString Url;
	TMap<FString,FString> AdditionalHeaderParams;
	mutable FHttpRetrySystem::FManager* RetryManager = nullptr;
	mutable TUniquePtr<HttpRetryManager> DefaultRetryManager;
};

}
