// DZ_Ur1_mod7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <cmath>

#define sz 10

using namespace std;
int isPrime(int* N);
int LinPoisk (int key, int dlina, int* Ms_ps);
int BinPoisk(int* key, int* perv, int* posl);

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "\tUrok_1__mod_7__HomeTask. Nomer zadania ot 1 do 8 bez 7(быки и коровы)" << endl;
	cout << endl;

	srand(time(NULL));
	int number = 1;

	do
	{
		switch (number)
		{
		case 1: {
			cout << "case 1: Obiavit ukazatel na int" << endl;
			int a;
			int *p = &a; // peremennaia p xranit address peremennoi a, t.e. peremennaia p ukazivaet na peremennuiu a
			cout << "int *p= &a; // peremennaia p xranit address peremennoi a " << endl;
			cout << " t.e. p ukazivaet na peremennuiu a" << endl;
			cout << "----------------------------------" << endl;
			//----------------------------------------------------------------------------
			cout << endl;
			cout << "       case 2: Naznachit znachenie peremennoi po ukazateliu" << endl;
			char *p2;
			char a2 = 'D';
			cout << " a2= " << a2 << ";" << endl;
			p2 = &a2;
			*p2 = 'W'; // v peremennuiu a popalo znachenie po ukazateliu *p2
			cout << " p2=&a2; " << endl;
			cout << " *p2='W'; // v peremennuiu a2 popalo znachenie po ukazateliu *p2" << endl;
			cout << " a2= " << a2 << ";" << endl;
			cout << "----------------------------------------------------------------" << endl;
			//----------------------------------------------------------------------------------
			cout << endl;
			cout << "       case 3: Obiavit ukazatel na textovuiu stroku " << endl;
			
			char god[] = "Hello";
			char *p3 = &god[0]; // text -> massiv simvolov -> ukazatel na 0-i element
			for (int i = 0; i<sizeof(god); i++)
			{
				cout << " " << *p3;
				p3++;
			}
			cout << endl;
			cout << "char *p3=god; // text -> massiv simvolov -> ukazatel na 0-i element" << endl;
			cout << endl;
			break;
		}
		case 4: {
			cout << "     4. Function Proverka Prostoe li chislo  " << endl;
			int cnt = 0;
			int Prime_arr[sz] = { 17, 35, 46, 19, 37, 25, 113, 117, 6, 169 };
			cout << " massiv dlia poiska prostix chisel: " << endl;
			for (int i = 0; i<sz; i++)
			{
				cout << " " << setw(3) << Prime_arr[i];
				if ((i + 1) % 5 == 0) cout << endl;
			}
			cout << " prostie chisla iz massiva: " << endl;
			for (int i = 0; i<sz; i++)
			{
				int* N = &Prime_arr[i];
				if (isPrime(N) == 1)
					cnt++;
			}
			cout << "Kolichestvo prostix chisel iz massiva 10 chisel: " << cnt << endl;
			cout << endl;
			break;
		}
		case 5: {
			cout << "     5. Function Lineinogo poiska  " << endl;
			int Ms1[sz] = { 17, 35, 46, 19, 37, 25, 113, 117, 6, 169 };
			int key = 113;
			int isk_ind=0;
			cout << "massiv dlia lin-poiska " << endl;
			for (int i = 0; i<sz; i++)
				cout << setw(5) << Ms1[i];
			cout << endl;
			cout << " naiti v massive key=  " << key << endl;
			// vizov f-cii
			isk_ind = LinPoisk(key, sz, Ms1);
			if (isk_ind != -1)
				cout << "key naiden, index= " << isk_ind << endl;
			else
				cout << "key NE naiden" << endl;
			
			cout << endl;
			break;
		}
		case 6: {
			cout << "     6. Function Binarnogo poiska  " << endl;
			int k=0, key=0;
			// massiv
			int Ms2[sz] = { -81, -74, -66, -63, -2, 5, 16, 47, 81, 115 };
			cout << "massiv dlia bin-poiska " << endl;
			for (int i = 0; i<sz; i++)
				cout << setw(5) << Ms2[i];
			cout << endl;
			
			// posl el-t massiva
			int* pMs2 = &Ms2[sz - 1]; 
			
			// kluch
			k = rand() % 11;
			key = Ms2[k];
			int* pkey = &key;
			cout << " naiti v massive key= " << key << endl;

			// vizov f-cii
			cout << "BinPoisk: " << BinPoisk(pkey, Ms2, pMs2) << endl;
			cout << endl;
			break;
		}
		case 8: {
			cout << "     8. Resultat segmenta prorammi " << endl;
			int count = 10, *temp, sum = 0;
			temp = &count;    // peremennaia temp soderzhit address peremennoi count
			*temp = 20;       // v peremennuiu count popalo zhachenie 20 po ukazateliu temp, count=20
			temp = &sum;       // peremennaia temp soderzhit address peremennoi sum
			*temp = count;   //  v peremennuiu sum popalo zhachenie peremennoi count po ukazateliu temp, sum=20
			printf("count=%d, *temp=%d, sum=%d\n", count, *temp, sum);
			cout << endl;
			cout << "temp = &count;   // peremennaia temp soderzhit address peremennoi count " << endl;
			cout << "*temp = 20;      // v peremennuiu count popalo zhachenie 20 po ukazateliu temp, count=20 " << endl;
			cout << "temp = &sum;     // peremennaia temp soderzhit address peremennoi sum " << endl;
			cout << "*temp = count;   // v peremennuiu sum popalo zhachenie peremennoi count po ukazateliu temp, sum=20 " << endl;
			break;
		}
		default: break;
		}
		cout << endl;
		cout << "Proverka zadanii ot 1 do 8, vixod - 0. Vvod nomera: " << endl;
		cin >> number;
	} while (number>0);
	cout << "End of Zadania 1-8 " << endl;
	system("pause");
	return(0);
}
// ---- 1 ---------------------------------------------------
int isPrime(int *N)
{
	if (*N == 2 || *N == 3 || *N == 5 || *N == 7 || *N == 11 || *N == 13 || *N == 17 || *N == 19 || *N == 23 || *N == 29||*N==113)
	{
		cout << "\t" << setw(3) << *N << endl;
		return 1;
	}
	if (*N % 2 == 0 || *N % 3 == 0 || *N % 5 == 0 || *N % 7 == 0 || *N % 11 == 0 || *N % 13 == 0 || *N % 17 == 0 || *N % 19 == 0 || *N % 23 == 0 || *N % 29 == 0||*N%113==0)
		return 0;
	else
		{
		cout << "\t" << setw(3) << *N << endl;
			return 1;
		}
}
//---- 2 -------------------------------------------------------
int LinPoisk(int key, int dlina, int* Ms_ps)
{
for(int i=0;i<dlina;i++)
{
	if (*(Ms_ps + i) == key)
		return i;
}
return -1;
}
//---- 3 -------------------------------------------------------
int BinPoisk(int* key, int* perv, int* posl)
{
	int* seredina = NULL;
	int i = 0;
	int kol_vo = posl - perv+1;
	 cout << " kol_vo= " << kol_vo << endl;
	seredina = perv + kol_vo/2;
	cout << "1-ia seredina " << *seredina << endl;
	while (perv <= posl)
	{
		i++;
		seredina = perv + kol_vo/2;
		 cout << *seredina << " =novaia seredina v cycle " << i << endl;
		*key <= *seredina ? posl = seredina : perv = seredina;
		kol_vo = posl - perv+1;
		 printf("\n%d, =novoe kol-vo v cycle", kol_vo);
		if (*seredina == *key) 
		{
			 cout << "\n kluch naiden, cycle i= " << i << " iskomoe znachenie= " << *seredina <<endl;
			return *key; 
		}
		else
		{
			cout << "\n kluch ne naiden" << endl; return - 1;
		}
	}
}
//---------------------------------------------------------------------------

