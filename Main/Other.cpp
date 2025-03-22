#include "stdafx.h"
#include "Other.h"
#include "TMemory.h"
#include "Import.h"
#include "User.h"
#include "Defines.h"
#include "Interface.h"
#include "Util.h"
#include "Protect.h"
#include "WindowsStruct.h"
// ----------------------------------------------------------------------------------------------

Other	gOther;
DWORD	GuildAssistEx_Buff;
DWORD dwAllowTabSwitchLoginJMP = 0x0040B16F;
// ----------------------------------------------------------------------------------------------

int valor = 0;

// ----------------------------------------------------------------------------------------------
static int NewCredit(void *This, int a2)
{
	return pCharacterBuf(This, a2);
}


//DWORD		Test_Buff;
//char		Test_LevelBuff[40];


//--------------------


void Other::Load()
{
	this->Crack();

	//============================================================================================================
	GetPrivateProfileStringA("TextVN", "TextVN0", "Null", TextVN[0], sizeof(TextVN[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN1", "Null", TextVN[1], sizeof(TextVN[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN2", "Null", TextVN[2], sizeof(TextVN[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN3", "Null", TextVN[3], sizeof(TextVN[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN4", "Null", TextVN[4], sizeof(TextVN[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN5", "Null", TextVN[5], sizeof(TextVN[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN6", "Null", TextVN[6], sizeof(TextVN[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN7", "Null", TextVN[7], sizeof(TextVN[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN8", "Null", TextVN[8], sizeof(TextVN[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN9", "Null", TextVN[9], sizeof(TextVN[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN10", "Null", TextVN[10], sizeof(TextVN[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN11", "Null", TextVN[11], sizeof(TextVN[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN12", "Null", TextVN[12], sizeof(TextVN[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN13", "Null", TextVN[13], sizeof(TextVN[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN14", "Null", TextVN[14], sizeof(TextVN[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN15", "Null", TextVN[15], sizeof(TextVN[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN16", "Null", TextVN[16], sizeof(TextVN[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN17", "Null", TextVN[17], sizeof(TextVN[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN18", "Null", TextVN[18], sizeof(TextVN[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN19", "Null", TextVN[19], sizeof(TextVN[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN20", "Null", TextVN[20], sizeof(TextVN[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN21", "Null", TextVN[21], sizeof(TextVN[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN22", "Null", TextVN[22], sizeof(TextVN[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN23", "Null", TextVN[23], sizeof(TextVN[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN24", "Null", TextVN[24], sizeof(TextVN[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN25", "Null", TextVN[25], sizeof(TextVN[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN26", "Null", TextVN[26], sizeof(TextVN[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN27", "Null", TextVN[27], sizeof(TextVN[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN28", "Null", TextVN[28], sizeof(TextVN[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN29", "Null", TextVN[29], sizeof(TextVN[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN30", "Null", TextVN[30], sizeof(TextVN[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN31", "Null", TextVN[31], sizeof(TextVN[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN32", "Null", TextVN[32], sizeof(TextVN[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN33", "Null", TextVN[33], sizeof(TextVN[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN34", "Null", TextVN[34], sizeof(TextVN[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN35", "Null", TextVN[35], sizeof(TextVN[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN36", "Null", TextVN[36], sizeof(TextVN[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN37", "Null", TextVN[37], sizeof(TextVN[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN38", "Null", TextVN[38], sizeof(TextVN[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN39", "Null", TextVN[39], sizeof(TextVN[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN40", "Null", TextVN[40], sizeof(TextVN[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN41", "Null", TextVN[41], sizeof(TextVN[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN42", "Null", TextVN[42], sizeof(TextVN[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN43", "Null", TextVN[43], sizeof(TextVN[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN44", "Null", TextVN[44], sizeof(TextVN[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN45", "Null", TextVN[45], sizeof(TextVN[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN46", "Null", TextVN[46], sizeof(TextVN[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN47", "Null", TextVN[47], sizeof(TextVN[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN48", "Null", TextVN[48], sizeof(TextVN[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN49", "Null", TextVN[49], sizeof(TextVN[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN50", "Null", TextVN[50], sizeof(TextVN[50]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN51", "Null", TextVN[51], sizeof(TextVN[51]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN52", "Null", TextVN[52], sizeof(TextVN[52]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN53", "Null", TextVN[53], sizeof(TextVN[53]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN54", "Null", TextVN[54], sizeof(TextVN[54]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN55", "Null", TextVN[55], sizeof(TextVN[55]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN56", "Null", TextVN[56], sizeof(TextVN[56]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN57", "Null", TextVN[57], sizeof(TextVN[57]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN58", "Null", TextVN[58], sizeof(TextVN[58]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN59", "Null", TextVN[59], sizeof(TextVN[59]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN60", "Null", TextVN[60], sizeof(TextVN[60]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN61", "Null", TextVN[61], sizeof(TextVN[61]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN62", "Null", TextVN[62], sizeof(TextVN[62]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN63", "Null", TextVN[63], sizeof(TextVN[63]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN64", "Null", TextVN[64], sizeof(TextVN[64]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN65", "Null", TextVN[65], sizeof(TextVN[65]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN66", "Null", TextVN[66], sizeof(TextVN[66]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN67", "Null", TextVN[67], sizeof(TextVN[67]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN68", "Null", TextVN[68], sizeof(TextVN[68]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN69", "Null", TextVN[69], sizeof(TextVN[69]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN70", "Null", TextVN[70], sizeof(TextVN[70]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN71", "Null", TextVN[71], sizeof(TextVN[71]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN72", "Null", TextVN[72], sizeof(TextVN[72]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN73", "Null", TextVN[73], sizeof(TextVN[73]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN74", "Null", TextVN[74], sizeof(TextVN[74]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN75", "Null", TextVN[75], sizeof(TextVN[75]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN76", "Null", TextVN[76], sizeof(TextVN[76]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN77", "Null", TextVN[77], sizeof(TextVN[77]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN78", "Null", TextVN[78], sizeof(TextVN[78]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN79", "Null", TextVN[79], sizeof(TextVN[79]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN80", "Null", TextVN[80], sizeof(TextVN[80]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN81", "Null", TextVN[81], sizeof(TextVN[81]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN82", "Null", TextVN[82], sizeof(TextVN[82]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN83", "Null", TextVN[83], sizeof(TextVN[83]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN84", "Null", TextVN[84], sizeof(TextVN[84]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN85", "Null", TextVN[85], sizeof(TextVN[85]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN86", "Null", TextVN[86], sizeof(TextVN[86]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN87", "Null", TextVN[87], sizeof(TextVN[87]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN88", "Null", TextVN[88], sizeof(TextVN[88]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN89", "Null", TextVN[89], sizeof(TextVN[89]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN90", "Null", TextVN[90], sizeof(TextVN[90]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN91", "Null", TextVN[91], sizeof(TextVN[91]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN92", "Null", TextVN[92], sizeof(TextVN[92]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN93", "Null", TextVN[93], sizeof(TextVN[93]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN94", "Null", TextVN[94], sizeof(TextVN[94]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN95", "Null", TextVN[95], sizeof(TextVN[95]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN96", "Null", TextVN[96], sizeof(TextVN[96]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN97", "Null", TextVN[97], sizeof(TextVN[97]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN98", "Null", TextVN[98], sizeof(TextVN[98]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN99", "Null", TextVN[99], sizeof(TextVN[99]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN100", "Null", TextVN[100], sizeof(TextVN[100]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN101", "Null", TextVN[101], sizeof(TextVN[101]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN102", "Null", TextVN[102], sizeof(TextVN[102]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN103", "Null", TextVN[103], sizeof(TextVN[103]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN104", "Null", TextVN[104], sizeof(TextVN[104]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN105", "Null", TextVN[105], sizeof(TextVN[105]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN106", "Null", TextVN[106], sizeof(TextVN[106]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN107", "Null", TextVN[107], sizeof(TextVN[107]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN108", "Null", TextVN[108], sizeof(TextVN[108]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN109", "Null", TextVN[109], sizeof(TextVN[109]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN110", "Null", TextVN[110], sizeof(TextVN[110]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN111", "Null", TextVN[111], sizeof(TextVN[111]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN112", "Null", TextVN[112], sizeof(TextVN[112]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN113", "Null", TextVN[113], sizeof(TextVN[113]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN114", "Null", TextVN[114], sizeof(TextVN[114]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN115", "Null", TextVN[115], sizeof(TextVN[115]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN116", "Null", TextVN[116], sizeof(TextVN[116]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN117", "Null", TextVN[117], sizeof(TextVN[117]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN118", "Null", TextVN[118], sizeof(TextVN[118]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN119", "Null", TextVN[119], sizeof(TextVN[119]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN120", "Null", TextVN[120], sizeof(TextVN[120]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN121", "Null", TextVN[121], sizeof(TextVN[121]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN122", "Null", TextVN[122], sizeof(TextVN[122]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN123", "Null", TextVN[123], sizeof(TextVN[123]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN124", "Null", TextVN[124], sizeof(TextVN[124]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN125", "Null", TextVN[125], sizeof(TextVN[125]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN126", "Null", TextVN[126], sizeof(TextVN[126]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN127", "Null", TextVN[127], sizeof(TextVN[127]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN128", "Null", TextVN[128], sizeof(TextVN[128]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN129", "Null", TextVN[129], sizeof(TextVN[129]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN130", "Null", TextVN[130], sizeof(TextVN[130]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN131", "Null", TextVN[131], sizeof(TextVN[131]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN132", "Null", TextVN[132], sizeof(TextVN[132]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN133", "Null", TextVN[133], sizeof(TextVN[133]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN134", "Null", TextVN[134], sizeof(TextVN[134]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN135", "Null", TextVN[135], sizeof(TextVN[135]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN136", "Null", TextVN[136], sizeof(TextVN[136]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN137", "Null", TextVN[137], sizeof(TextVN[137]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN138", "Null", TextVN[138], sizeof(TextVN[138]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN139", "Null", TextVN[139], sizeof(TextVN[139]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN140", "Null", TextVN[140], sizeof(TextVN[140]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN141", "Null", TextVN[141], sizeof(TextVN[141]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN142", "Null", TextVN[142], sizeof(TextVN[142]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN143", "Null", TextVN[143], sizeof(TextVN[143]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN144", "Null", TextVN[144], sizeof(TextVN[144]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN145", "Null", TextVN[145], sizeof(TextVN[145]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN146", "Null", TextVN[146], sizeof(TextVN[146]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN147", "Null", TextVN[147], sizeof(TextVN[147]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN148", "Null", TextVN[148], sizeof(TextVN[148]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN149", "Null", TextVN[149], sizeof(TextVN[149]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN150", "Null", TextVN[150], sizeof(TextVN[150]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN151", "Null", TextVN[151], sizeof(TextVN[151]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN152", "Null", TextVN[152], sizeof(TextVN[152]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN153", "Null", TextVN[153], sizeof(TextVN[153]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN154", "Null", TextVN[154], sizeof(TextVN[154]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN155", "Null", TextVN[155], sizeof(TextVN[155]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN156", "Null", TextVN[156], sizeof(TextVN[156]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN157", "Null", TextVN[157], sizeof(TextVN[157]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN158", "Null", TextVN[158], sizeof(TextVN[158]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN159", "Null", TextVN[159], sizeof(TextVN[159]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN160", "Null", TextVN[160], sizeof(TextVN[160]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN161", "Null", TextVN[161], sizeof(TextVN[161]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN162", "Null", TextVN[162], sizeof(TextVN[162]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN163", "Null", TextVN[163], sizeof(TextVN[163]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN164", "Null", TextVN[164], sizeof(TextVN[164]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN165", "Null", TextVN[165], sizeof(TextVN[165]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN166", "Null", TextVN[166], sizeof(TextVN[166]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN167", "Null", TextVN[167], sizeof(TextVN[167]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN168", "Null", TextVN[168], sizeof(TextVN[168]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN169", "Null", TextVN[169], sizeof(TextVN[169]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN170", "Null", TextVN[170], sizeof(TextVN[170]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN171", "Null", TextVN[171], sizeof(TextVN[171]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN172", "Null", TextVN[172], sizeof(TextVN[172]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN173", "Null", TextVN[173], sizeof(TextVN[173]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN174", "Null", TextVN[174], sizeof(TextVN[174]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN175", "Null", TextVN[175], sizeof(TextVN[175]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN176", "Null", TextVN[176], sizeof(TextVN[176]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN177", "Null", TextVN[177], sizeof(TextVN[177]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN178", "Null", TextVN[178], sizeof(TextVN[178]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN179", "Null", TextVN[179], sizeof(TextVN[179]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN180", "Null", TextVN[180], sizeof(TextVN[180]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN181", "Null", TextVN[181], sizeof(TextVN[181]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN182", "Null", TextVN[182], sizeof(TextVN[182]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN183", "Null", TextVN[183], sizeof(TextVN[183]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN184", "Null", TextVN[184], sizeof(TextVN[184]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN185", "Null", TextVN[185], sizeof(TextVN[185]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN186", "Null", TextVN[186], sizeof(TextVN[186]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN187", "Null", TextVN[187], sizeof(TextVN[187]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN188", "Null", TextVN[188], sizeof(TextVN[188]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN189", "Null", TextVN[189], sizeof(TextVN[189]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN190", "Null", TextVN[190], sizeof(TextVN[190]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN191", "Null", TextVN[191], sizeof(TextVN[191]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN192", "Null", TextVN[192], sizeof(TextVN[192]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN193", "Null", TextVN[193], sizeof(TextVN[193]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN194", "Null", TextVN[194], sizeof(TextVN[194]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN195", "Null", TextVN[195], sizeof(TextVN[195]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN196", "Null", TextVN[196], sizeof(TextVN[196]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN197", "Null", TextVN[197], sizeof(TextVN[197]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN198", "Null", TextVN[198], sizeof(TextVN[198]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN199", "Null", TextVN[199], sizeof(TextVN[199]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN200", "Null", TextVN[200], sizeof(TextVN[200]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN201", "Null", TextVN[201], sizeof(TextVN[201]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN202", "Null", TextVN[202], sizeof(TextVN[202]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN203", "Null", TextVN[203], sizeof(TextVN[203]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN204", "Null", TextVN[204], sizeof(TextVN[204]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN205", "Null", TextVN[205], sizeof(TextVN[205]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN206", "Null", TextVN[206], sizeof(TextVN[206]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN207", "Null", TextVN[207], sizeof(TextVN[207]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN208", "Null", TextVN[208], sizeof(TextVN[208]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN209", "Null", TextVN[209], sizeof(TextVN[209]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN210", "Null", TextVN[210], sizeof(TextVN[210]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN211", "Null", TextVN[211], sizeof(TextVN[211]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN212", "Null", TextVN[212], sizeof(TextVN[212]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN213", "Null", TextVN[213], sizeof(TextVN[213]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN214", "Null", TextVN[214], sizeof(TextVN[214]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN215", "Null", TextVN[215], sizeof(TextVN[215]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN261", "Null", TextVN[216], sizeof(TextVN[216]), TEXTVN_FILE);
	//===>>>
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh0", "Null", TextVN_SachThuocTinh[0], sizeof(TextVN_SachThuocTinh[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh1", "Null", TextVN_SachThuocTinh[1], sizeof(TextVN_SachThuocTinh[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh2", "Null", TextVN_SachThuocTinh[2], sizeof(TextVN_SachThuocTinh[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh3", "Null", TextVN_SachThuocTinh[3], sizeof(TextVN_SachThuocTinh[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh4", "Null", TextVN_SachThuocTinh[4], sizeof(TextVN_SachThuocTinh[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh5", "Null", TextVN_SachThuocTinh[5], sizeof(TextVN_SachThuocTinh[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh6", "Null", TextVN_SachThuocTinh[6], sizeof(TextVN_SachThuocTinh[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh7", "Null", TextVN_SachThuocTinh[7], sizeof(TextVN_SachThuocTinh[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh8", "Null", TextVN_SachThuocTinh[8], sizeof(TextVN_SachThuocTinh[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh9", "Null", TextVN_SachThuocTinh[9], sizeof(TextVN_SachThuocTinh[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh10", "Null", TextVN_SachThuocTinh[10], sizeof(TextVN_SachThuocTinh[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh11", "Null", TextVN_SachThuocTinh[11], sizeof(TextVN_SachThuocTinh[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh12", "Null", TextVN_SachThuocTinh[12], sizeof(TextVN_SachThuocTinh[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh13", "Null", TextVN_SachThuocTinh[13], sizeof(TextVN_SachThuocTinh[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh14", "Null", TextVN_SachThuocTinh[14], sizeof(TextVN_SachThuocTinh[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh15", "Null", TextVN_SachThuocTinh[15], sizeof(TextVN_SachThuocTinh[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh16", "Null", TextVN_SachThuocTinh[16], sizeof(TextVN_SachThuocTinh[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh17", "Null", TextVN_SachThuocTinh[17], sizeof(TextVN_SachThuocTinh[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh18", "Null", TextVN_SachThuocTinh[18], sizeof(TextVN_SachThuocTinh[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh19", "Null", TextVN_SachThuocTinh[19], sizeof(TextVN_SachThuocTinh[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh20", "Null", TextVN_SachThuocTinh[20], sizeof(TextVN_SachThuocTinh[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh21", "Null", TextVN_SachThuocTinh[21], sizeof(TextVN_SachThuocTinh[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh22", "Null", TextVN_SachThuocTinh[22], sizeof(TextVN_SachThuocTinh[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh23", "Null", TextVN_SachThuocTinh[23], sizeof(TextVN_SachThuocTinh[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh24", "Null", TextVN_SachThuocTinh[24], sizeof(TextVN_SachThuocTinh[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh25", "Null", TextVN_SachThuocTinh[25], sizeof(TextVN_SachThuocTinh[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh26", "Null", TextVN_SachThuocTinh[26], sizeof(TextVN_SachThuocTinh[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh27", "Null", TextVN_SachThuocTinh[27], sizeof(TextVN_SachThuocTinh[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh28", "Null", TextVN_SachThuocTinh[28], sizeof(TextVN_SachThuocTinh[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh29", "Null", TextVN_SachThuocTinh[29], sizeof(TextVN_SachThuocTinh[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh30", "Null", TextVN_SachThuocTinh[30], sizeof(TextVN_SachThuocTinh[30]), TEXTVN_FILE);
	//===>>>
#if(PHUKIEN_NEW == 1)
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien0", "Null", TextVN_PhuKien[0], sizeof(TextVN_PhuKien[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien1", "Null", TextVN_PhuKien[1], sizeof(TextVN_PhuKien[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien2", "Null", TextVN_PhuKien[2], sizeof(TextVN_PhuKien[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien3", "Null", TextVN_PhuKien[3], sizeof(TextVN_PhuKien[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien4", "Null", TextVN_PhuKien[4], sizeof(TextVN_PhuKien[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien5", "Null", TextVN_PhuKien[5], sizeof(TextVN_PhuKien[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien6", "Null", TextVN_PhuKien[6], sizeof(TextVN_PhuKien[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien7", "Null", TextVN_PhuKien[7], sizeof(TextVN_PhuKien[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien8", "Null", TextVN_PhuKien[8], sizeof(TextVN_PhuKien[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien9", "Null", TextVN_PhuKien[9], sizeof(TextVN_PhuKien[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien10", "Null", TextVN_PhuKien[10], sizeof(TextVN_PhuKien[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien11", "Null", TextVN_PhuKien[11], sizeof(TextVN_PhuKien[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien12", "Null", TextVN_PhuKien[12], sizeof(TextVN_PhuKien[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien13", "Null", TextVN_PhuKien[13], sizeof(TextVN_PhuKien[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien14", "Null", TextVN_PhuKien[14], sizeof(TextVN_PhuKien[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien15", "Null", TextVN_PhuKien[15], sizeof(TextVN_PhuKien[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien16", "Null", TextVN_PhuKien[16], sizeof(TextVN_PhuKien[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien17", "Null", TextVN_PhuKien[17], sizeof(TextVN_PhuKien[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien18", "Null", TextVN_PhuKien[18], sizeof(TextVN_PhuKien[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien19", "Null", TextVN_PhuKien[19], sizeof(TextVN_PhuKien[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien20", "Null", TextVN_PhuKien[20], sizeof(TextVN_PhuKien[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien21", "Null", TextVN_PhuKien[21], sizeof(TextVN_PhuKien[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien22", "Null", TextVN_PhuKien[22], sizeof(TextVN_PhuKien[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien23", "Null", TextVN_PhuKien[23], sizeof(TextVN_PhuKien[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien24", "Null", TextVN_PhuKien[24], sizeof(TextVN_PhuKien[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien25", "Null", TextVN_PhuKien[25], sizeof(TextVN_PhuKien[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien26", "Null", TextVN_PhuKien[26], sizeof(TextVN_PhuKien[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien27", "Null", TextVN_PhuKien[27], sizeof(TextVN_PhuKien[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien28", "Null", TextVN_PhuKien[28], sizeof(TextVN_PhuKien[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien29", "Null", TextVN_PhuKien[29], sizeof(TextVN_PhuKien[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien30", "Null", TextVN_PhuKien[30], sizeof(TextVN_PhuKien[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien31", "Null", TextVN_PhuKien[31], sizeof(TextVN_PhuKien[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien32", "Null", TextVN_PhuKien[32], sizeof(TextVN_PhuKien[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien33", "Null", TextVN_PhuKien[33], sizeof(TextVN_PhuKien[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien34", "Null", TextVN_PhuKien[34], sizeof(TextVN_PhuKien[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien35", "Null", TextVN_PhuKien[35], sizeof(TextVN_PhuKien[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien36", "Null", TextVN_PhuKien[36], sizeof(TextVN_PhuKien[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien37", "Null", TextVN_PhuKien[37], sizeof(TextVN_PhuKien[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien38", "Null", TextVN_PhuKien[38], sizeof(TextVN_PhuKien[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien39", "Null", TextVN_PhuKien[39], sizeof(TextVN_PhuKien[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien40", "Null", TextVN_PhuKien[40], sizeof(TextVN_PhuKien[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien41", "Null", TextVN_PhuKien[41], sizeof(TextVN_PhuKien[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien42", "Null", TextVN_PhuKien[42], sizeof(TextVN_PhuKien[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien43", "Null", TextVN_PhuKien[43], sizeof(TextVN_PhuKien[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien44", "Null", TextVN_PhuKien[44], sizeof(TextVN_PhuKien[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien45", "Null", TextVN_PhuKien[45], sizeof(TextVN_PhuKien[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien46", "Null", TextVN_PhuKien[46], sizeof(TextVN_PhuKien[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien47", "Null", TextVN_PhuKien[47], sizeof(TextVN_PhuKien[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien48", "Null", TextVN_PhuKien[48], sizeof(TextVN_PhuKien[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien49", "Null", TextVN_PhuKien[49], sizeof(TextVN_PhuKien[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_PhuKien", "TextVN_PhuKien50", "Null", TextVN_PhuKien[50], sizeof(TextVN_PhuKien[50]), TEXTVN_FILE);
#endif
	//===>>>
#if(DANH_HIEU_NEW)
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu0", "Null", TextVN_DanhHieu[0], sizeof(TextVN_DanhHieu[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu1", "Null", TextVN_DanhHieu[1], sizeof(TextVN_DanhHieu[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu2", "Null", TextVN_DanhHieu[2], sizeof(TextVN_DanhHieu[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu3", "Null", TextVN_DanhHieu[3], sizeof(TextVN_DanhHieu[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu4", "Null", TextVN_DanhHieu[4], sizeof(TextVN_DanhHieu[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu5", "Null", TextVN_DanhHieu[5], sizeof(TextVN_DanhHieu[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu6", "Null", TextVN_DanhHieu[6], sizeof(TextVN_DanhHieu[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu7", "Null", TextVN_DanhHieu[7], sizeof(TextVN_DanhHieu[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu8", "Null", TextVN_DanhHieu[8], sizeof(TextVN_DanhHieu[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu9", "Null", TextVN_DanhHieu[9], sizeof(TextVN_DanhHieu[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu10", "Null", TextVN_DanhHieu[10], sizeof(TextVN_DanhHieu[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu10", "Null", TextVN_DanhHieu[10], sizeof(TextVN_DanhHieu[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu11", "Null", TextVN_DanhHieu[11], sizeof(TextVN_DanhHieu[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu12", "Null", TextVN_DanhHieu[12], sizeof(TextVN_DanhHieu[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu13", "Null", TextVN_DanhHieu[13], sizeof(TextVN_DanhHieu[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu14", "Null", TextVN_DanhHieu[14], sizeof(TextVN_DanhHieu[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu15", "Null", TextVN_DanhHieu[15], sizeof(TextVN_DanhHieu[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu16", "Null", TextVN_DanhHieu[16], sizeof(TextVN_DanhHieu[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu17", "Null", TextVN_DanhHieu[17], sizeof(TextVN_DanhHieu[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu18", "Null", TextVN_DanhHieu[18], sizeof(TextVN_DanhHieu[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu19", "Null", TextVN_DanhHieu[19], sizeof(TextVN_DanhHieu[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu20", "Null", TextVN_DanhHieu[20], sizeof(TextVN_DanhHieu[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu21", "Null", TextVN_DanhHieu[21], sizeof(TextVN_DanhHieu[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu22", "Null", TextVN_DanhHieu[22], sizeof(TextVN_DanhHieu[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu23", "Null", TextVN_DanhHieu[23], sizeof(TextVN_DanhHieu[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu24", "Null", TextVN_DanhHieu[24], sizeof(TextVN_DanhHieu[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu25", "Null", TextVN_DanhHieu[25], sizeof(TextVN_DanhHieu[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu26", "Null", TextVN_DanhHieu[26], sizeof(TextVN_DanhHieu[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu27", "Null", TextVN_DanhHieu[27], sizeof(TextVN_DanhHieu[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu28", "Null", TextVN_DanhHieu[28], sizeof(TextVN_DanhHieu[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu29", "Null", TextVN_DanhHieu[29], sizeof(TextVN_DanhHieu[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu30", "Null", TextVN_DanhHieu[30], sizeof(TextVN_DanhHieu[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu31", "Null", TextVN_DanhHieu[31], sizeof(TextVN_DanhHieu[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu32", "Null", TextVN_DanhHieu[32], sizeof(TextVN_DanhHieu[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu33", "Null", TextVN_DanhHieu[33], sizeof(TextVN_DanhHieu[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu34", "Null", TextVN_DanhHieu[34], sizeof(TextVN_DanhHieu[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu35", "Null", TextVN_DanhHieu[35], sizeof(TextVN_DanhHieu[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu36", "Null", TextVN_DanhHieu[36], sizeof(TextVN_DanhHieu[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu37", "Null", TextVN_DanhHieu[37], sizeof(TextVN_DanhHieu[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu38", "Null", TextVN_DanhHieu[38], sizeof(TextVN_DanhHieu[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu39", "Null", TextVN_DanhHieu[39], sizeof(TextVN_DanhHieu[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu40", "Null", TextVN_DanhHieu[40], sizeof(TextVN_DanhHieu[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu41", "Null", TextVN_DanhHieu[41], sizeof(TextVN_DanhHieu[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu42", "Null", TextVN_DanhHieu[42], sizeof(TextVN_DanhHieu[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu43", "Null", TextVN_DanhHieu[43], sizeof(TextVN_DanhHieu[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu44", "Null", TextVN_DanhHieu[44], sizeof(TextVN_DanhHieu[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu45", "Null", TextVN_DanhHieu[45], sizeof(TextVN_DanhHieu[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu46", "Null", TextVN_DanhHieu[46], sizeof(TextVN_DanhHieu[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu47", "Null", TextVN_DanhHieu[47], sizeof(TextVN_DanhHieu[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu48", "Null", TextVN_DanhHieu[48], sizeof(TextVN_DanhHieu[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu49", "Null", TextVN_DanhHieu[49], sizeof(TextVN_DanhHieu[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu50", "Null", TextVN_DanhHieu[50], sizeof(TextVN_DanhHieu[50]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu51", "Null", TextVN_DanhHieu[51], sizeof(TextVN_DanhHieu[51]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu52", "Null", TextVN_DanhHieu[52], sizeof(TextVN_DanhHieu[52]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu53", "Null", TextVN_DanhHieu[53], sizeof(TextVN_DanhHieu[53]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu54", "Null", TextVN_DanhHieu[54], sizeof(TextVN_DanhHieu[54]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu55", "Null", TextVN_DanhHieu[55], sizeof(TextVN_DanhHieu[55]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu56", "Null", TextVN_DanhHieu[56], sizeof(TextVN_DanhHieu[56]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu57", "Null", TextVN_DanhHieu[57], sizeof(TextVN_DanhHieu[57]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu58", "Null", TextVN_DanhHieu[58], sizeof(TextVN_DanhHieu[58]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu59", "Null", TextVN_DanhHieu[59], sizeof(TextVN_DanhHieu[59]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu60", "Null", TextVN_DanhHieu[60], sizeof(TextVN_DanhHieu[60]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu61", "Null", TextVN_DanhHieu[61], sizeof(TextVN_DanhHieu[61]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu62", "Null", TextVN_DanhHieu[62], sizeof(TextVN_DanhHieu[62]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu63", "Null", TextVN_DanhHieu[63], sizeof(TextVN_DanhHieu[63]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu64", "Null", TextVN_DanhHieu[64], sizeof(TextVN_DanhHieu[64]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu65", "Null", TextVN_DanhHieu[65], sizeof(TextVN_DanhHieu[65]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu66", "Null", TextVN_DanhHieu[66], sizeof(TextVN_DanhHieu[66]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu67", "Null", TextVN_DanhHieu[67], sizeof(TextVN_DanhHieu[67]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu68", "Null", TextVN_DanhHieu[68], sizeof(TextVN_DanhHieu[68]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu69", "Null", TextVN_DanhHieu[69], sizeof(TextVN_DanhHieu[69]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu70", "Null", TextVN_DanhHieu[70], sizeof(TextVN_DanhHieu[70]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu71", "Null", TextVN_DanhHieu[71], sizeof(TextVN_DanhHieu[71]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu72", "Null", TextVN_DanhHieu[72], sizeof(TextVN_DanhHieu[72]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu73", "Null", TextVN_DanhHieu[73], sizeof(TextVN_DanhHieu[73]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu74", "Null", TextVN_DanhHieu[74], sizeof(TextVN_DanhHieu[74]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu75", "Null", TextVN_DanhHieu[75], sizeof(TextVN_DanhHieu[75]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu76", "Null", TextVN_DanhHieu[76], sizeof(TextVN_DanhHieu[76]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu77", "Null", TextVN_DanhHieu[77], sizeof(TextVN_DanhHieu[77]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu78", "Null", TextVN_DanhHieu[78], sizeof(TextVN_DanhHieu[78]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu79", "Null", TextVN_DanhHieu[79], sizeof(TextVN_DanhHieu[79]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu80", "Null", TextVN_DanhHieu[80], sizeof(TextVN_DanhHieu[80]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu81", "Null", TextVN_DanhHieu[81], sizeof(TextVN_DanhHieu[81]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu82", "Null", TextVN_DanhHieu[82], sizeof(TextVN_DanhHieu[82]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu83", "Null", TextVN_DanhHieu[83], sizeof(TextVN_DanhHieu[83]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu84", "Null", TextVN_DanhHieu[84], sizeof(TextVN_DanhHieu[84]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu85", "Null", TextVN_DanhHieu[85], sizeof(TextVN_DanhHieu[85]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu86", "Null", TextVN_DanhHieu[86], sizeof(TextVN_DanhHieu[86]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu87", "Null", TextVN_DanhHieu[87], sizeof(TextVN_DanhHieu[87]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu88", "Null", TextVN_DanhHieu[88], sizeof(TextVN_DanhHieu[88]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu89", "Null", TextVN_DanhHieu[89], sizeof(TextVN_DanhHieu[89]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu90", "Null", TextVN_DanhHieu[90], sizeof(TextVN_DanhHieu[90]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu91", "Null", TextVN_DanhHieu[91], sizeof(TextVN_DanhHieu[91]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu92", "Null", TextVN_DanhHieu[92], sizeof(TextVN_DanhHieu[92]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu93", "Null", TextVN_DanhHieu[93], sizeof(TextVN_DanhHieu[93]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu94", "Null", TextVN_DanhHieu[94], sizeof(TextVN_DanhHieu[94]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu95", "Null", TextVN_DanhHieu[95], sizeof(TextVN_DanhHieu[95]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu96", "Null", TextVN_DanhHieu[96], sizeof(TextVN_DanhHieu[96]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu97", "Null", TextVN_DanhHieu[97], sizeof(TextVN_DanhHieu[97]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu98", "Null", TextVN_DanhHieu[98], sizeof(TextVN_DanhHieu[98]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu99", "Null", TextVN_DanhHieu[99], sizeof(TextVN_DanhHieu[99]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu100", "Null", TextVN_DanhHieu[100], sizeof(TextVN_DanhHieu[100]), TEXTVN_FILE);
#endif
	//===>>>
#if(TU_LUYEN_NEW)
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen0", "Null", TextVN_TuLuyen[0], sizeof(TextVN_TuLuyen[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen1", "Null", TextVN_TuLuyen[1], sizeof(TextVN_TuLuyen[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen2", "Null", TextVN_TuLuyen[2], sizeof(TextVN_TuLuyen[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen3", "Null", TextVN_TuLuyen[3], sizeof(TextVN_TuLuyen[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen4", "Null", TextVN_TuLuyen[4], sizeof(TextVN_TuLuyen[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen5", "Null", TextVN_TuLuyen[5], sizeof(TextVN_TuLuyen[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen6", "Null", TextVN_TuLuyen[6], sizeof(TextVN_TuLuyen[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen7", "Null", TextVN_TuLuyen[7], sizeof(TextVN_TuLuyen[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen8", "Null", TextVN_TuLuyen[8], sizeof(TextVN_TuLuyen[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen9", "Null", TextVN_TuLuyen[9], sizeof(TextVN_TuLuyen[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen10", "Null", TextVN_TuLuyen[10], sizeof(TextVN_TuLuyen[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen11", "Null", TextVN_TuLuyen[11], sizeof(TextVN_TuLuyen[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen12", "Null", TextVN_TuLuyen[12], sizeof(TextVN_TuLuyen[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen13", "Null", TextVN_TuLuyen[13], sizeof(TextVN_TuLuyen[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen14", "Null", TextVN_TuLuyen[14], sizeof(TextVN_TuLuyen[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen15", "Null", TextVN_TuLuyen[15], sizeof(TextVN_TuLuyen[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen16", "Null", TextVN_TuLuyen[16], sizeof(TextVN_TuLuyen[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen17", "Null", TextVN_TuLuyen[17], sizeof(TextVN_TuLuyen[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen18", "Null", TextVN_TuLuyen[18], sizeof(TextVN_TuLuyen[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen19", "Null", TextVN_TuLuyen[19], sizeof(TextVN_TuLuyen[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen20", "Null", TextVN_TuLuyen[20], sizeof(TextVN_TuLuyen[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen21", "Null", TextVN_TuLuyen[21], sizeof(TextVN_TuLuyen[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen22", "Null", TextVN_TuLuyen[22], sizeof(TextVN_TuLuyen[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen23", "Null", TextVN_TuLuyen[23], sizeof(TextVN_TuLuyen[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen24", "Null", TextVN_TuLuyen[24], sizeof(TextVN_TuLuyen[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen25", "Null", TextVN_TuLuyen[25], sizeof(TextVN_TuLuyen[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen26", "Null", TextVN_TuLuyen[26], sizeof(TextVN_TuLuyen[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen27", "Null", TextVN_TuLuyen[27], sizeof(TextVN_TuLuyen[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen28", "Null", TextVN_TuLuyen[28], sizeof(TextVN_TuLuyen[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen29", "Null", TextVN_TuLuyen[29], sizeof(TextVN_TuLuyen[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen30", "Null", TextVN_TuLuyen[30], sizeof(TextVN_TuLuyen[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen31", "Null", TextVN_TuLuyen[31], sizeof(TextVN_TuLuyen[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen32", "Null", TextVN_TuLuyen[32], sizeof(TextVN_TuLuyen[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen33", "Null", TextVN_TuLuyen[33], sizeof(TextVN_TuLuyen[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen34", "Null", TextVN_TuLuyen[34], sizeof(TextVN_TuLuyen[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen35", "Null", TextVN_TuLuyen[35], sizeof(TextVN_TuLuyen[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen36", "Null", TextVN_TuLuyen[36], sizeof(TextVN_TuLuyen[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen37", "Null", TextVN_TuLuyen[37], sizeof(TextVN_TuLuyen[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen38", "Null", TextVN_TuLuyen[38], sizeof(TextVN_TuLuyen[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen39", "Null", TextVN_TuLuyen[39], sizeof(TextVN_TuLuyen[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen40", "Null", TextVN_TuLuyen[40], sizeof(TextVN_TuLuyen[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen41", "Null", TextVN_TuLuyen[41], sizeof(TextVN_TuLuyen[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen42", "Null", TextVN_TuLuyen[42], sizeof(TextVN_TuLuyen[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen43", "Null", TextVN_TuLuyen[43], sizeof(TextVN_TuLuyen[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen44", "Null", TextVN_TuLuyen[44], sizeof(TextVN_TuLuyen[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen45", "Null", TextVN_TuLuyen[45], sizeof(TextVN_TuLuyen[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen46", "Null", TextVN_TuLuyen[46], sizeof(TextVN_TuLuyen[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen47", "Null", TextVN_TuLuyen[47], sizeof(TextVN_TuLuyen[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen48", "Null", TextVN_TuLuyen[48], sizeof(TextVN_TuLuyen[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen49", "Null", TextVN_TuLuyen[49], sizeof(TextVN_TuLuyen[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen50", "Null", TextVN_TuLuyen[50], sizeof(TextVN_TuLuyen[50]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen51", "Null", TextVN_TuLuyen[51], sizeof(TextVN_TuLuyen[51]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen52", "Null", TextVN_TuLuyen[52], sizeof(TextVN_TuLuyen[52]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen53", "Null", TextVN_TuLuyen[53], sizeof(TextVN_TuLuyen[53]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen54", "Null", TextVN_TuLuyen[54], sizeof(TextVN_TuLuyen[54]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen55", "Null", TextVN_TuLuyen[55], sizeof(TextVN_TuLuyen[55]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen56", "Null", TextVN_TuLuyen[56], sizeof(TextVN_TuLuyen[56]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen57", "Null", TextVN_TuLuyen[57], sizeof(TextVN_TuLuyen[57]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen58", "Null", TextVN_TuLuyen[58], sizeof(TextVN_TuLuyen[58]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen59", "Null", TextVN_TuLuyen[59], sizeof(TextVN_TuLuyen[59]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen60", "Null", TextVN_TuLuyen[60], sizeof(TextVN_TuLuyen[60]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen61", "Null", TextVN_TuLuyen[61], sizeof(TextVN_TuLuyen[61]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen62", "Null", TextVN_TuLuyen[62], sizeof(TextVN_TuLuyen[62]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen63", "Null", TextVN_TuLuyen[63], sizeof(TextVN_TuLuyen[63]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen64", "Null", TextVN_TuLuyen[64], sizeof(TextVN_TuLuyen[64]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen65", "Null", TextVN_TuLuyen[65], sizeof(TextVN_TuLuyen[65]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen66", "Null", TextVN_TuLuyen[66], sizeof(TextVN_TuLuyen[66]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen67", "Null", TextVN_TuLuyen[67], sizeof(TextVN_TuLuyen[67]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen68", "Null", TextVN_TuLuyen[68], sizeof(TextVN_TuLuyen[68]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen69", "Null", TextVN_TuLuyen[69], sizeof(TextVN_TuLuyen[69]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen70", "Null", TextVN_TuLuyen[70], sizeof(TextVN_TuLuyen[70]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen71", "Null", TextVN_TuLuyen[71], sizeof(TextVN_TuLuyen[71]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen72", "Null", TextVN_TuLuyen[72], sizeof(TextVN_TuLuyen[72]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen73", "Null", TextVN_TuLuyen[73], sizeof(TextVN_TuLuyen[73]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen74", "Null", TextVN_TuLuyen[74], sizeof(TextVN_TuLuyen[74]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen75", "Null", TextVN_TuLuyen[75], sizeof(TextVN_TuLuyen[75]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen76", "Null", TextVN_TuLuyen[76], sizeof(TextVN_TuLuyen[76]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen77", "Null", TextVN_TuLuyen[77], sizeof(TextVN_TuLuyen[77]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen78", "Null", TextVN_TuLuyen[78], sizeof(TextVN_TuLuyen[78]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen79", "Null", TextVN_TuLuyen[79], sizeof(TextVN_TuLuyen[79]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen80", "Null", TextVN_TuLuyen[80], sizeof(TextVN_TuLuyen[80]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen81", "Null", TextVN_TuLuyen[81], sizeof(TextVN_TuLuyen[81]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen82", "Null", TextVN_TuLuyen[82], sizeof(TextVN_TuLuyen[82]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen83", "Null", TextVN_TuLuyen[83], sizeof(TextVN_TuLuyen[83]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen84", "Null", TextVN_TuLuyen[84], sizeof(TextVN_TuLuyen[84]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen85", "Null", TextVN_TuLuyen[85], sizeof(TextVN_TuLuyen[85]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen86", "Null", TextVN_TuLuyen[86], sizeof(TextVN_TuLuyen[86]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen87", "Null", TextVN_TuLuyen[87], sizeof(TextVN_TuLuyen[87]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen88", "Null", TextVN_TuLuyen[88], sizeof(TextVN_TuLuyen[88]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen89", "Null", TextVN_TuLuyen[89], sizeof(TextVN_TuLuyen[89]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen90", "Null", TextVN_TuLuyen[90], sizeof(TextVN_TuLuyen[90]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen91", "Null", TextVN_TuLuyen[91], sizeof(TextVN_TuLuyen[91]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen92", "Null", TextVN_TuLuyen[92], sizeof(TextVN_TuLuyen[92]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen93", "Null", TextVN_TuLuyen[93], sizeof(TextVN_TuLuyen[93]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen94", "Null", TextVN_TuLuyen[94], sizeof(TextVN_TuLuyen[94]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen95", "Null", TextVN_TuLuyen[95], sizeof(TextVN_TuLuyen[95]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen96", "Null", TextVN_TuLuyen[96], sizeof(TextVN_TuLuyen[96]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen97", "Null", TextVN_TuLuyen[97], sizeof(TextVN_TuLuyen[97]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen98", "Null", TextVN_TuLuyen[98], sizeof(TextVN_TuLuyen[98]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen99", "Null", TextVN_TuLuyen[99], sizeof(TextVN_TuLuyen[99]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen100", "Null", TextVN_TuLuyen[100], sizeof(TextVN_TuLuyen[100]), TEXTVN_FILE);

	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen101", "Null", TextVN_TuLuyen[101], sizeof(TextVN_TuLuyen[101]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen102", "Null", TextVN_TuLuyen[102], sizeof(TextVN_TuLuyen[102]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen103", "Null", TextVN_TuLuyen[103], sizeof(TextVN_TuLuyen[103]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen104", "Null", TextVN_TuLuyen[104], sizeof(TextVN_TuLuyen[104]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen105", "Null", TextVN_TuLuyen[105], sizeof(TextVN_TuLuyen[105]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen106", "Null", TextVN_TuLuyen[106], sizeof(TextVN_TuLuyen[106]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen107", "Null", TextVN_TuLuyen[107], sizeof(TextVN_TuLuyen[107]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen108", "Null", TextVN_TuLuyen[108], sizeof(TextVN_TuLuyen[108]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen109", "Null", TextVN_TuLuyen[109], sizeof(TextVN_TuLuyen[109]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen110", "Null", TextVN_TuLuyen[110], sizeof(TextVN_TuLuyen[110]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen111", "Null", TextVN_TuLuyen[111], sizeof(TextVN_TuLuyen[111]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen112", "Null", TextVN_TuLuyen[112], sizeof(TextVN_TuLuyen[112]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen113", "Null", TextVN_TuLuyen[113], sizeof(TextVN_TuLuyen[113]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen114", "Null", TextVN_TuLuyen[114], sizeof(TextVN_TuLuyen[114]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen115", "Null", TextVN_TuLuyen[115], sizeof(TextVN_TuLuyen[115]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen116", "Null", TextVN_TuLuyen[116], sizeof(TextVN_TuLuyen[116]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen117", "Null", TextVN_TuLuyen[117], sizeof(TextVN_TuLuyen[117]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen118", "Null", TextVN_TuLuyen[118], sizeof(TextVN_TuLuyen[118]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen119", "Null", TextVN_TuLuyen[119], sizeof(TextVN_TuLuyen[119]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen120", "Null", TextVN_TuLuyen[120], sizeof(TextVN_TuLuyen[120]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen121", "Null", TextVN_TuLuyen[121], sizeof(TextVN_TuLuyen[121]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen122", "Null", TextVN_TuLuyen[122], sizeof(TextVN_TuLuyen[122]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen123", "Null", TextVN_TuLuyen[123], sizeof(TextVN_TuLuyen[123]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen124", "Null", TextVN_TuLuyen[124], sizeof(TextVN_TuLuyen[124]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen125", "Null", TextVN_TuLuyen[125], sizeof(TextVN_TuLuyen[125]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen126", "Null", TextVN_TuLuyen[126], sizeof(TextVN_TuLuyen[126]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen127", "Null", TextVN_TuLuyen[127], sizeof(TextVN_TuLuyen[127]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen128", "Null", TextVN_TuLuyen[128], sizeof(TextVN_TuLuyen[128]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen129", "Null", TextVN_TuLuyen[129], sizeof(TextVN_TuLuyen[129]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen130", "Null", TextVN_TuLuyen[130], sizeof(TextVN_TuLuyen[130]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen131", "Null", TextVN_TuLuyen[131], sizeof(TextVN_TuLuyen[131]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen132", "Null", TextVN_TuLuyen[132], sizeof(TextVN_TuLuyen[132]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen133", "Null", TextVN_TuLuyen[133], sizeof(TextVN_TuLuyen[133]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen134", "Null", TextVN_TuLuyen[134], sizeof(TextVN_TuLuyen[134]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen135", "Null", TextVN_TuLuyen[135], sizeof(TextVN_TuLuyen[135]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen136", "Null", TextVN_TuLuyen[136], sizeof(TextVN_TuLuyen[136]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen137", "Null", TextVN_TuLuyen[137], sizeof(TextVN_TuLuyen[137]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen138", "Null", TextVN_TuLuyen[138], sizeof(TextVN_TuLuyen[138]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen139", "Null", TextVN_TuLuyen[139], sizeof(TextVN_TuLuyen[139]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen140", "Null", TextVN_TuLuyen[140], sizeof(TextVN_TuLuyen[140]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen141", "Null", TextVN_TuLuyen[141], sizeof(TextVN_TuLuyen[141]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen142", "Null", TextVN_TuLuyen[142], sizeof(TextVN_TuLuyen[142]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen143", "Null", TextVN_TuLuyen[143], sizeof(TextVN_TuLuyen[143]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen144", "Null", TextVN_TuLuyen[144], sizeof(TextVN_TuLuyen[144]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen145", "Null", TextVN_TuLuyen[145], sizeof(TextVN_TuLuyen[145]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen146", "Null", TextVN_TuLuyen[146], sizeof(TextVN_TuLuyen[146]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen147", "Null", TextVN_TuLuyen[147], sizeof(TextVN_TuLuyen[147]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen148", "Null", TextVN_TuLuyen[148], sizeof(TextVN_TuLuyen[148]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen149", "Null", TextVN_TuLuyen[149], sizeof(TextVN_TuLuyen[149]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen150", "Null", TextVN_TuLuyen[150], sizeof(TextVN_TuLuyen[150]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen151", "Null", TextVN_TuLuyen[151], sizeof(TextVN_TuLuyen[151]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen152", "Null", TextVN_TuLuyen[152], sizeof(TextVN_TuLuyen[152]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen153", "Null", TextVN_TuLuyen[153], sizeof(TextVN_TuLuyen[153]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen154", "Null", TextVN_TuLuyen[154], sizeof(TextVN_TuLuyen[154]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen155", "Null", TextVN_TuLuyen[155], sizeof(TextVN_TuLuyen[155]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen156", "Null", TextVN_TuLuyen[156], sizeof(TextVN_TuLuyen[156]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen157", "Null", TextVN_TuLuyen[157], sizeof(TextVN_TuLuyen[157]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen158", "Null", TextVN_TuLuyen[158], sizeof(TextVN_TuLuyen[158]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen159", "Null", TextVN_TuLuyen[159], sizeof(TextVN_TuLuyen[159]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen160", "Null", TextVN_TuLuyen[160], sizeof(TextVN_TuLuyen[160]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen161", "Null", TextVN_TuLuyen[161], sizeof(TextVN_TuLuyen[161]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen162", "Null", TextVN_TuLuyen[162], sizeof(TextVN_TuLuyen[162]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen163", "Null", TextVN_TuLuyen[163], sizeof(TextVN_TuLuyen[163]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen164", "Null", TextVN_TuLuyen[164], sizeof(TextVN_TuLuyen[164]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen165", "Null", TextVN_TuLuyen[165], sizeof(TextVN_TuLuyen[165]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen166", "Null", TextVN_TuLuyen[166], sizeof(TextVN_TuLuyen[166]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen167", "Null", TextVN_TuLuyen[167], sizeof(TextVN_TuLuyen[167]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen168", "Null", TextVN_TuLuyen[168], sizeof(TextVN_TuLuyen[168]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen169", "Null", TextVN_TuLuyen[169], sizeof(TextVN_TuLuyen[169]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen170", "Null", TextVN_TuLuyen[170], sizeof(TextVN_TuLuyen[170]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen171", "Null", TextVN_TuLuyen[171], sizeof(TextVN_TuLuyen[171]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen172", "Null", TextVN_TuLuyen[172], sizeof(TextVN_TuLuyen[172]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen173", "Null", TextVN_TuLuyen[173], sizeof(TextVN_TuLuyen[173]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen174", "Null", TextVN_TuLuyen[174], sizeof(TextVN_TuLuyen[174]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen175", "Null", TextVN_TuLuyen[175], sizeof(TextVN_TuLuyen[175]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen176", "Null", TextVN_TuLuyen[176], sizeof(TextVN_TuLuyen[176]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen177", "Null", TextVN_TuLuyen[177], sizeof(TextVN_TuLuyen[177]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen178", "Null", TextVN_TuLuyen[178], sizeof(TextVN_TuLuyen[178]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen179", "Null", TextVN_TuLuyen[179], sizeof(TextVN_TuLuyen[179]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen180", "Null", TextVN_TuLuyen[180], sizeof(TextVN_TuLuyen[180]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen181", "Null", TextVN_TuLuyen[181], sizeof(TextVN_TuLuyen[181]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen182", "Null", TextVN_TuLuyen[182], sizeof(TextVN_TuLuyen[182]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen183", "Null", TextVN_TuLuyen[183], sizeof(TextVN_TuLuyen[183]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen184", "Null", TextVN_TuLuyen[184], sizeof(TextVN_TuLuyen[184]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen185", "Null", TextVN_TuLuyen[185], sizeof(TextVN_TuLuyen[185]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen186", "Null", TextVN_TuLuyen[186], sizeof(TextVN_TuLuyen[186]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen187", "Null", TextVN_TuLuyen[187], sizeof(TextVN_TuLuyen[187]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen188", "Null", TextVN_TuLuyen[188], sizeof(TextVN_TuLuyen[188]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen189", "Null", TextVN_TuLuyen[189], sizeof(TextVN_TuLuyen[189]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen190", "Null", TextVN_TuLuyen[190], sizeof(TextVN_TuLuyen[190]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen191", "Null", TextVN_TuLuyen[191], sizeof(TextVN_TuLuyen[191]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen192", "Null", TextVN_TuLuyen[192], sizeof(TextVN_TuLuyen[192]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen193", "Null", TextVN_TuLuyen[193], sizeof(TextVN_TuLuyen[193]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen194", "Null", TextVN_TuLuyen[194], sizeof(TextVN_TuLuyen[194]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen195", "Null", TextVN_TuLuyen[195], sizeof(TextVN_TuLuyen[195]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen196", "Null", TextVN_TuLuyen[196], sizeof(TextVN_TuLuyen[196]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen197", "Null", TextVN_TuLuyen[197], sizeof(TextVN_TuLuyen[197]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen198", "Null", TextVN_TuLuyen[198], sizeof(TextVN_TuLuyen[198]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen199", "Null", TextVN_TuLuyen[199], sizeof(TextVN_TuLuyen[199]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen200", "Null", TextVN_TuLuyen[200], sizeof(TextVN_TuLuyen[200]), TEXTVN_FILE);

	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen201", "Null", TextVN_TuLuyen[201], sizeof(TextVN_TuLuyen[201]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen202", "Null", TextVN_TuLuyen[202], sizeof(TextVN_TuLuyen[202]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen203", "Null", TextVN_TuLuyen[203], sizeof(TextVN_TuLuyen[203]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen204", "Null", TextVN_TuLuyen[204], sizeof(TextVN_TuLuyen[204]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen205", "Null", TextVN_TuLuyen[205], sizeof(TextVN_TuLuyen[205]), TEXTVN_FILE);
#endif
	//===>>>
}

void GensLogoPlayer(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)
{
	gObjUser.Refresh();
	RenderBitmap(a1, a2 - valor, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

//void CRenderBoolean(int a1, int a2, char *a3)
//{
//	int result = *(DWORD *)(a3 + 668);
//
//	if (*(BYTE *)(result + 800) == 1)
//	{
//		CreateGuildMark(*(WORD *)(result + 124), 1);
//		RenderBitmap(31740, a1 - 15, a2 + 2, 16.0, 16.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
//	}
//
//	RenderBoolean(a1, a2, a3);
//}

void PlayerGuildLogo(int a1, int a2, char *a3) // ok
{
	gObjUser.Refresh();

	int result = *(DWORD *)(a3 + 668);

	if ((*(WORD *)(result + 124) == 0)) // ok
	{
		valor = 15;
		CreateGuildMark(*(WORD *)(result + 124), 1);
		RenderBitmap(31740, a1 - 18, a2 + 2, 16.0, 16.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}

	if (!(*(WORD *)(result + 124) == 0)) // ok
	{
		valor = 15;
		CreateGuildMark(*(WORD *)(result + 124), 1);
		RenderBitmap(31740, a1 - 18, a2 + 2, 16.0, 16.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}

	RenderBoolean(a1, a2, a3);
}
// ----------------------------------------------------------------------------------------------

void PopUpErrorCheckMsgBox(const char* szErrorMsg, bool bForceDestroy)
{
	MessageBox(NULL, szErrorMsg, NULL, MB_OK);
	SendMessage(NULL, WM_DESTROY, 0, 0);
}

// ----------------------------------------------------------------------------------------------
void Other::Crack()
{
#if(VANTHANH > 3)
	// Fix error load file
	SetCompleteHook(0xE8, 0x00614AEF, &PopUpErrorCheckMsgBox);//-- open texture model
	SetCompleteHook(0xE8, 0x00772460, &PopUpErrorCheckMsgBox);//-- open texture
#endif
	//----------------------------------------------------------------------
	//MiniBuff Icon
	SetFloat((PVOID)(0x00D43220), 10);
	SetFloat((PVOID)(0x00D43224), 14);
	SetByte((PVOID)(0x00777E70), 0x16);
	//----------------------------------------------------------------------
	//-> level xoa nhan vat
	SetDword((PVOID)(0x00405B7A + 2), 401); // Delete rule
	SetDword((PVOID)(0x0040CC3F + 1), 401); // Error message
	//----------------------------------------------------------------------
	//Fix CTRL Freeze
	//SetByte((LPVOID)0x0052101B, 0x02);
	//----------------------------------------------------------------------
    //SetCompleteHook(0xE8, 0x005BAFAB, &CRenderBoolean);

	SetCompleteHook(0xE8, 0x005BAFAB, &PlayerGuildLogo);

	SetCompleteHook(0xE8, 0x007C5DB0, &GensLogoPlayer);

	SetByte((DWORD)(0x81C03FA), 0x01); // Show Ten  Nhan Vat

	//SetCompleteHook(0xE8, 0x005BAFAB, &GetBitBarname);
	
	//if (gProtect.m_MainInfo.PutoEllQueLoLea != 1)
	//{
	//	//SetCompleteHook(0xE8, 0x005BAFAB, &GetBitBarname);
	//	SetByte((PVOID)(0x81C03FA), 0x01); // Show Ten  Nhan Vat
	//}


	SetOp2((LPVOID)0x004060D0, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D2882, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D28EB, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D2957, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D29C1, this->LoadNewFontA, ASM::CALL, 6);

}
// ----------------------------------------------------------------------------------------------

HFONT Other::LoadNewFontA(int nHeight,
	int nWidth,
	int nEscapement,
	int nOrientation,
	int fnWeight,
	DWORD fdwItalic,
	DWORD fdwUnderline,
	DWORD fdwStrikeOut,
	DWORD fdwCharSet,
	DWORD fdwOutputPrecision,
	DWORD fdwClipPrecision,
	DWORD fdwQuality,
	DWORD fdwPitchAndFamily,
	LPCTSTR lpszFace) {
	int Height = 13; // 13
	int Width = 0;
	int Italic = 0;
	DWORD UnderLine = 0; // Gach Chân
	DWORD StrikeOut = 0;
	return CreateFontA(Height, Width, 0, 0, fnWeight, Italic, UnderLine, StrikeOut, DEFAULT_CHARSET, 0, 0, fdwQuality, 0, "Tahoma");
}