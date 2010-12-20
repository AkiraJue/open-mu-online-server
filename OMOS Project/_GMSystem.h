//=======================================================================================
//= GMSystem.h
//=======================================================================================

//------------------------------------------------------
//- Start
//------------------------------------------------------
class gGMSystem
{
public:
	void Load();
	int CheckCommand(char* GMName, char* Command);
private:
	int Count;
	int Value[4];
	int Name[11];
};

//------------------------------------------------------
//- Structures
//------------------------------------------------------
typedef struct gGMCommandList
{
	char Name[11];
	int Gg;
	int Reload;
	int Drop;
	int Gmove;
}xGMCommandList;

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern gGMSystem GMSystem;
extern xGMCommandList GMCommandList[255];