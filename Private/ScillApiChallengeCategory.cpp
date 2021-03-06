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

#include "ScillApiWrapper/ScillApiChallengeCategory.h"

#include "ScillSDKModule.h"
#include "ScillApiWrapper/ScillApiHelpers.h"

#include "Templates/SharedPointer.h"

namespace ScillSDK
{

void ScillApiChallengeCategory::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (IsDailyCategory.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("is_daily_category")); WriteJsonValue(Writer, IsDailyCategory.GetValue());
	}
	if (CategoryPosition.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("category_position")); WriteJsonValue(Writer, CategoryPosition.GetValue());
	}
	if (CategorySlug.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("category_slug")); WriteJsonValue(Writer, CategorySlug.GetValue());
	}
	if (CategoryName.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("category_name")); WriteJsonValue(Writer, CategoryName.GetValue());
	}
	if (CategoryId.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("category_id")); WriteJsonValue(Writer, CategoryId.GetValue());
	}
	if (Challenges.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("challenges")); WriteJsonValue(Writer, Challenges.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool ScillApiChallengeCategory::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("is_daily_category"), IsDailyCategory);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("category_position"), CategoryPosition);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("category_slug"), CategorySlug);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("category_name"), CategoryName);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("category_id"), CategoryId);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("challenges"), Challenges);

	return ParseSuccess;
}

}
