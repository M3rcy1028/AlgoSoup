#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

// �ܼ� �ؽ�Ʈ ���� �������ִ� �Լ�
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

int main()
{
	PlaySound(TEXT("Allyouneedislove.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	
	SetConsoleTitle(TEXT("I LOVE U"));
	int n = 12;
	string str;
	for (int i = n / 2; i < n; i += 2)
	{
		//��
		for (int j = 1; j < n - i; j += 2)  str.append(" ");
		for (int j = 1; j < i + 1; j++) str.append("��");
		for (int j = 1; j < n - i + 1; j++) str.append(" ");
		for (int j = 1; j < i + 1; j++) str.append("��");
		str.append("\n");
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < n - i; j++) str.append(" ");
		for (int j = 1; j < i * 2; j++) str.append("��");;
		str.append("\n");
	}
	setColor(RED);		//text : RED
	cout << str;
	setColor(BLACK);	//text : WHITE
	_getch(); //�̰� ������ ��� �� ��, ���� �� �ڵ� ����
	return 0;
}