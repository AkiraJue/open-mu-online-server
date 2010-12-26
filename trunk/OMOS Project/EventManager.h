//=======================================================================================
//= EventManager.cpp
//=======================================================================================
//------------------------------------------------------
//- Start
//------------------------------------------------------
class cEventManager
{
public:
	void Load();
	void Start();
	void EditExp(char Exp[256]);
	void EditDrop(int Drop);
	int Count;

	int HappyHourStarted;
private:
	int Value[6];
};

void EventsManage(void * lpParam);
void HappyHourEvent(void * lpParam);
//------------------------------------------------------
//- Structures
//------------------------------------------------------
typedef struct gEventList
{
	int Type;
	int Day;
	int Month;
	int Year;
	int Hour;
	int Minute;
}xEventList;

enum EventIDs
{
	HappyHour	= 0
};

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern cEventManager EventManager;
extern xEventList EventList[255];