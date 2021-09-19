/*	
	team_deathmatch.sp Copyright (C) 2021 Oylsister
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma semicolon 1

#include <sourcemod>
#include <sdktools>
#include <sdkhooks>
#include <cstrike>
#include <multicolors>

// TDM Module
#include "tdm/global.inc"
#include "tdm/cvar.inc"
#include "tdm/event.inc"

public Plugin myinfo = 
{
	name = "[CS:GO] Team Death Match",
	author = "Oylsister",
	description = "PVP game mode where each team have to fight.",
	version = "1.1",
	url = "https://github.com/oylsister/"
}

public void OnPluginStart()
{
	ConVarInit();
	EventInit();
}

public void OnMapStart()
{
	SetConVarInt(g_Cvar.Cvar_Timelimit, g_iMaxTime);
}


