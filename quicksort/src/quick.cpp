#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <new>
#include <algorithm>
#include "quick.hh"

using namespace std;

//Funkcja zaraca liosc wierszy
int policz(string nazwa){

	string str;				//Zmienna pomocnicza
	int zakres = 0;			//Zmienna zliczajaca ilosc wierszy

	fstream filmy;
	filmy.open(nazwa);		//Otwarcie pliku

	while(!filmy.eof()){	//Petla dziala tak dlugo az nie natrafi na ostatni wiersz
		getline(filmy,str);	//Przypisanie wartosci wiersza do zmiennej pomocniczej
		zakres++;			//Zwiekszenie zakresu
	}
	filmy.close();			//Zamkniecie pliku
	return zakres;			//Zwraca ilosc wierszy
}






//Funkcaj usuwa wiersze z pustymi kolumnami
int usun_zbedne(Filmy *filmiki,string nazwa_pliku){



	fstream filmy;
	filmy.open(nazwa_pliku);		//Otwarcie pliku
	string wiersz;					//Zmienna pomocnicza
	int i = 0;						//Zmienna pomocnicza
	char delim = ';';				//Zmienna pomocnicza

	while(i < 960000){			//Petla dziala tak dlugo az nie natrafi na ostatni wiersz
	//while(!filmy.eof()){
		getline(filmy,wiersz, delim);		//Wczytywanie wiersza do znaku
		getline(filmy,wiersz, delim);		//Wczytywanie tego samego wiersza az do znaku
		filmiki[i].tytul = wiersz;			//Podstawia nazwe tytulu pod zmienna tytul

		getline(filmy,wiersz);				//Wczytywanie tego samego wiersza az do znaku
		filmiki[i].ocena = atof(wiersz.c_str());	//Wczytanie oceny i zmiana stringa na float
		if(filmiki[i].ocena == '\0'){				//Sprawdzenie czy nie ma pustego pola
			i--;									//Jezeli jest puste pole wczytuje kolejny wiersz nadpisujac stary
		}
		i++;										//Zwiekszenie zakresu

	}
	return i;											//Zwraca ilosc wierszy po usunieciu niektorych pozycji
}

//Sprawdza poprawnosc sortowania
void sprawdz(Filmy *filmiki, int i){

	int j = 1;											//Zmienna pomocnicza

	while(j < i){											//Petla dziala tak dlugo az dojdzie do ostatniego wiersza
	    if(filmiki[j-1].ocena > filmiki[j].ocena){			//Porowanienie poprzedniego i obecnego elementu
	    	cout << "NIE UDALO SIE POSORTOWAC!!!" << endl;	//Zwraca ostrzezenie
	    }
	    j++;												//Zwiekszenie zakresu

	 }

}

//Funkcja zapisuje posortowanie wiersze do pliku
void zapisz(Filmy *filmiki, int i){

	int j = 0;				//Zmienna pomocnicza
	string nowy_plik;		//Zmienna przechowujac anazwe nowego pliku
	ofstream wyjscie;

	cout << "Podaj nazwe pliku: ";
	cin >>  nowy_plik;				//Zapisanie nazwy nowego pliku
	wyjscie.open(nowy_plik);		//Ustawienie jako wyjscie

	while(j < i){					//Petla dziala tak dlugo az dojdzie do ostatniego wiersza
									//Wpisywanie do pliku odpowiednich wartosci
		wyjscie  << j << "," << filmiki[j].tytul << ", " << filmiki[j].ocena << ".0" << endl;
	    j++;						//Zwiekszenie zakresu
	}
	wyjscie.close();				//Zamyka plik
}


//Funkcja wykorzystuje algorytm quicksort do posortowania filmow
void quicksort(Filmy *film , int l , int r){

	 int m = film[(l+r)/2].ocena;   	//Wyznaczenie srodkowego znacznika
	 int i;                	 			//Zmienna pomocnicza
	 int j;								//Zmienna pomocnicza

	 i = l;                      		//Ustawienie odpowiednich zakresow
	 j = r;								//Ustawienie odpowiednich zakresow
	 Filmy temp;						//Zmienna pomocnicza przechowujaca wartosci tytul i ocena

	 do {								//Petla dziala tak dlugo az nie spelni sie warunek +1 raz
	     while(m > film[i].ocena) i++;	//Tak dlugo zmienia zakres az ocena na i-tym miejscu tablicy jest mniejsza od srodkowej wartosci to zwieksza sie zakres
	     while(m < film[j].ocena) j--;	//Tak dlugo zmienia zakres az ocena na j-tym miejscu tablicy jest mniejsza od srodkowej wartosci to zwieksza sie zakres
	     if (i <= j){					//Porowanienie dwoch zakresow
	        temp = film[i];				//Podstawienie wartoci pod zmienna pomocnicza
	        film[i] = film[j];			//Zamiana miejscami filmow
	        film[j] = temp;				//Podstawienie pod j-te miejsce wartosci z zmiennej pomocniczej

	        i++;						//Zwiekszenie zakresu
	        j--;						//Zmniejszenie zakresu
	     }
	 }while( i<=j );					//Petla dziala tak dlugo az i nie bedzie mniejsze rowne j

     if(j > l){							//Jezleli j jest wieksze od lewego zakresu to
         quicksort(film ,  l , j);		//Powtarza szybkie sortowanie dla zakesu od l do j
     }
     if(i < r){							//Jezleli i jest mniejsze od prawego zakresu to
         quicksort(film , i , r);		////Powtarza szybkie sortowanie dla zakesu od i do r
     }
}



