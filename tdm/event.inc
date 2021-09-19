void EventInit()
{
	HookEvent("player_death", OnPlayerDeath);
	HookEvent("player_team", OnPlayerJoinTeam);
	HookEvent("round_start", OnRoundStart);
}

public void OnPlayerDeath(Event event, const char[] name, bool dontBroadcast)
{
	if (GameRules_GetProp("m_bWarmupPeriod") == 1)
		return;
		
	int client = GetClientOfUserId(GetEventInt(event, "userid"));
	int attacker = GetClientOfUserId(GetEventInt(event, "attacker"));
	
	CreateTimer(g_fRespawnTime, RespawnClient, client);
	
	int team = GetClientTeam(attacker);
	if(team == CS_TEAM_CT)
	{
		g_iCTScore++;
		CS_SetTeamScore(CS_TEAM_CT, g_iCTScore);
	}
	else if(team == CS_TEAM_T)
	{
		g_iTScore++;
		CS_SetTeamScore(CS_TEAM_T, g_iTScore);
	}
	else
	{
		return;
	}
	
	if(g_iCTScore == g_iMaxKill)
		CS_TerminateRound(0.1, CSRoundEnd_CTWin, true);
		
	else if(g_iTScore == g_iMaxKill)
		CS_TerminateRound(0.1, CSRoundEnd_TerroristWin, true);
}

public void OnPlayerJoinTeam(Event event, const char[] name, bool dontBroadcast)
{
	int client = GetClientOfUserId(GetEventInt(event, "userid"));
	
	if(!IsPlayerAlive(client))
		CreateTimer(g_fRespawnTime, RespawnClient, client);
}

public void OnRoundStart(Event event, const char[] name, bool dontBroadcast) 
{
	g_iTScore = 0;
	g_iCTScore = 0;
	
	CS_SetTeamScore(CS_TEAM_CT, g_iCTScore);
	CS_SetTeamScore(CS_TEAM_T, g_iTScore);
	
	CPrintToChatAll("\x04[TDM]\x01 The Current game mode is \x05Team Death Match\x01. Any team that reach \x10%d\x01 point before, will be a winner!", g_iMaxKill);
}

public Action CS_OnTerminateRound(float &delay, CSRoundEndReason &reason)
{
	if(g_iMode == 0)
	{
		if(g_iCTScore < g_iMaxKill || g_iTScore < g_iMaxKill)
		{
			return Plugin_Handled;
		}
	}
	else
	{
		return Plugin_Continue;
	}
}

public Action RespawnClient(Handle timer, any client)
{
	if(!IsPlayerAlive(client) && IsClientInGame(client))
		CS_RespawnPlayer(client);
}