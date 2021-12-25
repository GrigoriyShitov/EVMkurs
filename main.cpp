#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <chrono>
#include <string>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

void drawline(int x1, int x2, int y1, int y2)
{
	HWND sHwnd = GetForegroundWindow();
	HDC hdc = GetDC(sHwnd);
	HPEN hPen1;
	HPEN hPen2;
	hPen1 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, hPen1);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	ReleaseDC(sHwnd, hdc);
}
void drawlinedigits(int x1, int x2, int y1, int y2)
{
	HWND sHwnd = GetForegroundWindow();
	HDC hdc = GetDC(sHwnd);
	HPEN hPen1;
	hPen1 = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	SelectObject(hdc, hPen1);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	ReleaseDC(sHwnd, hdc);
}
void drawlineCBE(int x1, int x2, int y1, int y2)
{
	HWND sHwnd = GetForegroundWindow();
	HDC hdc = GetDC(sHwnd);
	HPEN hPen1;
	hPen1 = CreatePen(PS_SOLID, 1, RGB(255, 0, 255));
	SelectObject(hdc, hPen1);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	ReleaseDC(sHwnd, hdc);
}
void clk() {
	int x1, x2, y1, y2;
	x1 = 60, x2 = 80, y1 = 40, y2 = 40;
	drawline(x1, x2, y1, y2);
	for (int i = 0; i < 64; i++)
	{
		x1 = x2, x2 += 10, y1 = y2, y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2, x2 += 10, y1 = y2;
		drawline(x1, x2, y1, y2);
		x1 = x2, x2 += 10, y1 = y2, y2 += 20;
		drawline(x1, x2, y1, y2);
		x1 = x2, x2 += 10, y1 = y2;
		drawline(x1, x2, y1, y2);
	}
}
void lines(int x1, int y1, int digit) {
	int x2, y2;
	x2 = x1, y2 = y1 - 40;
	switch (digit)
	{
	case 1:
		drawlinedigits(x1, x2, y1, y2);
		break;
	case 2:
		drawlinedigits(x1, x2, y1, y2);
		x1 += 10, x2 = x1;
		drawlinedigits(x1, x2, y1, y2);
		break;
	case 3:
		drawlinedigits(x1, x2, y1, y2);
		x1 += 10, x2 = x1;
		drawlinedigits(x1, x2, y1, y2);
		x1 += 10, x2 = x1;
		drawlinedigits(x1, x2, y1, y2);
		break;
	case 4:
		drawlinedigits(x1, x2, y1, y2);
		x1 += 10;
		drawlinedigits(x2, x1, y2, y1);
		x2 += 20;
		drawlinedigits(x1, x2, y1, y2);
		break;
	case 5:
		x1 += 10;
		drawlinedigits(x2, x1, y2, y1);
		x2 += 20;
		drawlinedigits(x1, x2, y1, y2);
		break;
	case 6:
		x1 += 10;
		drawlinedigits(x2, x1, y2, y1);
		x2 += 20;
		drawlinedigits(x1, x2, y1, y2);
		x1 = x2;
		drawlinedigits(x2, x1, y2, y1);
		break;
	}
}
int romb(int x2, int y2, int k)
{
	int x1 = x2;
	int y1 = y2;
	y2 += 20, x2 += 10;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2;
	if (k == 2)
		x2 += 60;
	else
		x2 += 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y2 -= 20, x2 += 10;
	drawline(x1, x2, y1, y2);
	x1 = x2;
	int x3 = x2;
	y1 = y2, x2 -= 10, y2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2;
	if (k == 2)
		x2 -= 60;
	else
		x2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2, x2 -= 10, y2 += 20;
	drawline(x1, x2, y1, y2);
	return x3;
}
void endline(int x1)
{
	int x2 = x1 + 2000;
	int y1, y2;
	y1 = 110, y2 = 110;
	drawline(x1, x2, y1, y2);
	y1 = 160, y2 = 160;
	drawline(x1, x2, y1, y2);
	y1 = 210, y2 = 210;
	drawline(x1, x2, y1, y2);
	y1 = 260, y2 = 260;
	drawline(x1, x2, y1, y2);
	y1 = 310, y2 = 310;
	drawline(x1, x2, y1, y2);
	y1 = 110, y2 = 110;
}
void frame(int x2) {
	int x3, x4, y3, y4;
	x3 = 60, x4 = 100, y3 = 60, y4 = 60;
	drawline(x3, x4, y3, y4);
	x3 = x4, y4 += 20, x4 += 10;
	drawline(x3, x4, y3, y4);
	y3 = y4, x3 = x4, x4 = x2, x4 -= 10;
	drawline(x3, x4, y3, y4);
	x3 = x4, y4 -= 20, x4 += 10;
	drawline(x3, x4, y3, y4);
	y3 = y4, x3 = x4, x4 += 2000;
	drawline(x3, x4, y3, y4);
}
void binword(int xnach, int xend)
{
	int x1, x2;
	x1 = xnach, x2 = x1;
	int y1, y2;
	int xdif = xend - x2;
	y1 = 160, y2 = y1, x2 += 10, y2 += 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2, x2 = xend, x2 -= 10;
	drawline(x1, x2, y1, y2);
	x1 = x2, x2 += 10, y2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2, x2 -= 10, y2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2, x2 -= xdif, x2 += 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, x2 -= 10, y2 += 20;
	drawline(x1, x2, y1, y2);
}
void ugolok(int x1, int x2, int y1, int y2, int xnach)
{
	drawline(x1, x2, y1, y2);
	x1 = x2, y2 -= 20, x2 += 10;
	binword(xnach, x2);
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2, y2 -= 20, x2 -= 10;
	drawline(x1, x2, y1, y2);
}
int TRDY(int op, int bin, int xend, int time, int xbuff)
{
	int ybuff, x1, x2, y1, y2;
	ybuff = 260, y1 = ybuff, y2 = y1;
	x1 = xend, x2 = x1;
	x2 -= 10, y2 += 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2, x2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, x2 -= 10, y2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2;
	drawline(x1, xbuff, y1, ybuff);
	xbuff = xend;
	return xbuff;
}
int adress(int k, int time, int bit, int op) {
	int x1, x2, y1, y2;
	x1 = 60;
	x2 = 110;
	y1 = 110;
	y2 = 110;
	drawline(x1, x2, y1, y2);
	//drowing A
	drawlinedigits(x2 + 10, x2 + 15, 130, 90);//1.25
	drawlinedigits(x2 + 15, x2 + 20, 90, 130);
	drawlinedigits(x2 + 12.5, x2 + 17.5, 110, 110);
	//drowing D
	drawlinedigits(x2 + 20, x2 + 20, 90, 130);
	drawlinedigits(x2 + 20, x2 + 30, 130, 110);
	drawlinedigits(x2 + 30, x2 + 20, 110, 90);
	//
	int a = 0;
	if (op == 1 || op == 3)
	{
		a = romb(x2, y2, k) + 40;
		drawline((a - 40), a, y1, y2);
	}
	else
		a = romb(x2, y2, k);
	return a;
}
int data(int x3, int time, int bit, int op, int k)
{
	int i = 0;
	int digit = 1;
	int x1, x2, y1, y2, xbuff, ybuff = 0;
	x2 = x3, y2 = 110, y1 = y2, x1 = x2;
	int xnach, xend;
	xnach = 0, xend = 0;
	switch (time)
	{
	case 1:// 30ns
		xnach = x1;
		xbuff = 60;
		for (i = 0; i < 6; i++)
		{
			y2 += 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)
			{
				x2 += 20;
				if (i == 0 && (op == 1 || op == 3))
					ugolok(x1, x2, y1, y2, xnach = adress(k, time, bit, op) - 40);
				else
					ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10; x2 += 50;
				binword(xnach, x2);
				x2 -= 10;
			}
			else
			{
				x2 += 30;
				if (i == 0 && (op == 1 || op == 3))
					binword((adress(k, time, bit, op) - 40), x2);
				else
					binword(xnach, x2);
				xnach = x2;
				x2 -= 10;
			}

			drawline(x1, x2, y1, y2);
			x1 = x2;
			y2 -= 20;
			x2 += 10;
			xnach = x2;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (i == 4)
				frame(x2);
		}
		xend = x2;
		x2 += 300;
		drawline(x1, x2, y1, y2);
		y1 = 260, y2 = 260;
		drawline(x1, x2, y1, y2);
		y1 = 100, y2 = 110;
		x2 = x1;
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 60;
			else
				x2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);

		}
		break;
	case 2://70 ns
		xnach = x1;
		xbuff = 60;
		for (i = 0; i < 6; i++)
		{
			y2 += 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)
			{
				x2 += 100;//220
				if (i == 0 && (op == 1 || op == 3))
					ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
				else
					ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 130;
				binword(xnach, x2);
				xnach = x2;
				x2 -= 10;
			}
			else
			{
				x2 += 110;
				if (i == 0 && (op == 1 || op == 3))
					binword((adress(k, time, bit, op) - 40), x2);
				else
					binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y2 -= 20;
			x2 += 10;
			xnach = x2;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (i == 4)
				frame(x2);
		}
		xend = x2;
		x2 = x1;
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 220;
			else
				x2 -= 100;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);
		}
		break;
	case 3://100 ns
		xnach = x1;
		xbuff = 60;
		for (i = 0; i < 6; i++)
		{
			y2 += 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)
			{
				x2 += 140;//310
				if (i == 0 && (op == 1 || op == 3))
					ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
				else
					ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 180;
				binword(xnach, x2);
				xnach = x2;
				x2 -= 10;
			}
			else
			{
				x2 += 150;
				if (i == 0 && (op == 1 || op == 3))
					binword((adress(k, time, bit, op) - 40), x2);
				else
					binword(xnach, x2);
				xnach = x2; x2 -= 10;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2, y2 -= 20, x2 += 10;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (i == 4)
				frame(x2);
		}
		xend = x2;
		x2 = x1;
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 310;
			else
				x2 -= 140;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);

		}
		break;
	case 4://200 ns
		xnach = x1;
		xbuff = 60;
		for (i = 0; i < 6; i++)
		{
			y2 += 20;
			x2 += 10;
			lines(x2, y2, digit);
			digit++;
			drawline(x1, x2, y1, y2);
			y1 = y2;
			x1 = x2;
			if (bit == 1)
			{
				x2 += 260;//540
				if (i == 0 && (op == 1 || op == 3))
					ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
				else
					ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 290;
				binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			else//260
			{
				x2 += 270;
				if (i == 0 && (op == 1 || op == 3))
					binword((adress(k, time, bit, op) - 40), x2);
				else
					binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y2 -= 20;
			x2 += 10;
			xnach = x2;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (i == 4)
				frame(x2);
		}
		xend = x2;
		x2 = x1;
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 540;
			else
				x2 -= 260;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);

		}
		break;
	case 5://3-1-1-1-3-1 25 ns
	case 6://3-1-1-1-3-1 20 ns
		xnach = x1;
		xbuff = 60;
		//3 takta 1 time
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		digit++;
		y1 = y2;
		x1 = x2;
		if (bit == 1)
		{
			x2 += 100;
			if (op == 1 || op == 3)
				ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
			else
				ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 120;
		}
		else
		{
			x2 += 100;
		}
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xnach = x2;
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		//1 takt 3 times
		for (i = 0; i < 3; i++)
		{
			y2 += 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)//60
			{
				x2 += 20;
				ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 50;
				binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			else//20
			{
				x2 += 30;
				binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y2 -= 20;
			x2 += 10;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
		}
		//3 takts 1 time
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		digit++;
		y1 = y2;
		x1 = x2;
		if (bit == 1)
		{
			x2 += 100;
			ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 120;
		}
		else
			x2 += 100;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xnach = x2;
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		frame(x2);
		//1takt 1 time
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		y1 = y2;
		x1 = x2;
		if (bit == 1)//60
		{
			x2 += 20;
			ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 40;
		}
		else//20
			x2 += 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		xend = x2;
		x2 = x1;
		//обратно последнее слово
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 60;
		else
			x2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		//обратно слово 3 такта
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 220;
		else
			x2 -= 100;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		// обратно 3 слова 1 такт
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 60;
			else
				x2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);
		}
		x1 = x2;
		y1 = y2;
		//обратно слово 3 такта
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 220;
		else
			x2 -= 100;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		break;
	case 7://4-1-4-1-4-1 20 ns
		xnach = x1;
		xbuff = 60;
		for (i = 0; i < 3; i++)
		{
			//4 takta
			y2 += 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)//310
			{
				x2 += 140;
				if (i == 0 && (op == 1 || op == 3))
					ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
				else
					ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 170;
			}
			else
			{
				x2 += 140;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y2 -= 20;
			x2 += 10;
			binword(xnach, x2);
			xnach = x2;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			//одик такт
			xnach = x1;
			y2 += 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)//60
			{
				x2 += 20;
				ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 40;
			}
			else
				x2 += 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y2 -= 20;
			x2 += 10;
			binword(xnach, x2);
			xnach = x2;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
		}
		xend = x2;
		x2 = x1;
		for (i; i > 0; i--)
		{
			//1 takt
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 60;
			else
				x2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);
			if (i == 3)
				frame(x2);
			//4 takta
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 -= 20;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 310;
			else
				x2 -= 140;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);
		}
		break;
	case 8://5-2-2-2-5-2 20 ns
		//5 taktov
		xnach = x1;
		xbuff = 60;
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		digit++;
		y1 = y2;
		x1 = x2;
		if (bit == 1)//300
		{
			x2 += 180;
			if (op == 1 || op == 3)
				ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
			else
				ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 120;
		}
		else
		{
			x2 += 180;
		}
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xnach = x2;
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		//2 takta 3 times
		for (i = 0; i < 3; i++)
		{
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)
			{
				x2 += 60;
				ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 90;
				binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			else
			{
				x2 += 70;
				binword(xnach, x2);
				xnach = x2, x2 -= 10;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2, y1 = y2, y2 -= 20, x2 += 10;
			drawline(x1, x2, y1, y2);
			x1 = x2, y1 = y2, y2 += 20, x2 += 10;
			lines(x2, y2, digit);
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
		}
		lines(x2, y2, digit);
		digit++;
		//5 taktov 1 times
		xnach = x1;
		y1 = y2;
		x1 = x2;
		if (bit == 1)//300
		{
			x2 += 180;
			ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 120;
		}
		else
			x2 += 180;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xnach = x2;
		frame(x2);
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		//2 takta 1 times
		y1 = y2;
		x1 = x2;
		if (bit == 1)//140
		{
			x2 += 60;
			ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 80;
		}
		else
			x2 += 60;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		xend = x2;
		//obratno 2 takta 1 times
		x2 = x1;
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 140;
		else
			x2 -= 60;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		//obranto 5 taktov 1 times
		x1 = x2;
		y1 = y2;
		y2 -= 20;
		x2 -= 10;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 300;
		else
			x2 -= 180;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		//obratno 2 takta 3 times
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			y2 -= 20;
			x2 -= 10;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 140;
			else
				x2 -= 60;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);
		}
		//obratno 5 taktov 1 times
		x1 = x2;
		y1 = y2;
		y2 -= 20;
		x2 -= 10;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 300;
		else
			x2 -= 180;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		break;
	case 9:
		//3 takta 1 time
		xnach = x1;
		xbuff = 60;
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		digit++;
		y1 = y2;
		x1 = x2;
		if (bit == 1)
		{
			x2 += 100;
			if (op == 1 || op == 3)
				ugolok(x1, x2, y1, y2, adress(k, time, bit, op) - 40);
			else
				ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 120;
		}
		else
		{
			x2 += 100;
			if (op == 1 || op == 3)
				binword((adress(k, time, bit, op) - 40), x2);
		}
		drawline(x1, x2, y1, y2);
		x1 = x2, y1 = y2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xnach = x2;
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		//2 takta 3 times
		for (i = 0; i < 3; i++)
		{
			digit++;
			y1 = y2;
			x1 = x2;
			if (bit == 1)
			{
				x2 += 60;
				ugolok(x1, x2, y1, y2, xnach);
				xnach = x2 + 10, x2 += 90;
				binword(xnach, x2);
				xnach = x2;
				x2 -= 10;
			}
			else
			{
				x2 += 70;
				binword(xnach, x2);
				xnach = x2;
				x2 -= 10;
			}
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			y2 -= 20;
			x2 += 10;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			y2 += 20;
			x2 += 10;
			xbuff = TRDY(op, bit, x2, time, xbuff);
			drawline(x1, x2, y1, y2);
			lines(x2, y2, digit);
		}
		//3 takta 1 times
		xnach = x1;
		x1 = x2;
		y1 = y2;
		lines(x2, y2, digit);
		digit++;
		if (bit == 1)
		{
			x2 += 100,
				ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 120;
		}
		else
			x2 += 100;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y2 -= 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		xbuff = TRDY(op, bit, x2, time, xbuff);
		binword(xnach, x2);
		frame(x2);
		x1 = x2;
		xnach = x1;
		y1 = y2;
		//2 takta 1 time
		y2 += 20;
		x2 += 10;
		drawline(x1, x2, y1, y2);
		lines(x2, y2, digit);
		digit++;
		y1 = y2;
		x1 = x2;
		if (bit == 1)
		{
			x2 += 60;
			ugolok(x1, x2, y1, y2, xnach);
			xnach = x2 + 10, x2 += 80;
		}
		else
			x2 += 60;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		y2 -= 20;
		x2 += 10;
		binword(xnach, x2);
		xbuff = TRDY(op, bit, x2, time, xbuff);
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		xend = x2;
		//obratno 2 takta 1 time
		x2 = x1;
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 140;
		else
			x2 -= 60;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		//obratno 3takta 1 time
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 220;
		else
			x2 -= 100;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);
		//obratno 2 takta 3 times
		for (i; i > 0; i--)
		{
			x1 = x2;
			y1 = y2;
			y2 -= 20;
			x2 -= 10;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			if (bit == 1)
				x2 -= 140;
			else
				x2 -= 60;
			drawline(x1, x2, y1, y2);
			x1 = x2;
			y1 = y2;
			x2 -= 10;
			y2 += 20;
			drawline(x1, x2, y1, y2);
		}
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 -= 20;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		if (bit == 1)
			x2 -= 220;
		else
			x2 -= 100;
		drawline(x1, x2, y1, y2);
		x1 = x2;
		y1 = y2;
		x2 -= 10;
		y2 += 20;
		drawline(x1, x2, y1, y2);

		break;
	}
	return (xend);
}

