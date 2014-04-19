// MagicSqure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

static const int MIN = 3;
static const int MAX = 1000;

static int magic_arr[MAX][MAX] = {0};

void InitMagicArray(){
	memset(magic_arr, 0, sizeof(magic_arr) / sizeof(int));
}

void OddMagic(const int n){
	int line, row, num;
	num = 0;
	line = 0;
	row = n/2;
	magic_arr[line][row] = 1;
	for(int i = 2; i <= n * n; i++){
		line = (line - 1 + n) % n;
		row = (row + 1) % n;
		if(magic_arr[line][row] != 0){
			line = (line + 2) % n;
			row = (row - 1 + n) % n;
		}
		magic_arr[line][row] = i;
	}
}

void DoubleEvenMagic(int n){

}

void SigleEvenMagic(int n){

}

void GenerateMagicSqure(int n){
	InitMagicArray();
	if(n % 2 == 1)
		OddMagic(n);
	else if(n % 4 == 0)
		DoubleEvenMagic(n);
	else
		SigleEvenMagic(n);
}

void ShowMagicSqure(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			_tprintf(_T("%3d\t"), magic_arr[i][j]);
		}
		_tprintf(_T("\n"));
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
START:
	int n = 0;
	_tprintf (_T("Input a integer to generate magic cube, OR intput 0 to quit program.\n"));
	_tscanf_s(_T("%d"), &n);
	if(n == 0)
		return 0;
	else if(n < MIN || n > MAX){
		_tprintf(_T("Error. Input an integer lager than %d and smaller than %d.\n"),
			MIN, MAX);
		goto START;
	}
	GenerateMagicSqure(n);
	ShowMagicSqure(n);
	goto START;

	return 0;
}

