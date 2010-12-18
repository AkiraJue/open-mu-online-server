typedef struct IPBlock
{
	char IP[16];
}IPBLOCK;

//Structures
extern IPBLOCK IPBlockInfo[255];
extern int IPBlockCount;

void LoadIPBlock();