int codeop(int xnach, int op, int k)
{
	//написание кода операции
	int x1, x2;
	int y1, y2;
	y1 = 160, y2 = y1;
	if (op == 1 || op == 3)
	{
		x2 = xnach - 40;
		if (k == 2)
		{
			x2 -= 30;
			if (op == 1)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 23, 160, 160);
			}
			else if (op == 2)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 13, 180, 140);
			}
			else if (op == 3)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 13, 180, 140);
			}
			else if (op == 4)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 13, 180, 140);
			}
			x2 -= 10;
			romb(x2, y2, 1);
			x2 -= 30;
			if (op == 1)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 23, 160, 160);
			}
			else if (op == 2)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 18, x2 + 18, 180, 140);
			}
			else if (op == 3)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 21, x2 + 30, 160, 160);
			}
			else if (op == 4)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 20, x2 + 20, 180, 140);
			}
			x2 -= 10;
			romb(x2, y2, 1);
		}
		else
			x2 -= 40;
	}
	else
		if (k == 2)
		{
			x2 = xnach - 30;
			if (op == 1)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 23, 160, 160);
			}
			else if (op == 2)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 18, x2 + 18, 180, 140);
			}
			else if (op == 3)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 21, x2 + 30, 160, 160);
			}
			else if (op == 4)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 20, x2 + 20, 180, 140);
			}
			x2 -= 10;
			romb(x2, y2, 1);
			x2 -= 30;
			if (op == 1)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 23, 160, 160);
			}
			else if (op == 2)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 18, x2 + 18, 180, 140);
			}
			else if (op == 3)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 21, x2 + 30, 160, 160);
			}
			else if (op == 4)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 20, x2 + 20, 180, 140);
			}
			x2 -= 10;
			romb(x2, y2, 1);
		}
		else
		{
			x2 = xnach - 30;
			if (op == 1)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 13, x2 + 23, 160, 160);
			}
			else if (op == 2)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 6, x2 + 6, 180, 140);
				drawlineCBE(x2 + 12, x2 + 12, 180, 140);
				drawlineCBE(x2 + 18, x2 + 18, 180, 140);
			}
			else if (op == 3)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 21, x2 + 30, 160, 160);
			}
			else if (op == 4)
			{
				drawlineCBE(x2 - 5, x2 + 5, 160, 160);
				drawlineCBE(x2 + 7, x2 + 17, 160, 160);
				drawlineCBE(x2 + 19, x2 + 19, 140, 180);
				drawlineCBE(x2 + 20, x2 + 20, 180, 140);
			}
			x2 -= 10;
		}
	x1 = 60;
	int X = 0;
	int Y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor = { 0,0 };
	cor.X = X;
	cor.Y = Y;
	SetConsoleCursorPosition(hConsole, cor);
	switch (op)
	{
	case 1:
		cout << "0110";
		break;
	case 2:
		cout << "0111";
		break;
	case 3:
		cout << "0010";
		break;
	case 4:
		cout << "0011";
		break;
	}
	drawline(x1, x2, y1, y2);
	romb(x2, y2, 1);
	romb(x2, y2, 1);
	return romb(x2, y2, 1);
}
void IRDY(int xnach, int xend, int k)
{
	int x1, x2, y1, y2;
	x1 = 60;
	if (k == 1)
		x2 = xnach - 10;
	else
		x2 = xnach - 50;
	y1 = 210, y2 = y1;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2;
	x2 += 10, y2 += 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2;
	x2 = xend - 10;
	drawline(x1, x2, y1, y2);
	x1 = x2;
	x2 += 10, y2 -= 20;
	drawline(x1, x2, y1, y2);
	x1 = x2, y1 = y2;
	x2 += 300;
	drawline(x1, x2, y1, y2);
}
void devsel(int xnach, int xend, int op)
{
	int x1 = 60; int y1 = 310; int y2 = 330; int x2 = xend;
	if (op == 1 || op == 3)
	{
		drawline(x1, xnach - 50, y1, y1);
		x1 = xnach - 50;
		drawline(x1, xnach - 40, y1, y2);
		x1 = xnach - 40;
	}
	else
	{
		drawline(x1, xnach - 10, y1, y1);
		x1 = xnach - 10;
		drawline(x1, xnach, y1, y2);
		x1 = xnach;
	}
	drawline(x1, x2 - 10, y2, y2);
	drawline(x2 - 10, x2, y2, y1);
	drawline(x2, x2 + 300, y1, y1);
}

