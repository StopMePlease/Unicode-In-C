#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>

#include <Windows.h>

int _tmain()
{

	/*_setmode(_fileno(stdout), _O_U16TEXT);
	_tprintf(_T("A\u262F") _T("C\n"));*/

	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	//wchar_t s[] = L"\u017A";
	wchar_t s[100];
	wscanf(L"%s", s);
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, s, -1, NULL, 0, NULL, NULL);
	char* m = new char[bufferSize]; 
	WideCharToMultiByte(CP_UTF8, 0, s, -1, m, bufferSize, NULL, NULL);
	wprintf(L"%S", m);
	delete[] m;

	SetConsoleOutputCP(oldcp);
	return 0;
}