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

#include "ScillApiWrapper/ScillApiBaseModel.h"

namespace ScillSDK
{

bool HttpRetryManager::Tick(float DeltaTime)
{
	FManager::Update();
	return true;
}

HttpRetryParams::HttpRetryParams(const FRetryLimitCountSetting& InRetryLimitCountOverride /*= FRetryLimitCountSetting()*/,
    const FRetryTimeoutRelativeSecondsSetting& InRetryTimeoutRelativeSecondsOverride /*= FRetryTimeoutRelativeSecondsSetting()*/,
    const FRetryResponseCodes& InRetryResponseCodes /*= FRetryResponseCodes()*/,
    const FRetryVerbs& InRetryVerbs /*= FRetryVerbs()*/,
    const FRetryDomainsPtr& InRetryDomains /*= FRetryDomainsPtr() */)
    : RetryLimitCountOverride(InRetryLimitCountOverride)
    , RetryTimeoutRelativeSecondsOverride(InRetryTimeoutRelativeSecondsOverride)
    , RetryResponseCodes(InRetryResponseCodes)
    , RetryVerbs(InRetryVerbs)
    , RetryDomains(InRetryDomains)
{
}

void Response::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
    ResponseCode = InHttpResponseCode;
    SetSuccessful(EHttpResponseCodes::IsOk(InHttpResponseCode));
    if(InHttpResponseCode == EHttpResponseCodes::RequestTimeout)
    {
        SetResponseString(TEXT("Request Timeout"));
    }
}

}