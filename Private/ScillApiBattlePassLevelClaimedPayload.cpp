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

#include "ScillApiWrapper/ScillApiBattlePassLevelClaimedPayload.h"

#include "ScillSDKModule.h"
#include "ScillApiWrapper/ScillApiHelpers.h"

#include "Templates/SharedPointer.h"

namespace ScillSDK
{

void ScillApiBattlePassLevelClaimedPayload::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (WebhookType.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("webhook_type")); WriteJsonValue(Writer, WebhookType.GetValue());
	}
	if (BattlePassLevelRewardClaimed.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("battle_pass_level_reward_claimed")); WriteJsonValue(Writer, BattlePassLevelRewardClaimed.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool ScillApiBattlePassLevelClaimedPayload::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("webhook_type"), WebhookType);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("battle_pass_level_reward_claimed"), BattlePassLevelRewardClaimed);

	return ParseSuccess;
}

}
