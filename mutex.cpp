#include <windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI thread1_fun(LPVOID lpParameter);
DWORD WINAPI thread2_fun(LPVOID lpParameter);

HANDLE hmutex;
int num=0;

int main()
{
	HANDLE h_thread1,h_thread2;
	hmutex=::CreateMutex(NULL,false,NULL);
	
	h_thread1=::CreateThread(NULL,0,thread1_fun,NULL,0,NULL);
	cout<<"线程1开始运行！"<<endl;
	h_thread2=::CreateThread(NULL,0,thread2_fun,NULL,0,NULL);
	cout<<"线程2开始运行！"<<endl;
	
	
	::CloseHandle(h_thread1);
	::CloseHandle(h_thread2);
	::Sleep(1000);
	
	
	return 0;
}

DWORD WINAPI thread1_fun(LPVOID lpParameter)
{
	while(1)
	{
		::WaitForSingleObject(hmutex,INFINITE);
		
		if (num<1000)
		{
			num++;
			::Sleep(1000);
			cout<<"线程1："<<num<<endl;
			::ReleaseMutex(hmutex);
		}
		else
		{
			::ReleaseMutex(hmutex);
			break;
		}
	}
	return 0;
}

DWORD WINAPI thread2_fun(LPVOID lpParameter)
{
	while(1)
	{
		::WaitForSingleObject(hmutex,INFINITE);
		
		if (num<1000)
		{
			num++;
			::Sleep(1000);
			cout<<"线程2："<<num<<endl;
			::ReleaseMutex(hmutex);
		}
		else
		{
			::ReleaseMutex(hmutex);
			break;
		}
	}
	return 0;
}
