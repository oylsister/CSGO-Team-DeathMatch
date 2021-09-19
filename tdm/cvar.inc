enum struct TDM_Convar
{
	ConVar Cvar_UseCSGOCvar;
	ConVar Cvar_Mode;
	ConVar Cvar_MaxKill;
	ConVar Cvar_MaxTime;
	ConVar Cvar_RespawnTime;
	ConVar Cvar_Timelimit;
}

TDM_Convar g_Cvar;

void ConVarInit()
{
	g_Cvar.Cvar_Mode = CreateConVar("sm_tdm_mode", "0.0", "Specific mode for TDM match [0 = Max Kill, 1 = Max Time]", _, true, 0.0, true, 1.0);
	g_Cvar.Cvar_MaxKill = CreateConVar("sm_tdm_maxkill", "200.0", "Specific the maximum kill before end game", _, true, 50.0, true, 400.0);
	g_Cvar.Cvar_MaxTime = CreateConVar("sm_tdm_maxtime", "20.0", "Specific the maximum play time before end game", _, true, 5.0, true, 20.0);
	g_Cvar.Cvar_RespawnTime = CreateConVar("sm_tdm_respawntime", "5.0", "Specific respawn time", _, true, 1.0, false);
	g_Cvar.Cvar_Timelimit = FindConVar("mp_timelimit");
	
	HookConVarChange(g_Cvar.Cvar_Mode, ModeChange);
	HookConVarChange(g_Cvar.Cvar_MaxKill, MaxKillChange);
	HookConVarChange(g_Cvar.Cvar_MaxTime, MaxTimeChange);
	HookConVarChange(g_Cvar.Cvar_RespawnTime, RespawnTimeChange);
}

public void ModeChange(ConVar cvar, const char[] oldvalue, const char[] newvalue)
{
	g_iMode = GetConVarInt(g_Cvar.Cvar_Mode);
}

public void MaxKillChange(ConVar cvar, const char[] oldvalue, const char[] newvalue)
{
	g_iMaxKill = GetConVarInt(g_Cvar.Cvar_MaxKill);
}

public void MaxTimeChange(ConVar cvar, const char[] oldvalue, const char[] newvalue)
{
	g_iMaxTime = GetConVarInt(g_Cvar.Cvar_MaxTime);
}

public void RespawnTimeChange(ConVar cvar, const char[] oldvalue, const char[] newvalue)
{
	g_fRespawnTime = GetConVarFloat(g_Cvar.Cvar_RespawnTime);
}