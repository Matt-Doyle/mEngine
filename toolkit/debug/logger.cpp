#include "logger.h"
#include "Windows.h"
#include "cstdio"

namespace mEngine {
	namespace toolkit {
		namespace debug {
			namespace logger {
				bool CreateConsole() {
					/* https://msdn.microsoft.com/en-us/library/windows/desktop/ms686331(v=vs.85).aspx MSDN STARTUPINFO structure  */
					/* https://msdn.microsoft.com/en-us/library/windows/desktop/ms682425(v=vs.85).aspx CreateProcess function */
					/* https://msdn.microsoft.com/en-us/library/windows/desktop/ms682528(v=vs.85).aspx Creation of a console tutorial */

					typedef struct _STARTUPINFO {
						DWORD  cb;
						LPTSTR lpReserved;
						LPTSTR lpDesktop;
						LPTSTR lpTitle;
						DWORD  dwX;
						DWORD  dwY;
						DWORD  dwXSize;
						DWORD  dwYSize;
						DWORD  dwXCountChars;
						DWORD  dwYCountChars;
						DWORD  dwFillAttribute;
						DWORD  dwFlags;
						WORD   wShowWindow;
						WORD   cbReserved2;
						LPBYTE lpReserved2;
						HANDLE hStdInput;
						HANDLE hStdOutput;
						HANDLE hStdError;
					};

					_STARTUPINFO StartUpInfo;
					SecureZeroMemory(&StartUpInfo, sizeof(_STARTUPINFO)); // Make sure all data in the structure is set to zero, we don't want someone peskilly exploiting a buffer overflow now do we?

					StartUpInfo.cb = sizeof(_STARTUPINFO);
					StartUpInfo.lpReserved = NULL; // This must be null according to MSDN
					StartUpInfo.lpDesktop = NULL; // Use the default desktop
					StartUpInfo.lpTitle = NULL; // The console can set this its self
					StartUpInfo.dwX = CW_USEDEFAULT; // X offet of new window from top most left of parent's window in pixels
					StartUpInfo.dwY = CW_USEDEFAULT; // Y offet of new window from top most left of parent's window in pixels
					StartUpInfo.dwXSize = CW_USEDEFAULT; // Width of new window in pixels
					StartUpInfo.dwYSize = CW_USEDEFAULT; // Height of new window in pixels
					StartUpInfo.dwXCountChars = 80; // Length of the console window in character rows
					StartUpInfo.dwYCountChars = 40; // Height of the console window in character columns
					StartUpInfo.dwFillAttribute = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; // The foreground and background colors that the console will initially be set to, this should be white on black
					StartUpInfo.dwFlags = NULL; // TODO: Do something with this
					StartUpInfo.wShowWindow = SW_SHOWDEFAULT; // If the window should be shown
					StartUpInfo.cbReserved2 = 0; // This must be 0
					StartUpInfo.lpReserved2 = NULL; // This must be NULL
					StartUpInfo.hStdInput = NULL; // TODO: Maybe replace these with the invalid handle macro, not too sure how that works though
					StartUpInfo.hStdOutput = NULL;
					StartUpInfo.hStdError = NULL;

					HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);

					CreateProcess(L"mEngineConsole", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, (LPSTARTUPINFO)&StartUpInfo);
				}
			}
		}
	}
}