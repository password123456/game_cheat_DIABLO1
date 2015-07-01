#include <windows.h>
#include "resource.h"
#include "Tlhelp32.h"


#define			CLASS_NAME				"DIABLO"


HDC hdc;
PAINTSTRUCT ps;

DWORD dwPid = 0;

HWND hWindow;


BOOL MAXEXPlV50ON(DWORD dwPid);
BOOL InfiniteSTATPOINTON(DWORD dwPid);
BOOL FREESHOPCOUPONON(DWORD dwPid);

BOOL CALLBACK MainDlgProc(HWND hDlg,UINT iMessage,WPARAM wParam,LPARAM lParam);
HINSTANCE g_hInst;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdParam,int nCmdShow)
{
    g_hInst=hInstance;
	WNDCLASS WndClass;
	WndClass.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON));
    HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, MainDlgProc);
	ShowWindow(hWnd, SW_SHOW);
	
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			SendMessage(hWnd, msg.message, msg.wParam, msg.lParam);
		}
		
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

BOOL CALLBACK MainDlgProc(HWND hDlg,UINT iMessage,WPARAM wParam,LPARAM lParam)
{

	
	switch(iMessage) 
	{
	case WM_RBUTTONDOWN:
		MessageBox(NULL,"http://www.playGameWithCheat.com\r\n\nsendmefuture@gmail.com", "Thank For Playing", MB_OK);
		return FALSE;
	case WM_KEYDOWN:
		if (GetAsyncKeyState(VK_F1) & 0X8000)
		{
			hWindow = ::FindWindow(CLASS_NAME, NULL);
			
			if (!hWindow)
			{
				MessageBox(NULL,"DIABLO 1이 실행되지 않았습니다.", "DIABLO 1 - 3 Trainer",MB_OK | MB_ICONWARNING);
				break;
			}
			else
			{
				GetWindowThreadProcessId(hWindow, &dwPid);
				MAXEXPlV50ON(dwPid);
				return FALSE;
			}
		}
		if (GetAsyncKeyState(VK_F2) & 0X8000)
		{
			hWindow = ::FindWindow(CLASS_NAME, NULL);
			
			if (!hWindow)
			{
				MessageBox(NULL,"DIABLO 1이 실행되지 않았습니다.", "DIABLO 1 - 3 Trainer",MB_OK | MB_ICONWARNING);
				break;
			}
			else
			{
				GetWindowThreadProcessId(hWindow, &dwPid);
				InfiniteSTATPOINTON(dwPid);
				return FALSE;
							
			}
		}
	
		if (GetAsyncKeyState(VK_F3) & 0X8000)
		{
			hWindow = ::FindWindow(CLASS_NAME, NULL);
			
			if (!hWindow)
			{
				MessageBox(NULL,"DIABLO 1이 실행되지 않았습니다.", "DIABLO 1 - 3 Trainer",MB_OK | MB_ICONWARNING);
				break;
			}
			else
			{
				GetWindowThreadProcessId(hWindow, &dwPid);
				FREESHOPCOUPONON(dwPid);
				return FALSE;
				
			}
		}
		
		return FALSE;
		
	case WM_INITDIALOG:
		SendMessage(hDlg,WM_SETICON,TRUE, (LPARAM)LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON)));
		return FALSE;
	
	case WM_COMMAND:
		switch (wParam)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return FALSE;
		}
	}
	return FALSE;
}


