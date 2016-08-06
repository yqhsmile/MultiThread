//ѧϰ��ô�����Ͷ����̺߳����Լ�ʹ�ú���CreateThread()�����̵߳Ĵ���
#include <windows.h>
#include <iostream>

using namespace std;
//�����̺߳���
DWORD WINAPI thread1_fun(LPVOID lpParameter);
DWORD WINAPI thread2_fun(LPVOID lpParameter);

CRITICAL_SECTION sec;
static int num=0;

int main()
{
	InitializeCriticalSection(&sec);
	HANDLE h_thread1,h_thread2;
	h_thread1=::CreateThread(NULL,0,thread1_fun,NULL,0,NULL);
	cout<<"�߳�1��ʼִ�У�"<<endl;
	h_thread2=::CreateThread(NULL,0,thread2_fun,NULL,0,NULL);
	cout<<"�߳�2��ʼִ�У�"<<endl;

	
	::CloseHandle(h_thread1);
	::CloseHandle(h_thread2);

	
	::Sleep(1000);
	while (1)
	{
		if (getchar()=='q')
		{
			DeleteCriticalSection(&sec);
			return 0;
		}
	}

	return 0;
}

DWORD WINAPI thread1_fun(LPVOID lpParameter)
{
	
	while (1)
	{
		EnterCriticalSection(&sec);
		num++;
		if (num<500)
		{
			::Sleep(100);
			cout<<"�߳�1����ִ�д���"<<num<<endl;
			LeaveCriticalSection(&sec);
		}
		else
		{
			LeaveCriticalSection(&sec);
			break;
		}
	}
	
	return 0;
}

DWORD WINAPI thread2_fun(LPVOID lpParameter)
{

	while (1)
	{
		EnterCriticalSection(&sec);
		num++;
		if (num<500)
		{
			::Sleep(100);
			cout<<"�߳�2����ִ�д���"<<num<<endl;
			LeaveCriticalSection(&sec);
		}
		else
		{
			LeaveCriticalSection(&sec);
			break;
		}
	}
	
	return 0;
}