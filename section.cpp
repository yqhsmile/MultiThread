//ѧϰ��ô�����Ͷ����̺߳����Լ�ʹ�ú���CreateThread()�����̵߳Ĵ���
#include <iostream>
#include <afxmt.h>

using namespace std;
//�����̺߳���
DWORD WINAPI thread1_fun(LPVOID lpParameter);
DWORD WINAPI thread2_fun(LPVOID lpParameter);

CCriticalSection sec;
int num=0;

int main()
{
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
			return 0;
		}
	}
	
	return 0;
}

DWORD WINAPI thread1_fun(LPVOID lpParameter)
{
	
	sec.Lock();
	num++;
	
	cout<<"�߳�1����ִ�д���"<<num<<endl;
	sec.Unlock();
	
	return 0;
}

DWORD WINAPI thread2_fun(LPVOID lpParameter)
{
	sec.Lock();
	num++;
	
	cout<<"�߳�2����ִ�д���"<<num<<endl;
	sec.Unlock();
	
	return 0;
}