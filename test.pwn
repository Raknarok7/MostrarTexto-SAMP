#include<MostrarTexto>



hook OnGameModeInit() {




return 0;
}

CMD:test(playerid) {

MostrarTexto(playerid, "Welcome i am raknarok", 3000); // el "3000" es el tiempo.


return 1;
}
CMD:cerrar(playerid) {
hook OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, InfoText[playerid]);
	return 1;
}
return 1;
}
