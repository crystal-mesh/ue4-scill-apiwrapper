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

#include "ScillApiWrapper/ScillApiError.h"

#include "ScillSDKModule.h"
#include "ScillApiWrapper/ScillApiHelpers.h"

#include "Templates/SharedPointer.h"

namespace ScillSDK
{

void ScillApiError::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Code.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("code")); WriteJsonValue(Writer, Code.GetValue());
	}
	Writer->WriteIdentifierPrefix(TEXT("message")); WriteJsonValue(Writer, Message);
	Writer->WriteObjectEnd();
}

bool ScillApiError::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("code"), Code);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("message"), Message);

	return ParseSuccess;
}

}