BOOL MAXEXPlV50ON(DWORD dwPid)
{
	LPVOID lpAddress = (LPVOID)0x44FA4B;
	BYTE lpPatchBuffer[] = {0xEB};

	LPVOID lpAddress1 = (LPVOID)0x686604;
	BYTE lpPatchBuffer1[] = {0x2A,0xCF,0x1F,0x4E};
	
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	
	DWORD dwOldProtect = 0;
	DWORD dwWritten = 0;

	VirtualProtectEx(hProcess, lpAddress, sizeof(lpPatchBuffer), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite = WriteProcessMemory(hProcess, lpAddress, (LPVOID)lpPatchBuffer, sizeof(lpPatchBuffer), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress1, sizeof(lpPatchBuffer1), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite1 = WriteProcessMemory(hProcess, lpAddress1, (LPVOID)lpPatchBuffer1, sizeof(lpPatchBuffer1), &dwWritten );
	

	if (bWrite && bWrite1 )
	{
		
		MessageBox(NULL,"Lv50 / EXP 충전 완료.", "DIABLO 1 - 3 Trainer",MB_OK | MB_ICONWARNING);
		return TRUE;
	}
	CloseHandle(hProcess);
	return 0;
	
}

BOOL InfiniteSTATPOINTON(DWORD dwPid)
{
	LPVOID lpAddress = (LPVOID)0x4063F8;
	BYTE lpPatchBuffer[] = {0x90,0x90};
	

	LPVOID lpAddress1 = (LPVOID)0x6865cc;
	BYTE lpPatchBuffer1[] = {0x10};

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	
	DWORD dwOldProtect = 0;
	DWORD dwWritten = 0;
	VirtualProtectEx(hProcess, lpAddress, sizeof(lpPatchBuffer), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite = WriteProcessMemory(hProcess, lpAddress, (LPVOID)lpPatchBuffer, sizeof(lpPatchBuffer), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress1, sizeof(lpPatchBuffer1), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite1 = WriteProcessMemory(hProcess, lpAddress1, (LPVOID)lpPatchBuffer1, sizeof(lpPatchBuffer1), &dwWritten );
	

	if (bWrite && bWrite1)
	{
		
		MessageBox(NULL,"스탯 포인트 무한 완료.", "DIABLO 1 - 3 Trainer",MB_OK | MB_ICONWARNING);
		return TRUE;
	}
	
	CloseHandle(hProcess);
	return 0;
	
}

BOOL FREESHOPCOUPONON(DWORD dwPid)
{
	LPVOID lpAddress = (LPVOID)0x45ac75;
	BYTE lpPatchBuffer[] = {0xEB};
	
	LPVOID lpAddress1 = (LPVOID)0x45ADFE;
	BYTE lpPatchBuffer1[] = {0xEB};

	LPVOID lpAddress2 = (LPVOID)0x45B6E0;
	BYTE lpPatchBuffer2[] = {0xEB};

	LPVOID lpAddress3 = (LPVOID)0x45BC00;
	BYTE lpPatchBuffer3[] = {0xEB};

	LPVOID lpAddress4 = (LPVOID)0x45B4B8;
	BYTE lpPatchBuffer4[] = {0xEB};

	LPVOID lpAddress5 = (LPVOID)0x0045B8DD;
	BYTE lpPatchBuffer5[] = {0xEB};

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	
	DWORD dwOldProtect = 0;
	DWORD dwWritten = 0;

	VirtualProtectEx(hProcess, lpAddress, sizeof(lpPatchBuffer), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite = WriteProcessMemory(hProcess, lpAddress, (LPVOID)lpPatchBuffer, sizeof(lpPatchBuffer), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress1, sizeof(lpPatchBuffer1), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite1 = WriteProcessMemory(hProcess, lpAddress1, (LPVOID)lpPatchBuffer1, sizeof(lpPatchBuffer1), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress2, sizeof(lpPatchBuffer2), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite2 = WriteProcessMemory(hProcess, lpAddress2, (LPVOID)lpPatchBuffer2, sizeof(lpPatchBuffer2), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress3, sizeof(lpPatchBuffer3), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite3 = WriteProcessMemory(hProcess, lpAddress3, (LPVOID)lpPatchBuffer3, sizeof(lpPatchBuffer3), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress4, sizeof(lpPatchBuffer4), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite4 = WriteProcessMemory(hProcess, lpAddress4, (LPVOID)lpPatchBuffer4, sizeof(lpPatchBuffer4), &dwWritten );
	
	VirtualProtectEx(hProcess, lpAddress5, sizeof(lpPatchBuffer5), PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	BOOL bWrite5 = WriteProcessMemory(hProcess, lpAddress5, (LPVOID)lpPatchBuffer5, sizeof(lpPatchBuffer5), &dwWritten );
	
	if (bWrite && bWrite1 && bWrite2 && bWrite3 && bWrite4 && bWrite5)
	{
		
		MessageBox(NULL,"공짜 상점 이용권 완료.", "DIABLO 1 - 3 Trainer",MB_OK | MB_ICONWARNING);
		return TRUE;
	}
	CloseHandle(hProcess);
	return 0;
	
}
