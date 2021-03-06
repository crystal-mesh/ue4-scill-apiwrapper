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

#include "ScillApiWrapper/ScillApiLeaderboardScore.h"

#include "ScillSDKModule.h"
#include "ScillApiWrapper/ScillApiHelpers.h"

#include "Templates/SharedPointer.h"

namespace ScillSDK
{

void ScillApiLeaderboardScore::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Score.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("score")); WriteJsonValue(Writer, Score.GetValue());
	}
	if (Rank.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("rank")); WriteJsonValue(Writer, Rank.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool ScillApiLeaderboardScore::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("score"), Score);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("rank"), Rank);

	return ParseSuccess;
}

}
