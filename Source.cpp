#include <Windows.h>
#include "resource.h"

BOOL CALLBACK DlgWinProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;

int WINAPI WinMain(
	HINSTANCE hInst,
	HINSTANCE prevIst,
	LPSTR cmdArgs,
	int typeShow)

{
	hInstance = hInst;

	DialogBox(hInst, MAKEINTRESOURCE(IDD_CALC), NULL, DlgWinProc);

	return 0;
}

BOOL CALLBACK DlgWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int result = 0;
	WCHAR buf[256];

	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_SUMM:
		{
			GetDlgItemText(hDlg, IDC_NUMBER_A, buf, -1);
			int a = _wtoi(buf);

			GetDlgItemText(hDlg, IDC_NUMBER_B, buf, -1);
			int b = _wtoi(buf);

			wsprintf(buf, L"%d + %d = %d", a, b, a + b);

			SetDlgItemText(hDlg, IDC_RESULT, buf);
		}
		break;
		case IDC_SUBS:
		{
			GetDlgItemText(hDlg, IDC_NUMBER_A, buf, -1);
			int a = _wtoi(buf);

			GetDlgItemText(hDlg, IDC_NUMBER_B, buf, -1);
			int b = _wtoi(buf);

			wsprintf(buf, L"%d - %d = %d", a, b, a - b);

			SetDlgItemText(hDlg, IDC_RESULT, buf);
		}
		break;
		case IDC_MULT:
		{
			GetDlgItemText(hDlg, IDC_NUMBER_A, buf, -1);
			int a = _wtoi(buf);

			GetDlgItemText(hDlg, IDC_NUMBER_B, buf, -1);
			int b = _wtoi(buf);

			wsprintf(buf, L"%d * %d = %d", a, b, a * b);

			SetDlgItemText(hDlg, IDC_RESULT, buf);
		}
		break;
		case IDC_DIV:
		{
			GetDlgItemText(hDlg, IDC_NUMBER_A, buf, -1);
			int a = _wtoi(buf);

			GetDlgItemText(hDlg, IDC_NUMBER_B, buf, -1);
			int b = _wtoi(buf);

			wsprintf(buf, L"%d / %d = %d", a, b, a / b);

			SetDlgItemText(hDlg, IDC_RESULT, buf);
		}
		break;
		case IDC_REM_DIV:
		{
			GetDlgItemText(hDlg, IDC_NUMBER_A, buf, -1);
			int a = _wtoi(buf);

			GetDlgItemText(hDlg, IDC_NUMBER_B, buf, -1);
			int b = _wtoi(buf);

			wsprintf(buf, L"%d '%' %d = %d", a, b, a % b);

			SetDlgItemText(hDlg, IDC_RESULT, buf);
		}
		break;

		case ID_EXIT:
		{
			EndDialog(hDlg, wParam);
		}
		break;

		}
		return TRUE;
	}
	return FALSE;
}
