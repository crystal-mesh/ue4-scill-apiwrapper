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

#include "ScillApiWrapper/ScillApiChallengesApi.h"

#include "ScillApiWrapper/ScillApiChallengesApiOperations.h"
#include "ScillSDKModule.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace ScillSDK
{

ScillApiChallengesApi::ScillApiChallengesApi()
: Url(TEXT("https://virtserver.swaggerhub.com/4Players-GmbH/scill-gaas/1.0.0"))
{
}

ScillApiChallengesApi::~ScillApiChallengesApi() {}

void ScillApiChallengesApi::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void ScillApiChallengesApi::AddHeaderParam(const FString& Key, const FString& Value)
{
	AdditionalHeaderParams.Add(Key, Value);
}

void ScillApiChallengesApi::ClearHeaderParams()
{
	AdditionalHeaderParams.Reset();
}

bool ScillApiChallengesApi::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogScillSDK, Error, TEXT("ScillApiChallengesApi: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

void ScillApiChallengesApi::SetHttpRetryManager(FHttpRetrySystem::FManager& InRetryManager)
{
	if(RetryManager != &GetHttpRetryManager())
	{
		DefaultRetryManager.Reset();
		RetryManager = &InRetryManager;
	}
}

FHttpRetrySystem::FManager& ScillApiChallengesApi::GetHttpRetryManager()
{
	checkf(RetryManager, TEXT("ScillApiChallengesApi: RetryManager is null.  You may have meant to set it with SetHttpRetryManager first, or you may not be using a custom RetryManager at all."))
	return *RetryManager;
}

FHttpRequestRef ScillApiChallengesApi::CreateHttpRequest(const Request& Request) const
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

void ScillApiChallengesApi::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
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

FHttpRequestPtr ScillApiChallengesApi::ActivatePersonalChallenge(const ActivatePersonalChallengeRequest& Request, const FActivatePersonalChallengeDelegate& Delegate /*= FActivatePersonalChallengeDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnActivatePersonalChallengeResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnActivatePersonalChallengeResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FActivatePersonalChallengeDelegate Delegate) const
{
	ActivatePersonalChallengeResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::CancelPersonalChallenge(const CancelPersonalChallengeRequest& Request, const FCancelPersonalChallengeDelegate& Delegate /*= FCancelPersonalChallengeDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnCancelPersonalChallengeResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnCancelPersonalChallengeResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCancelPersonalChallengeDelegate Delegate) const
{
	CancelPersonalChallengeResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::ClaimPersonalChallengeReward(const ClaimPersonalChallengeRewardRequest& Request, const FClaimPersonalChallengeRewardDelegate& Delegate /*= FClaimPersonalChallengeRewardDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnClaimPersonalChallengeRewardResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnClaimPersonalChallengeRewardResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FClaimPersonalChallengeRewardDelegate Delegate) const
{
	ClaimPersonalChallengeRewardResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::GenerateWebsocketAccessToken(const GenerateWebsocketAccessTokenRequest& Request, const FGenerateWebsocketAccessTokenDelegate& Delegate /*= FGenerateWebsocketAccessTokenDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnGenerateWebsocketAccessTokenResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnGenerateWebsocketAccessTokenResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGenerateWebsocketAccessTokenDelegate Delegate) const
{
	GenerateWebsocketAccessTokenResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::GetActivePersonalChallenges(const GetActivePersonalChallengesRequest& Request, const FGetActivePersonalChallengesDelegate& Delegate /*= FGetActivePersonalChallengesDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnGetActivePersonalChallengesResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnGetActivePersonalChallengesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetActivePersonalChallengesDelegate Delegate) const
{
	GetActivePersonalChallengesResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::GetAllPersonalChallenges(const GetAllPersonalChallengesRequest& Request, const FGetAllPersonalChallengesDelegate& Delegate /*= FGetAllPersonalChallengesDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnGetAllPersonalChallengesResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnGetAllPersonalChallengesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetAllPersonalChallengesDelegate Delegate) const
{
	GetAllPersonalChallengesResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::GetPersonalChallengeById(const GetPersonalChallengeByIdRequest& Request, const FGetPersonalChallengeByIdDelegate& Delegate /*= FGetPersonalChallengeByIdDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnGetPersonalChallengeByIdResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnGetPersonalChallengeByIdResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetPersonalChallengeByIdDelegate Delegate) const
{
	GetPersonalChallengeByIdResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::GetPersonalChallenges(const GetPersonalChallengesRequest& Request, const FGetPersonalChallengesDelegate& Delegate /*= FGetPersonalChallengesDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnGetPersonalChallengesResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnGetPersonalChallengesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetPersonalChallengesDelegate Delegate) const
{
	GetPersonalChallengesResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::GetUnresolvedPersonalChallenges(const GetUnresolvedPersonalChallengesRequest& Request, const FGetUnresolvedPersonalChallengesDelegate& Delegate /*= FGetUnresolvedPersonalChallengesDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnGetUnresolvedPersonalChallengesResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnGetUnresolvedPersonalChallengesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUnresolvedPersonalChallengesDelegate Delegate) const
{
	GetUnresolvedPersonalChallengesResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::ResetUserAppChallenges(const ResetUserAppChallengesRequest& Request, const FResetUserAppChallengesDelegate& Delegate /*= FResetUserAppChallengesDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnResetUserAppChallengesResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnResetUserAppChallengesResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FResetUserAppChallengesDelegate Delegate) const
{
	ResetUserAppChallengesResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr ScillApiChallengesApi::UnlockPersonalChallenge(const UnlockPersonalChallengeRequest& Request, const FUnlockPersonalChallengeDelegate& Delegate /*= FUnlockPersonalChallengeDelegate()*/) const
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

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiChallengesApi::OnUnlockPersonalChallengeResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void ScillApiChallengesApi::OnUnlockPersonalChallengeResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnlockPersonalChallengeDelegate Delegate) const
{
	UnlockPersonalChallengeResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

}
