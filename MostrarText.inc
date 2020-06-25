/*
	Mostrar texto  | @Raknarok7
	

*/
#include <YSI\y_hooks>

new PlayerText:InfoText[MAX_PLAYERS],
	InfoTimer[MAX_PLAYERS],
	InfoTextShowing[MAX_PLAYERS]; 


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

stock MostrarTexto(playerid, text[], time) // playerid, texto, tiempo
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
