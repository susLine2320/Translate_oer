// Ats.cpp : DLL アプリケーション用のエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "atsplugin.h"
#include "Ats.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

ATS_API int WINAPI GetPluginVersion()
{
	return ATS_VERSION;
}

ATS_API void WINAPI SetVehicleSpec(ATS_VEHICLESPEC vehicleSpec)
{
	g_svcBrake = vehicleSpec.BrakeNotches;
	g_emgBrake = g_svcBrake + 1;
}

ATS_API void WINAPI Initialize(int brake)
{
	g_speed = 0;
	g_output.Reverser = 0;//起動時レバーサーを切に入れる（これがないと小田急/うさプラ/ATOは戸開中前を出し続けるので必ず入れる）
}

ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE vehicleState, int *panel, int *sound)
{
	g_deltaT = vehicleState.Time - g_time;
	g_time = vehicleState.Time;
	g_speed = vehicleState.Speed;

	// ハンドル出力
	
	if(g_brakeNotch != g_emgBrake)
	{
		g_output.Brake = g_brakeNotch;
	}
	else
	{
		g_output.Brake = g_emgBrake;
	}
	
	if(g_pilotlamp)
	{
		g_output.Reverser = g_reverser;
	}
	else
	{
		if (panel[14] == 0) {
			g_output.Reverser = 1;
		}
		else if (panel[14] == 1) {
			g_output.Reverser = -1;
		}
		else {
			g_output.Reverser = 0;
		}
	}
	
	g_output.Power = g_powerNotch;
	g_output.ConstantSpeed = ATS_CONSTANTSPEED_CONTINUE;

	// パネル入力（変換）
	//ats100 = panel[43];
	ats99 = panel[42];
	ats98 = panel[41];
	ats97 = panel[40];
	ats95 = panel[12];
	ats94 = panel[11];
	ats93 = panel[172];
	ats90 = panel[37];
	ats89 = panel[36];
	ats88 = panel[35];
	ats87 = panel[34];
	ats85 = panel[33];
	ats84 = panel[32];
	ats83 = panel[31];
	ats80 = panel[54];
	ats71 = panel[53];
	ats67 = panel[52];
	ats40 = panel[51];
	ats35 = panel[50];
	ats24 = panel[8];
	ats8 = panel[10];
	ats126 = panel[43];
	ats127 = panel[2];
	ats128 = panel[59];
	//ats129 = panel[25];
	ats130 = panel[55];
	ats136 = panel[130];
	ats138 = panel[131];
	ats139 = panel[20];
	ats140 = panel[132];
	ats141 = panel[133];
	ats142 = panel[134];
	ats143 = panel[135];
	ats144 = panel[79];
	ats145 = panel[80];
	ats146 = panel[81];
	ats147 = panel[87];
	ats148 = panel[88];
	ats149 = panel[89];
	ats150 = panel[90];
	ats170 = panel[181];
	ats178 = panel[177];
	ats179 = panel[178];
	ats180 = panel[179];
	ats183 = panel[175];
	ats184 = panel[176];
	ats195 = panel[100];
	ats196 = panel[101];
	ats197 = panel[102];
	ats198 = panel[103];
	ats199 = panel[104];
	ats200 = panel[105];
	ats207 = panel[15];
	ats208 = panel[16];
	ats209 = panel[17];
	ats215 = panel[106];
	ats216 = panel[107];
	ats217 = panel[108];
	ats218 = panel[109];
	ats219 = panel[110];
	ats220 = panel[111];
	ats221 = panel[112];
	ats222 = panel[113];
	ats223 = panel[114];
	ats224 = panel[115];
	ats225 = panel[116];
	ats226 = panel[117];
	ats227 = panel[118];
	ats228 = panel[119];
	ats229 = panel[120];
	ats230 = panel[121];
	ats231 = panel[122];
	ats233 = panel[123];
	ats242 = panel[83];
	ats243 = panel[84];
	ats244 = panel[85];
	ats255 = panel[82];

	// パネル出力
	panel[8] = ats8;
	panel[24] = ats24;
	panel[35] = ats35;
	panel[40] = ats40;
	panel[67] = ats67;
	panel[71] = ats71;
	panel[80] = ats80;
	panel[83] = ats83;
	panel[84] = ats84;
	panel[85] = ats85;
	panel[87] = ats87;
	panel[88] = ats88;
	panel[89] = ats89;
	panel[90] = ats90;
	panel[93] = ats93;
	panel[94] = ats94;
	panel[95] = ats95;
	panel[97] = ats97;
	panel[98] = ats98;
	panel[99] = ats99;
	panel[100] = ats100;
	panel[126] = ats126;
	panel[127] = ats127;
	panel[128] = ats128;
	panel[129] = ats129;
	panel[130] = ats130;
	panel[136] = ats136;
	panel[138] = ats138;
	panel[139] = ats139;
	panel[140] = ats140;
	panel[141] = ats141;
	panel[142] = ats142;
	panel[143] = ats143;
	panel[144] = ats144;
	panel[145] = ats145;
	panel[146] = ats146;
	panel[147] = ats147;
	panel[148] = ats148;
	panel[149] = ats149;
	panel[150] = ats150;
	panel[170] = ats170;
	panel[178] = ats178;
	panel[179] = ats179;
	panel[180] = ats180;
	panel[183] = ats183;
	panel[184] = ats184;
	panel[195] = ats195;
	panel[196] = ats196;
	panel[197] = ats197;
	panel[198] = ats198;
	panel[199] = ats199;
	panel[200] = ats200;
	panel[207] = ats207;
	panel[208] = ats208;
	panel[209] = ats209;
	panel[215] = ats215;
	panel[216] = ats216;
	panel[217] = ats217;
	panel[218] = ats218;
	panel[219] = ats219;
	panel[220] = ats220;
	panel[221] = ats221;
	panel[222] = ats222;
	panel[223] = ats223;
	panel[224] = ats224;
	panel[225] = ats225;
	panel[226] = ats226;
	panel[227] = ats227;
	panel[228] = ats228;
	panel[229] = ats229;
	panel[230] = ats230;
	panel[231] = ats231;
	panel[233] = ats233;
	panel[242] = ats242;
	panel[243] = ats243;
	panel[244] = ats244;
	panel[255] = ats255;

	//サウンド入力（変換）
	s21 = sound[41];
	s25 = sound[0];
	s26 = sound[1];
	s54 = sound[3];
	s55 = sound[4];
	s67 = sound[7];
	s68 = sound[8];
	s89 = sound[5];
	
	// サウンド出力（変換）
	sound[21] = s21;
	sound[25] = s25;
	sound[26] = s26;
	sound[54] = s54;
	sound[55] = s55;
	sound[67] = s67;
	sound[68] = s68;
	sound[89] = s89;

	//サウンド出力（元番号を0に）
	sound[0] = ATS_SOUND_STOP;
	sound[1] = ATS_SOUND_STOP;
	sound[3] = ATS_SOUND_STOP;
	sound[4] = ATS_SOUND_STOP;
	sound[5] = ATS_SOUND_STOP;
	sound[7] = ATS_SOUND_STOP;
	sound[8] = ATS_SOUND_STOP;
	sound[41] = ATS_SOUND_STOP;



    return g_output;
}

ATS_API void WINAPI SetPower(int notch)
{
	g_powerNotch = notch;
}

ATS_API void WINAPI SetBrake(int notch)
{
	g_brakeNotch = notch;
}

ATS_API void WINAPI SetReverser(int pos)
{
	g_reverser = pos;
}

ATS_API void WINAPI KeyDown(int atsKeyCode)
{
}

ATS_API void WINAPI KeyUp(int hornType)
{
}

ATS_API void WINAPI HornBlow(int atsHornBlowIndex)
{
}

ATS_API void WINAPI DoorOpen()
{
	g_pilotlamp = false;
}

ATS_API void WINAPI DoorClose()
{
	g_pilotlamp = true;
}

ATS_API void WINAPI SetSignal(int signal)
{
}

ATS_API void WINAPI SetBeaconData(ATS_BEACONDATA beaconData)
{
}

ATS_API void WINAPI Load() {}
ATS_API void WINAPI Dispose() {}