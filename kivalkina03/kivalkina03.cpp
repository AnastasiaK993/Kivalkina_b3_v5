
#include <iostream>
#include <Windows.h>
using namespace std;


const wchar_t* name_sema = L"Global\\sema";

const wchar_t* name_event = L"Global\\event";
int main()
{

	setlocale(0, "rus");
	HANDLE sema = CreateSemaphore(NULL,2,2,name_sema);
	HANDLE event = CreateEvent(NULL, true, false, name_event);
	DWORD SEMAFOR = WaitForSingleObject(sema, 0);

	if (SEMAFOR == WAIT_OBJECT_0)
	{
		cout << "программа запустилась";
		DWORD eventevent = WaitForSingleObject(event, INFINITE);
		if(eventevent == WAIT_OBJECT_0)
		{ 
			cout << "больше 2 прог нельзя";
			Sleep(10000);
		}
		Sleep(10000);
		
ReleaseSemaphore(sema,1,NULL);
CloseHandle(event);
	CloseHandle(sema);
	return 0;
	}
	else {
		PulseEvent(event);

	}
	CloseHandle(sema);
	CloseHandle(event);
	return 0;
	
}
