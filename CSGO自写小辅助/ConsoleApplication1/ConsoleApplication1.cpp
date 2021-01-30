// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<Windows.h>
#include<TlHelp32.h>
#include<d3d9.h>

#define Enemypen 0x000000FF
HBRUSH EnemyBrush = CreateSolidBrush(0x000000FF);

using namespace std;


DWORD ProcessID;

DWORD GetProcId(const wchar_t* procName)  //获取进程名
{
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!_wcsicmp(procEntry.szExeFile, procName))
				{
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));

		}
	}
	CloseHandle(hSnap);
	return procId;
}



uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName) //进程模块基址定义API通用
{
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(ModuleEntry32);
		if (Module32First(hSnap, &ModuleEntry32))
		{
			do
			{
				if (!wcsicmp(ModuleEntry32.szModule, modName))
				{
					modBaseAddr = (uintptr_t)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &ModuleEntry32));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}

uintptr_t moduleBase = GetModuleBaseAddress(GetProcId(L"csgo.exe"), L"client.dll");


DWORD human = moduleBase + 0x4DA1F24;
DWORD human1 = moduleBase + 0x4DA1F34;
DWORD human2 = moduleBase + 0x4DA1F24;
DWORD human3 = moduleBase + 0x4DA1F24;


DWORD BULLET = moduleBase + 0x051D6C9C;

DWORD bulletfirst = 0xBC;
DWORD bulletsecond = 0x40;
DWORD bulletthird = 0x64;


DWORD bloodfirst = 0x100;

DWORD Xfirst = 0x138;

DWORD Yfirst = 0x13c;

DWORD Zfirst = 0x140;








int main()
{

	HWND hwnd = FindWindowA(0, "Counter-Strike: Global Offensive");

	GetWindowThreadProcessId(hwnd, &ProcessID);

	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);

	DWORD humanbasevalue = 0;
	DWORD humanbasevalue1 = 0;
	DWORD humanbasevalue2 = 0;
	DWORD humanbasevalue3 = 0;
	DWORD humanbasevalue4 = 0;
	DWORD humanbasevalue5 = 0;
	DWORD humanbasevalue6 = 0;
	DWORD humanbasevalue7 = 0;
	DWORD humanbasevalue8 = 0;
	DWORD humanbasevalue9 = 0;
	DWORD humanbasevalue10 = 0;
	DWORD humanbasevalue11 = 0;
	DWORD humanbasevalue12 = 0;
	DWORD bulletbasevalue = 0;
	DWORD bulletsecondvalue = 0;
	DWORD bulletthirdvalue = 0;
	DWORD bulletafter = 0;

	DWORD nice = 0;
	DWORD nice1= 0;
	float xnice = 0;
	float ynice = 0;
	float znice = 0;









	while (true)
	{
		
		system("cls");
		
		ReadProcessMemory(pHandle, (LPVOID)human, &humanbasevalue, sizeof(nice), 0);
		ReadProcessMemory(pHandle, (LPVOID)human1, &humanbasevalue1, sizeof(nice), 0);


		ReadProcessMemory(pHandle, (LPVOID)(humanbasevalue + bloodfirst), &nice, sizeof(nice), 0);
		ReadProcessMemory(pHandle, (LPVOID)(humanbasevalue1 + bloodfirst), &nice1, sizeof(nice), 0);

		ReadProcessMemory(pHandle, (LPVOID)(humanbasevalue + Xfirst), &xnice, sizeof(float), 0);

		ReadProcessMemory(pHandle, (LPVOID)(humanbasevalue + Yfirst), &ynice, sizeof(float), 0);
		ReadProcessMemory(pHandle, (LPVOID)(humanbasevalue + Zfirst), &znice, sizeof(float), 0);

		ReadProcessMemory(pHandle, (LPVOID)BULLET, &bulletbasevalue, sizeof(nice), 0);
		ReadProcessMemory(pHandle, (LPVOID)(bulletbasevalue + bulletfirst),&bulletsecondvalue,sizeof(nice), 0);
		ReadProcessMemory(pHandle, (LPVOID)(bulletsecondvalue + bulletsecond), &bulletthirdvalue, sizeof(nice), 0);
		ReadProcessMemory(pHandle, (LPVOID)(bulletthirdvalue + bulletthird), &bulletafter, sizeof(nice), 0);



		if (nice < 30)
		{
			cout << "你当前生命值过低无法对枪" << endl;
		}
		else
		{
			cout << "血量目前很满，不用担心" << endl;
		}
		
		
		
		
		
		if (hwnd)
		{
			cout << "已经找到CSGO游戏进程" << endl;

			cout << "本人血值 " << nice << endl;
			cout << "敌人血值 " << nice1 << endl;
			cout << "本人X坐标" << xnice << endl;
			cout << "本人Y坐标" << ynice << endl;
			cout << "本人Z坐标" << znice << endl;
			cout << "本人弹药数" << bulletafter << endl;


		}
		else
		{
			cout << "未找到CSGO游戏进程" << endl;

		}

		

			
		if (bulletafter == 20)
		{
		cout << "当前武器为gay gun" << endl;

		}
		if (bulletafter == 150)
		{
		cout << "当前武器为内格夫" << endl;
		}
		
		
		}
		

	}






    
	