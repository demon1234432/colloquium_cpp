#include <fstream>
#include "../struct.h"
natural DIV_NN_Nk(const natural, const natural); //user function
natural SUB_NN_N(const natural, const natural); //для user function
natural MUL_Nk_N(const natural, const unsigned short); //для user function
unsigned short COM_NN_D(const natural, const natural); //для SUB_NN_N
bool NZER_N_B(const natural); //для COM_NN_D
natural DELZ_N_N(const natural); //для NZER_N_B
natural NEWN_N_N(natural); //для DELZ_N_N
void DELN_N(natural); //для DELZ_N_N
natural ADD_1N_N(const natural); //для user function
bool test(const natural, const natural); //для проверки
#include "../Модули/DIV_NN_Nk.cpp" //user function
#include "../Модули/SUB_NN_N.cpp" //для user function
#include "../Модули/MUL_Nk_N.cpp" //для user function
#include "../Модули/COM_NN_D.cpp" //для SUB_NN_N
#include "../Модули/NZER_N_B.cpp" //для COM_NN_D
#include "../Модули/DELZ_N_N.cpp" //для NZER_N_B
#include "../Модули/NEWN_N_N.cpp" //для DELZ_N_N
#include "../Модули/DELN_N.cpp" //для DELZ_N_N
#include "../Модули/ADD_1N_N.cpp" //для user function
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	unsigned short n;
	fstream file("../Тесты/DIV_NN_Nk",ios::in);
	if (!file) return 254; //Проверка на существование тестов
	file>>n;
	for(register unsigned short i=1;i<=n;i++)
	{
		natural x,y,_x,_y,z,result; //Копируем x в _x, y в _y
		file>>x.count;
		_x.count=x.count;
		x=NEWN_N_N(x);
		_x=NEWN_N_N(_x);
		for(register unsigned short j=0;j<x.count;j++)
		{
			file>>x.digits[j];
			_x.digits[j]=x.digits[j];
		};
		file>>y.count;
		_y.count=y.count;
		y=NEWN_N_N(y);
		_y=NEWN_N_N(_y);
		for(register unsigned short j=0;j<y.count;j++)
		{
			file>>y.digits[j];
			_y.digits[j]=y.digits[j];
		};
		file>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		z=DIV_NN_Nk(x,y);//user function
		if (!test(x,_x) || !test(y,_y)) return 255; //Проверка на сохранность данных
		if (!test(z/*user function*/,result)) return i;
		DELN_N(x);
		DELN_N(_x);
		DELN_N(y);
		DELN_N(_y);
		DELN_N(z);
		DELN_N(result);
	};
	return 0;
};
