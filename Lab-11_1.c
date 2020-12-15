   /*/----------------------!!!----------------------------/*/
  /*/ Before compilation Save with Encoding Windows 1251  /*/
 /*/              Saved in Encoding UTF-8                /*/
/*/-------------------------!!!-------------------------/*/
#include <stdio.h>
#include <stdlib.h>
#include "default_cfg.h"
                                 /////////////////////////////////////////////////////////////
#define _yellow SetColor(14,0); // жовний вивід тексту на екран + чорний фон               //
#define _red SetColor(12,0);   // червоний вивід тексту на екран + чорний фон             //
#define _green SetColor(10,0);// повернення зеленого виводу тексту на екран + чорний фон //
                             /////////////////////////////////////////////////////////////
#define N 15
#define _files "Lab-11_1.dat"

void create_file(); // створює файл та заповняє його числами

int main()
{
	start_cfg(); // default_cfg.h
	FILE *f; // вказівник на файл
	int k = 0; // Кількість непарних чисел в файлі
	int buff[N];// буфер для тимчасових даних
	char x; // збереження відповіді
do{
	f = fopen (_files, "rb"); // Відкриття файла
	if(f == NULL)
	{
		printf("\nФАЙЛ НЕ ІСНУЄ, СТВОРИТИ? \n[y/n]: ");
	do{
		_red
		scanf("%c", &x);
		_green
		if (x == 'y' || x == 'Y')
		{
			create_file(); // створює файл та заповняє його числами
			break;
		} else if (x == 'n' || x == 'N')
		{
			Error_RED();
			printf("Без файла %s робота програми не можлива\n", _files);
			end_cfg(); // default_cfg.h
			return 1;
		} else printf("\nДайте відповідь [y/n]: ");
	}while(x != 'y' && x != 'Y' && x != 'n' && x != 'N'); // цикл працює доки не дано нормальної відповіді
	}
}while(f == NULL);
	fread(buff, sizeof(int), N, f); // копіювання вмісту файла у масив
	printf("\nВміст файла: ");
	for (int i = 0; i < N; i++)
	{
		if (buff[i]%2 != 0) // якщо число не парне виводить його жовтим кольором
		{
			_yellow
			printf("%d ", buff[i]);
			_green
		}else printf("%d ", buff[i]);
		
	}printf("\n");

	for (int i = 0; i < N; i++) // Кількість непарних чисел в файлі
	{
		if (buff[i]%2 != 0)
		{
			k++;
		}
	}
	if (k>0)
	{
		printf("\nКількість непарних чисел в файлі: ");
		_yellow
		printf("%d", k);
		_green
		printf("\nНепарні числа в ньому: ");
		for (int i = 0; i < N; i++)
		{
			if (buff[i]%2 != 0)
			{
				_yellow
				printf("%d ", buff[i]);	
				_green
			}
		}
	}
	else{
		Error_RED();
		_red
		printf("У файлі немає непарних чисел\n");
		_green
		}
	
	fclose(f); // закриття файла
	end_cfg(); // default_cfg.h
	return 0;
}

void create_file(){
	int buff[N];
	for (int i = 0; i < N; i++)
	{
		buff[i] = i+1;
	}
	
	FILE *f; // вказівник на файл
	f = fopen(_files, "wb"); // Створення бінарного файла
	if(f == 0)
	{ printf ("Не можу відкрити файл для запису");
	end_cfg();// default_cfg.h
	exit(1); // Завершення роботи програми з кодом 1
	}

	fwrite(buff, sizeof(int), N, f);
	fclose(f); //закриття файла
}