void pcisim(int speed, int bitting, int type, int amount) {
	auto t1 = chrono::high_resolution_clock::now();
	int cnt, x, var, i, sum;
	i = 0, sum = 0;
	bool clk, adr, irdy, trdy, devs, com;
	adr = false, irdy = false, trdy = false;
	cout << "Характеристики шины: Частота шины ";
	switch (type)
	{
	case 1:
		var = sizeof(char);
		break;
	case 2:
		var = sizeof(short);
		break;
	case 3:
		var = sizeof(int);
		break;
	case 4:
		var = sizeof(long long);
		break;
	}
	switch (speed)
	{
	case 1:
		cnt = 26;
		cout << "33MHZ; Раpрядность 32-bit" << endl;
		break;
	case 2:
		cnt = 10;
		cout << "33/66 MHZ; Раpрядность32/64-bit" << endl;
		break;
	case 3:
		cnt = 6;
		cout << "64MHZ; Раpрядность 64-bit" << endl;
		break;
	}
	int datas = amount / cnt;
	while (cnt > 0)
	{
		if (i % 2 == 0)
			clk = true;
		else
			clk = false;
		if (clk == true && adr == false)
		{
			adr = true;
			i++;
		}
		else
			irdy = true, trdy = true, devs = true, com = true;
		if (irdy == true && trdy == true && devs == true && com == true && clk == true)
		{
			x = var * datas;
			sum += x;
			i++;
			cnt--;
		}
		else
		{
			cnt--;
			i++;
		}
	}
	auto t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout.precision(2);
	cout << "Шина обработала " << x << " байт за " << duration << " микросекунд." << endl;
}
void task1(int amnt) {
	pcisim(1, 1, 1, amnt);
	pcisim(1, 1, 2, amnt);
	pcisim(1, 1, 3, amnt);
	pcisim(1, 1, 4, amnt);
	cout << "\n\n";
	cout << "__________________________________________________\n" << endl;
	pcisim(2, 2, 1, amnt);
	pcisim(2, 2, 2, amnt);
	pcisim(2, 2, 3, amnt);
	pcisim(2, 2, 4, amnt);

	cout << "\n\n";
	cout << "__________________________________________________\n" << endl;
	pcisim(3, 3, 1, amnt);
	pcisim(3, 3, 2, amnt);
	pcisim(3, 3, 3, amnt);
	pcisim(3, 3, 4, amnt);
}
void task2()
{
	int choose = 0;
	int c[10];
	int min = INT_MAX;
	int max = -INT_MAX;
	int i, j, tmp, cnt = 0;
	cout << "Введите исходный массив чисел\n";
	for (i = 0; i < 10; i++)
		cin >> c[i];
	auto t1 = chrono::high_resolution_clock::now();
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (c[j] > c[j + 1])
			{
				tmp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = tmp;
			}
		}
	}
	cout << "\nИтоговый массив имеет вид:\n";
	for (i = 0; i < 10; i++)
	{
		cout << c[i] << " ";
	}
	cout << "\nКоличество обработанных данных\n" << sizeof c[10] << " байт\n";
	auto t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout.precision(2);
	cout << "Данная операция заняла " << duration << " микросекунд" << endl;
	_getch();
}
void task3(int k, int time, int bit, int op) {/*{adress();data();}*/
	int xnach = adress(k, time, bit, op);
	int xend = data(xnach, time, bit, op, k);
	codeop(xnach, op, k);
	IRDY(xnach, xend, k);
	devsel(xnach, xend, op);
	endline(xend);
	_getch();
}
void menufor3task(int choose)
{
	switch (choose)
	{
	case 1:
		cout << "Выберите операцию на шине:\n____________________________\n1-Чтение из памяти\n2-Запись в память\n3-Чтение с УВВ\n4-Запись в УВВ\n";
		break;
	case 2:
		cout << "Выберите разрядность адреса:\n____________________________\n1-32 бита\n2-64 бита\n";
		break;
	case 3:
		cout << "Выберите разрядность, передаваемого по шине слова:\n__________________________________________\n1-64 бита\n2-32 бита\n3-16 бит\n4-8 бит\n";
		break;
	case 4:
		cout << "Выберите Время доступа к информации:\n_________________________________\n1. 30 нс\n2. 70 нс\n3. 100 нс\n4. 200 нс\n5. 5-3-1-1-1 25нс\n6. 3-1-1-1 25нс\n7. 4-1-4-1 20 нс\n8. 5-2-2-2 20нс\n9. 3-2-2-2 15нс\n";
		break;
	}
}
int main()
{
	int k, time, bit, op;
	setlocale(LC_ALL, "Russian");
	int choose;
	do {
		system("cls");
		cout << "Введите номер задания" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			system("cls");
			int amnt;
			cout << "Введите количество данных";
			cin >> amnt;
			system("cls");
			task1(amnt);
			_getch();
			break;
		case 2:
			system("cls");
			task2();
			break;
		case 3:
			system("cls");
			menufor3task(1);
			cin >> op;
			system("cls");
			menufor3task(2);
			cin >> k;
			system("cls");
			menufor3task(3);
			cin >> bit;
			system("cls");
			menufor3task(4);
			cin >> time;
			system("cls");
			cout << "\n" << "CLK";
			cout << "\n\n" << "frame";
			cout << "\n\n" << "AD";
			cout << "\n\n\n" << "C/BE#";
			cout << "\n\n" << "IRDY#";
			cout << "\n\n\n" << "TRDY#";
			cout << "\n\n" << "Devsel";
			clk();
			int x1 = 63, y1 = 0;
			drawline(x1, x1, y1, y1 + 600);
			task3(k, time, bit, op);
			_getch();
			system("cls");
			break;
		}
	} while (choose != 0);
	system("cls");
	return 0;
}
