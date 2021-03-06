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
#include "ScillApiLeaderboardRanking.h"

namespace ScillSDK
{

/*
 * ScillApiLeaderboard
 *
 * The Leaderboard object contains information about the leaderboard itself like the name and the id, but also contains actual rankings for users and teams.
 */
class SCILLSDK_API ScillApiLeaderboard : public Model
{
public:
    virtual ~ScillApiLeaderboard() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	/* The id of the leaderboard */
	TOptional<FString> LeaderboardId;
	/* The name of the leaderboard */
	TOptional<FString> Name;
	/* An array of LeaderboardRanking Items for individual users */
	TOptional<TArray<ScillApiLeaderboardRanking>> GroupedByUsers;
	/* An array of LeaderboardRanking Items for teams. Provide a team_id in the event payload to also create leaderboards for teams */
	TOptional<TArray<ScillApiLeaderboardRanking>> GroupedByTeams;
	/* The total number of team rankings available in the leaderboard */
	TOptional<double> NumTeams;
	/* The total number of user rankings available in the leaderboard */
	TOptional<double> NumUsers;
};

}
