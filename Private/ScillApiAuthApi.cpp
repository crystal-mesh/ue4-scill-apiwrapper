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

#include "ScillApiWrapper/ScillApiAuthApi.h"

#include "ScillApiWrapper/ScillApiAuthApiOperations.h"
#include "ScillSDKModule.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace ScillSDK
{

ScillApiAuthApi::ScillApiAuthApi()
: Url(TEXT("https://virtserver.swaggerhub.com/4Players-GmbH/scill-gaas/1.0.0"))
{
}

ScillApiAuthApi::~ScillApiAuthApi() {}

void ScillApiAuthApi::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void ScillApiAuthApi::AddHeaderParam(const FString& Key, const FString& Value)
{
	AdditionalHeaderParams.Add(Key, Value);
}

void ScillApiAuthApi::ClearHeaderParams()
{
	AdditionalHeaderParams.Reset();
}

bool ScillApiAuthApi::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogScillSDK, Error, TEXT("ScillApiAuthApi: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

void ScillApiAuthApi::SetHttpRetryManager(FHttpRetrySystem::FManager& InRetryManager)
{
	if(RetryManager != &GetHttpRetryManager())
	{
		DefaultRetryManager.Reset();
		RetryManager = &InRetryManager;
	}
}

FHttpRetrySystem::FManager& ScillApiAuthApi::GetHttpRetryManager()
{
	checkf(RetryManager, TEXT("ScillApiAuthApi: RetryManager is null.  You may have meant to set it with SetHttpRetryManager first, or you may not be using a custom RetryManager at all."))
	return *RetryManager;
}

FHttpRequestRef ScillApiAuthApi::CreateHttpRequest(const Request& Request) const
{
	if (!Request.GetRetryParams().IsSet())
	{
		return FHttpModule::Get().CreateRequest();
	}
	else
	{
		if (!RetryManager)
		{
			// Create default retry manager if none was specified
			DefaultRetryManager = MakeUnique<HttpRetryManager>(6, 60);
			RetryManager = DefaultRetryManager.Get();
		}

		const HttpRetryParams& Params = Request.GetRetryParams().GetValue();
		return RetryManager->CreateRequest(Params.RetryLimitCountOverride, Params.RetryTimeoutRelativeSecondsOverride, Params.RetryResponseCodes, Params.RetryVerbs, Params.RetryDomains);
	}
}

void ScillApiAuthApi::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
{
	InOutResponse.SetHttpResponse(HttpResponse);
	InOutResponse.SetSuccessful(bSucceeded);

	if (bSucceeded && HttpResponse.IsValid())
	{
		InOutResponse.SetHttpResponseCode((EHttpResponseCodes::Type)HttpResponse->GetResponseCode());
		FString ContentType = HttpResponse->GetContentType();
		FString Content;

		if (ContentType.IsEmpty())
		{
			return; // Nothing to parse
		}
		else if (ContentType.StartsWith(TEXT("application/json")) || ContentType.StartsWith("text/json"))
		{
			Content = HttpResponse->GetContentAsString();

			TSharedPtr<FJsonValue> JsonValue;
			auto Reader = TJsonReaderFactory<>::Create(Content);

			if (FJsonSerializer::Deserialize(Reader, JsonValue) && JsonValue.IsValid())
			{
				if (InOutResponse.FromJson(JsonValue))
					return; // Successfully parsed
			}
		}
		else if(ContentType.StartsWith(TEXT("text/plain")))
		{
			Content = HttpResponse->GetContentAsString();
			InOutResponse.SetResponseString(Content);
			return; // Successfully parsed
		}

		// Report the parse error but do not mark the request as unsuccessful. Data could be partial or malformed, but the request succeeded.
		UE_LOG(LogScillSDK, Error, TEXT("Failed to deserialize Http response content (type:%s):\n%s"), *ContentType , *Content);
		return;
	}

	// By default, assume we failed to establish connection
	InOutResponse.SetHttpResponseCode(EHttpResponseCodes::RequestTimeout);
}

FHttpRequestPtr ScillApiAuthApi::GenerateAccessToken(const GenerateAccessTokenRequest& Request, const FGenerateAccessTokenDelegate& Delegate /*= FGenerateAccessTokenDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnGenerateAccessTokenResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnGenerateAccessTokenResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGenerateAccessTokenDelegate Delegate) const
{
	GenerateAccessTokenResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiAuthApi::GetLeaderboardNotificationTopic(const GetLeaderboardNotificationTopicRequest& Request, const FGetLeaderboardNotificationTopicDelegate& Delegate /*= FGetLeaderboardNotificationTopicDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnGetLeaderboardNotificationTopicResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnGetLeaderboardNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLeaderboardNotificationTopicDelegate Delegate) const
{
	GetLeaderboardNotificationTopicResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiAuthApi::GetUserBattlePassNotificationTopic(const GetUserBattlePassNotificationTopicRequest& Request, const FGetUserBattlePassNotificationTopicDelegate& Delegate /*= FGetUserBattlePassNotificationTopicDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnGetUserBattlePassNotificationTopicResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnGetUserBattlePassNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserBattlePassNotificationTopicDelegate Delegate) const
{
	GetUserBattlePassNotificationTopicResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiAuthApi::GetUserChallengeNotificationTopic(const GetUserChallengeNotificationTopicRequest& Request, const FGetUserChallengeNotificationTopicDelegate& Delegate /*= FGetUserChallengeNotificationTopicDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnGetUserChallengeNotificationTopicResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnGetUserChallengeNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserChallengeNotificationTopicDelegate Delegate) const
{
	GetUserChallengeNotificationTopicResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiAuthApi::GetUserChallengesNotificationTopic(const GetUserChallengesNotificationTopicRequest& Request, const FGetUserChallengesNotificationTopicDelegate& Delegate /*= FGetUserChallengesNotificationTopicDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnGetUserChallengesNotificationTopicResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnGetUserChallengesNotificationTopicResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserChallengesNotificationTopicDelegate Delegate) const
{
	GetUserChallengesNotificationTopicResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiAuthApi::GetUserInfo(const GetUserInfoRequest& Request, const FGetUserInfoDelegate& Delegate /*= FGetUserInfoDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnGetUserInfoResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnGetUserInfoResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserInfoDelegate Delegate) const
{
	GetUserInfoResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiAuthApi::SetUserInfo(const SetUserInfoRequest& Request, const FSetUserInfoDelegate& Delegate /*= FSetUserInfoDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiAuthApi::OnSetUserInfoResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiAuthApi::OnSetUserInfoResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetUserInfoDelegate Delegate) const
{
	SetUserInfoResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

}
