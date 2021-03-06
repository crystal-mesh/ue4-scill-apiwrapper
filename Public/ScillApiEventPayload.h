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
#include "ScillApiEventMetaData.h"

namespace ScillSDK
{

/*
 * ScillApiEventPayload
 *
 * Events are the engine and driver for challenges, battle passes and leaderboards within the SCILL ecosystem. They are a simple, yet powerful data structure. The idea is, that you just send events for actions and things that happen in your game or application. SCILL leverages these info to update and progress challenges or to figure out the users score within a leaderboard. You don&#39;t have to handle any state in your application or game, as everything is done by SCILL.
 */
class SCILLSDK_API ScillApiEventPayload : public Model
{
public:
    virtual ~ScillApiEventPayload() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	/* This is your user id. You can set this to whatever you like, either your real user id or an obfuscated user id. However you need to be consistent here. Events linked to this user id only track if challenges or battle passes are unlocked with the same user id. */
	TOptional<FString> UserId;
	/* This is required if event_type is single and identifies a session. This can be anything used to group events together. For example this can be a level or a match id. */
	TOptional<FString> SessionId;
	/* This is the event type as a string. These have predefined event names for many games and applications. It’s wise to use those as this allows us to analyse data and help you balancing your application or game. */
	TOptional<FString> EventName;
	/* This is either single or group. You can send multiple events in one request (group) or send events in sequence. Please note, that depending on your tier you might run into rate limits. */
	TOptional<FString> EventType;
	TOptional<ScillApiEventMetaData> MetaData;
	/* Provide an optional team id that will be used in leaderboards to group results of teams. */
	TOptional<FString> TeamId;
};

}
