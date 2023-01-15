// 以下の ifdef ブロックは DLL から簡単にエクスポートさせるマクロを作成する標準的な方法です。 
// この DLL 内のすべてのファイルはコマンドラインで定義された ATS_EXPORTS シンボル
// でコンパイルされます。このシンボルはこの DLL が使用するどのプロジェクト上でも未定義でなけ
// ればなりません。この方法ではソースファイルにこのファイルを含むすべてのプロジェクトが DLL 
// からインポートされたものとして ATS_API 関数を参照し、そのためこの DLL はこのマク 
// ロで定義されたシンボルをエクスポートされたものとして参照します。
//#pragma data_seg(".shared")
//#pragma data_seg()

#define ATS_BEACON_S 0 // Sロング
#define ATS_BEACON_SN 1 // SN直下
#define ATS_BEACON_SNRED 2 // SN誤出発防止
#define ATS_BEACON_P 3 // P停止信号
#define ATS_BEACON_EMG 4 // P即停(非常)
#define ATS_BEACON_SVC 5 // P即停(常用)
#define ATS_BEACON_SPDLIM 6 // P分岐器速度制限
#define ATS_BEACON_SPDMAX 7 // P最高速度
#define ATS_BEACON_SPP 8 // 停車駅通過防止装置

int g_emgBrake; // 非常ノッチ
int g_svcBrake; // 常用最大ノッチ
int g_brakeNotch; // ブレーキノッチ
int g_powerNotch; // 力行ノッチ
int g_reverser; // レバーサ
bool g_pilotlamp; // パイロットランプ
int g_time; // 現在時刻
float g_speed; // 速度計の速度[km/h]
int g_deltaT; // フレーム時間[ms/frame]
int atoCgS; //運転切替スイッチ
int atoSWitch; //パターン切替スイッチ
bool atodrive;
bool ats8;
bool ats24;
int ats35;
int ats40;
int ats67;
int ats71;
int ats80;
int ats83;
int ats84;
int ats85;
int ats87;
int ats88;
int ats89;
int ats90;
int ats93;
bool ats94;
bool ats95;
bool ats97;
bool ats98;
bool ats99;
bool ats100;
int ats126;
int ats127;
int ats128;
int ats129;
int ats130;
bool ats136;
bool ats138;
int ats139;
int ats140;
int ats141;
int ats142;
int ats143;
int ats144;
int ats145;
int ats146;
int ats147;
int ats148;
int ats149;
int ats150;
int ats170;
int ats178;
int ats179;
int ats180;
int ats183;
int ats184;
int ats242;
int ats243;
int ats244;
int ats188;
int ats189;
int ats190;
int ats191;
int ats195;
int ats196;
int ats197;
int ats198;
int ats199;
int ats200;
int ats207;
int ats208;
int ats209;
int ats215;
int ats216;
int ats217;
int ats218;
int ats219;
int ats220;
int ats221;
int ats222;
int ats223;
int ats224;
int ats225;
int ats226;
int ats227;
int ats228;
int ats229;
int ats230;
int ats231;
int ats233;
bool ats255;
int s21;
int s25;
int s26;
int s54;
int s55;
int s67;
int s68;
int s89;

ATS_HANDLES g_output; // 出力
