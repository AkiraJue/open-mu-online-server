//=======================================================================================
//= NewsSystem.h
//=======================================================================================

//------------------------------------------------------
//- Start
//------------------------------------------------------
class gNewsSystem
{
public:
	void Load();
	void Start();
	void SendMsg(int Type,char * Text, ...);
	int Count;
private:
	int Value[6];
	int String[255];
};
void Manage(void * lpParam);
//------------------------------------------------------
//- Structures
//------------------------------------------------------
typedef struct gNewsList
{
	int News_Day;
	int News_Month;
	int News_Year;
	int News_Hour;
	int News_Minute;
	char News_Line[255];
	int News_Type;
}xNewsList;

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern gNewsSystem NewsSystem;
extern xNewsList NewsList[255];