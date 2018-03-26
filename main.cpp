#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>


using namespace std;

//ZMIENNE
int  punkt_glob,tlos[6];
string kate,jeszcze;

//FUNKCJE
int losowanie();
//*************************************************************
void zerowanie();
//***********************************************************
bool czylosowana(int a, int tab[5],int ile);
//***********************************************************
int main()
{

    while(1)
    {
        zerowanie();

        do
        {
            system("CLS");
            cout<<"============================"<<endl;
            cout << "     Witaj w quizie !" << endl;
            cout<<"============================"<<endl;
            cout<<"    Wybierz katogorie:"<<endl;
            cout<<"============================"<<endl;
            cout<<"        1. Biblia"<<endl;
            cout<<"       2. Alkohole"<<endl;
            cout<<"============================"<<endl;
            cout<<"Wprowadz numer kategorii: ";
            cin>>kate;
        }while(kate[0] != '1' && kate[0]!='2');

        int kat;
        kat=atoi(kate.c_str());

        if(kat==1)
        {

            cout<<endl<<"Wybrana kategoria: Biblia";
            Sleep(1000);
            cout<<endl<<endl<<"Losuje pytanie...";
            Sleep(2000);
            system("CLS");
            fstream plik;
            string linia;
            string A[20],B[20],C[20],D[20],Pyt[20],Pop[20];
            int nr_linii=1,numer=0;
    //Otwieranie pliku z pytaniami Biblia
            plik.open("Biblia.txt",ios::in);
            if(plik.good()==false)
            {
                cout<<"Nie udalo sie otworzyc pliku";
                exit (0);
            }

            while(getline(plik,linia))
            {
                switch(nr_linii)
                {
                    case 1:Pyt[numer]=linia;     break;
                    case 2:A[numer]=linia;       break;
                    case 3:B[numer]=linia;       break;
                    case 4:C[numer]=linia;       break;
                    case 5:D[numer]=linia;       break;
                    case 6:Pop[numer]=linia;     break;
                }
                if(nr_linii==6)
                {
                    nr_linii=0;
                    numer++;
                }
                nr_linii++;
            }

            plik.close();
    //Zamkniecie pliku
            int liczba,tt=5;
            int punkty=0;
            for(int i=0;i<5;i++)
            {
                liczba=losowanie();
                while(czylosowana(liczba,tlos,tt)==true)
                {
                    liczba=losowanie();
                }
                tlos[i]=liczba;
                string odp;
            do
            {
                system("CLS");
                cout<<endl<<"Kategoria: Biblia";
                cout<<"         Punkty: "<<punkty<<endl<<endl;
                cout<<"Pytanie "<<i+1<<endl<<endl;
                cout<<" "<<Pyt[liczba]<<endl;
                cout<<"  a) "<<A[liczba]<<endl;
                cout<<"  b) "<<B[liczba]<<endl;
                cout<<"  c) "<<C[liczba]<<endl;
                cout<<"  d) "<<D[liczba]<<endl;
                cout<<endl<<"Podaj odpowiedz wpisujac a,b,c lub d"<<endl;
                cout<<"ODPOWIEDZ: ";
                cout<<" ";
                getline(cin,odp);
                transform(odp.begin(),odp.end(),odp.begin(),::tolower);
                }while((odp[0]!='a'&& odp[0]!='b'&& odp[0]!='c'&&odp[0] != 'd')||(odp.length()>=2));
                cout<<endl;

                if(odp==Pop[liczba])
                {
                    cout<<"Brawo! Odpowiedz prawidlowa !"<<endl;
                    cout<<"Zdobywasz punkt!"<<endl;
                    punkty=punkty+1;
                }
                else
                {
                    cout<<"Niestety zle, prawidlowa odpowiedz to: "<<Pop[liczba]<<endl;
                    cout<<"Otrzymujesz 0 punktow!"<<endl;
                }

                Sleep(2000);
                system("CLS");
            }
            punkt_glob=punkty;
        }

        else
        {
            cout<<endl<<"Wybrana kategoria: Alkohole";
            Sleep(1000);
            cout<<endl<<endl<<"Losuje pytanie...";
            Sleep(2000);
            system("CLS");
            fstream plik;
            string linia;
            string A[20],B[20],C[20],D[20],Pyt[20],Pop[20];
            int nr_linii=1,numer=0;

            plik.open("Alkohole.txt",ios::in);
            if(plik.good()==false)
            {
                cout<<"Nie udalo sie otworzyc pliku";
                exit (0);
            }

            while(getline(plik,linia))
            {
                switch(nr_linii)
                {
                    case 1:Pyt[numer]=linia;     break;
                    case 2:A[numer]=linia;       break;
                    case 3:B[numer]=linia;       break;
                    case 4:C[numer]=linia;       break;
                    case 5:D[numer]=linia;       break;
                    case 6:Pop[numer]=linia;     break;
                }
                if(nr_linii==6)
                {
                    nr_linii=0;
                    numer++;
                }
                nr_linii++;
            }

            plik.close();

            int liczba,tt=5;
            int punkty=0;
            for(int i=0;i<5;i++)
            {
                liczba=losowanie();
                while(czylosowana(liczba,tlos,tt)==true)
                {
                    liczba=losowanie();
                }
                tlos[i]=liczba;

                string odp;
                do
                {
                    system("CLS");
                    cout<<endl<<"Kategoria: Alkohole";
                    cout<<"         Punkty: "<<punkty<<endl<<endl;
                    cout<<"Pytanie "<<i+1<<endl<<endl;
                    cout<<" "<<Pyt[liczba]<<endl;
                    cout<<"  a) "<<A[liczba]<<endl;
                    cout<<"  b) "<<B[liczba]<<endl;
                    cout<<"  c) "<<C[liczba]<<endl;
                    cout<<"  d) "<<D[liczba]<<endl;
                    cout<<endl<<"Podaj odpowiedz wpisujac a,b,c lub d"<<endl;
                    cout<<"ODPOWIEDZ: ";
                    cout<<" ";
                    getline(cin,odp);
                    transform(odp.begin(),odp.end(),odp.begin(),::tolower);
                }while((odp[0]!='a'&& odp[0]!='b'&& odp[0]!='c'&&odp[0] != 'd')||(odp.length()>=2));

                cout<<endl;
                if(odp==Pop[liczba])
                {
                    cout<<"Brawo! Odpowiedz prawidlowa !"<<endl;
                    cout<<"Zdobywasz punkt!"<<endl;
                    punkty=punkty+1;
                }
                else
                {
                    cout<<"Niestety zle, prawidlowa odpowiedz to: "<<Pop[liczba]<<endl;
                    cout<<"Otrzymujesz 0 punktow!"<<endl;
                }

                Sleep(2000);
                system("CLS");
            }
            punkt_glob=punkty;


        }

        cout<<endl<<" Koniec quizu! Twoj wynik to: "<<punkt_glob<<endl;
        fstream zapis;
        string *nick=new string,G[100],czytana;
        int nr=0;
        cout<<endl<<" Podaj swoje imie: ";
        getline(cin,*nick);
        cout<<endl;
        cout<<" Czekaj...";
        Sleep(1500);
        zapis.open("Ranking.txt",ios::out | ios::app);
        zapis<<*nick<<"      ";
        zapis<<punkt_glob<<endl;
        zapis.close();

        zapis.open("Ranking.txt",ios::in);
        while(getline(zapis,czytana))
        {
            G[nr]=czytana;
            nr++;
        }
        zapis.close();
        do{
                system("CLS");
            int lp=1;
            cout<<endl<<" 10 ostatnich rozgrywek:"<<endl<<endl;
            for(int i=9;i>=0;i--)
            {
                cout<<"  "<<lp<<". "<<G[i]<<endl;
                lp++;
            }
            zapis.open("Ranking.txt",ios::out);
            for(int i=1;i<=9;i++)
                {
                    zapis<<G[i]<<endl;
                }
            zapis.close();
            cout<<endl<<endl<<" Jezeli chcesz sprowac jeszcze raz, wcisnij 1"<<endl<<" ";
            cin>>jeszcze;
        }while(jeszcze[0]!='1'||jeszcze.length()>=2);

        system("CLS");

        }
        return 0;

}

bool czylosowana(int a, int tab[5],int ile)
{
    if(ile<=0)
        return false;
    int i=0;
    do
    {
        if(tab[i]==a)
            return true;
        i++;
    }while (i<ile);

    return false;
}

int losowanie()
{
    int liczba;
    srand(time(NULL));
    liczba=rand()%15;
    return liczba;
}
void zerowanie()
{

        for(int i=0;i<6;i++)
        {
            tlos[i]=-1;
        }
}
