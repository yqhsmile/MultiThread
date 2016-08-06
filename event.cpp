#include <windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI thread1_fun(LPVOID lpParameter);
DWORD WINAPI thread2_fun(LPVOID lpParameter);

HANDLE hevent;
int num=0;

int main()
{
	HANDLE h_thread1,h_thread2;
	hevent=::CreateEvent(NULL,false,false,NULL);
	::SetEvent(hevent);
	h_thread1=::CreateThread(NULL,0,thread1_fun,NULL,0,NULL);
	cout<<"�߳�1��ʼ���У�"<<endl;
	h_thread2=::CreateThread(NULL,0,thread2_fun,NULL,0,NULL);
	cout<<"�߳�2��ʼ���У�"<<endl;
	

	::CloseHandle(h_thread1);
	::CloseHandle(h_thread2);
	::Sleep(1000);


	return 0;
}

DWORD WINAPI thread1_fun(LPVOID lpParameter)
{
	while(1)
	{
		::WaitForSingleObject(hevent,INFINITE);
		::ResetEvent(hevent);
		if (num<1000)
		{
			num++;
			::Sleep(1000);
			cout<<"�߳�1��"<<num<<endl;
			::SetEvent(hevent);
		}
		else
		{
			::SetEvent(hevent);
			break;
		}
	}
	return 0;
}

DWORD WINAPI thread2_fun(LPVOID lpParameter)
{
	while(1)
	{
		::WaitForSingleObject(hevent,INFINITE);
		::ResetEvent(hevent);
		if (num<1000)
		{
			num++;
			::Sleep(1000);
			cout<<"�߳�2��"<<num<<endl;
			::SetEvent(hevent);
		}
		else
		{
			::SetEvent(hevent);
			break;
		}
	}
	return 0;
}