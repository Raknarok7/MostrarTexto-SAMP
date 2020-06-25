/*
	ShowInfoForPlayer include by Richie©.
	
	If you dont want to use y_hooks you can
	move the code from OnPlayerDisconnect(playerid, reason)
	and OnPlayerConnect(playerid) to those callbacks in
	your script. 
	
	To use it, place it under your other includes.
*/
#include <YSI\y_hooks>

new PlayerText:InfoText[MAX_PLAYERS],
	InfoTimer[MAX_PLAYERS],
	InfoTextShowing[MAX_PLAYERS]; // var if you need other parts of your script to know if the Info Message is showing for the player.


hook OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, InfoText[playerid]);
	return 1;
}

hook OnPlayerConnect(playerid)
{
	// Create the textdraw
	InfoText[playerid] = CreatePlayerTextDraw(playerid, 319.999938, 401.955749, "_");
	PlayerTextDrawLetterSize(playerid, InfoText[playerid], 0.241999, 1.280593);
	PlayerTextDrawAlignment(playerid, InfoText[playerid], 2);
	PlayerTextDrawColor(playerid, InfoText[playerid], -1);
	PlayerTextDrawSetShadow(playerid, InfoText[playerid], 0);
	PlayerTextDrawSetOutline(playerid, InfoText[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, InfoText[playerid], 51);
	PlayerTextDrawFont(playerid, InfoText[playerid], 1);
	PlayerTextDrawSetProportional(playerid, InfoText[playerid], 1);
	
	InfoTextShowing[playerid] = 0;
	return 1;
}

stock ShowInfoForPlayer(playerid, text[], time) // playerid to show, text to show, time to show in ms
{
	KillTimer(InfoTimer[playerid]);
    PlayerTextDrawHide(playerid, InfoText[playerid]);
    InfoTextShowing[playerid] = 1;
    PlayerTextDrawSetString(playerid, InfoText[playerid], text);
	PlayerTextDrawShow(playerid, InfoText[playerid]);
	InfoTimer[playerid] = SetTimerEx("HideInfoForPlayer", time, false, "i", playerid);
	return 1;
}

forward HideInfoForPlayer(playerid); // Hide the info message for player.
public HideInfoForPlayer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 1;
    PlayerTextDrawHide(playerid, InfoText[playerid]);
    InfoTextShowing[playerid] = 0;
    return 1;
}