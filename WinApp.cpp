#include<windows.h>
#include "resource.h"
//	Puntero = Handler

//CallBack
INT_PTR CALLBACK cVentana1(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmdLine, int cShow) {

	//Crea una variable MSG y asigna a tods los espacios sin usar cero, o un valor default
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	//Crea un handle y lo aputa a la ventana de dialogo 
	HWND hVentana1 = CreateDialog(hInst, MAKEINTRESOURCE(DLG_ventanaUno), NULL, cVentana1);

	//muestra la ventana de dialgo con un formato definido por el sistema operativo
	ShowWindow(hVentana1, cShow);

	//Lee todos los mesajes sin restricciones, los traduce a un lenguaje que el codigo comprende y se lo envia a la ventana
	while (GetMessage(&msg, NULL, 0, 0)) {
		if (!IsDialogMessage(hVentana1, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
};
INT_PTR CALLBACK cVentana1(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_COMMAND: {
		if (LOWORD(wParam) == BTN_enviar && HIWORD(wParam) == BN_CLICKED) {//verifica si el boton es clickeado
			//Tenemos que leer el mensaje en la ventana "TXT_nombre"
			//LPWSTR nombre;
			HWND hNombre = GetDlgItem(hWnd, TXT_nombre); //puntero a textBox
			int lNombre = GetWindowTextLength(hNombre);
			//GetWindowText(hNombre, nombre, lNombre+1);

			//Trabajando un poco con lo logrado
			if (lNombre < 1) {
				MessageBox(NULL, L"Mensaje demasiado corto",L"ERROR", MB_OK);
			}
			else {
				MessageBox(NULL, L"Deleting <system32>", L"FATAL ERROR", MB_ICONWARNING);
			};		
		};
	}break;

	case WM_CLOSE: {
		DestroyWindow(hWnd);
	};
	case WM_DESTROY: {
		PostQuitMessage(17);
	}break;
	};
	return (INT_PTR)false;
};