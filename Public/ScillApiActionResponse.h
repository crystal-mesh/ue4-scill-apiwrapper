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

#include "ScillApiBaseModel.h"
#include "ScillApiChallenge.h"

namespace ScillSDK
{

/*
 * ScillApiActionResponse
 *
 * Standard response for actions like update or delete. If anything went fine, you&#39;ll receive a HTTP code of 200 and a OK message.
 */
class SCILLSDK_API ScillApiActionResponse : public Model
{
public:
    virtual ~ScillApiActionResponse() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	/* HTTP status code */
	int32 Status = 0;
	FString Message;
	TOptional<ScillApiChallenge> Challenge;
};

}
