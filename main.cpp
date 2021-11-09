#include"Fahrzeug.h"
#include"PKW.h"
#include"Fahrrad.h"
#include<iostream>
#include<iomanip>

#include <map>
#include<memory>
#include<vector>
#include<cmath>

using namespace std;

// Vergleichsfunktion fuer zwei double-Werte mit Fehlertoleranz.
inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}
void vAufgabe_1()
{
	//Fahrzeug Fahrrad("fahrrad_1)
	//Fahrzeug Auto("auto_1)

	int* p = new int[20];
	delete[] p;

	//Erzeugen Smartpointers

	unique_ptr<Fahrzeug>p_fahrrad1 = make_unique<Fahrzeug>("fahrrad_1");
	shared_ptr<Fahrzeug>p_auto1 = make_shared<Fahrzeug>("auto_1");
	cout << p_auto1.use_count() << endl;
	shared_ptr<Fahrzeug>p_auto2 = p_auto1;
	cout << p_auto1.use_count() << endl;


	vector<unique_ptr<Fahrzeug>>vehicles;
	vehicles.push_back(move(p_fahrrad1));

	vector<shared_ptr<Fahrzeug>>vehiches_shared;
	vehiches_shared.push_back(p_auto1);

	vehicles.clear();
	vehiches_shared.clear();


}
void vAufgabe_1a()
{
	double dDeltaSimulationsZeit = 0.1;

	vector<unique_ptr<Fahrzeug>> pvFahrzeuge;

	//Einlesen von drei Fahrzeugen 
	for (int i = 0; i < 3; i++)
	{
		//Variablen 
		string sName;
		string sMaxGeschwindigkeit;
		double dMaxGeschwindigkeit;

		//Einlesen des Namen & Max. Geschwindigkeit
		cout << "Name fuer Fahrzeug eingeben \n";
		cin >> sName;
		cout << " Maximale Geschwindigkeit eingeben \n";
		cin >> sMaxGeschwindigkeit;

		//Konvertieren des Geschw. String in double
		dMaxGeschwindigkeit = stod(sMaxGeschwindigkeit);

		//Fahrzeug erstellen & dem Vektor anh�ngen 
		pvFahrzeuge.push_back(make_unique<Fahrzeug>(sName, dMaxGeschwindigkeit));
	}

	for (int i = 0; i < 10; i++)
	{
		//Ausgabe der Globalen Zeit
		cout << "Globale Zeit : " << dGlobaleZeit << endl;

		//Simulieren & Ausgeben f�r alle Fahrzeuge des Vektors;
		for (auto& it : pvFahrzeuge)
		{
			it->vSimulieren();
			it->vAusgeben();
			cout << endl;
		}

		dGlobaleZeit += dDeltaSimulationsZeit;
	}


}

void vAufgabe_2()
{
	int iNumPKW = 0;
	int iNumFahrrad = 0;

	cout << "Wie viele PKWs sollen erzeugt werden? ";
	cin >> iNumPKW;
	cout << "Wie viele Fahrraeder sollen erzeugt werden? ";
	cin >> iNumFahrrad;

	vector < unique_ptr < Fahrzeug>> vecFahrzeuge;

	// PKWs erzeugen
	for (int i = 1; i <= iNumPKW; i++)
	{
		PKW* pkwTemp = new PKW("AUTO " + to_string(i), 60, 5);
		vecFahrzeuge.push_back(pkwTemp);
	}

	// Fahrraeder erzeugen
	for (int i = 1; i <= iNumFahrrad; i++)
	{
		Fahrrad* frdTemp = new Fahrrad("FAHRRAD " + to_string(i), 24);
		vecFahrzeuge.push_back(frdTemp);
	}

	double dInterval = 0.0;
	cout << "Bitte geben Sie das Abfertigungsinterval ein: ";
	cin >> dInterval;
	cout << endl;

	bool bGetankt = false;
	Fahrzeug::vHeaderAusgeben();
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dInterval)
	{
		// vector<Fahrzeug*>::iterator it;
		for (auto it = vecFahrzeuge.begin(); it != vecFahrzeuge.end(); it++)
		{
			if ((bEqual(dGlobaleZeit, 3.0) || dGlobaleZeit > 3.0) && !bGetankt)
			{
				(*it)->dTanken();	// Zum Zeitpunkt 3:00 Autos nachtanken
				bGetankt = true;
			}

			(*it)->vSimulieren();	// Fahrzeuge fahren lassen
			(*it)->vAusgeben();		// Fahrzeugdaten ausgeben
			cout << endl;
		}

		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}

	// vector<Fahrzeug*>::iterator it;
	for (auto it = vecFahrzeuge.begin(); it != vecFahrzeuge.end(); it++)
	{
		delete* it; // Dynamische Objekte loeschen
	}
}
void vAufgabe_3()
{
	PKW car("Golf", 60, 5);
	Fahrrad bike("Cube", 24);

	// Ein wenig fahren
	dGlobaleZeit += 2.5;
	car.vSimulieren();
	bike.vSimulieren();

	// Alles ausgeben
	Fahrzeug::vHeaderAusgeben();
	cout << car << endl << bike << endl;

	// Vergleichsoperator testen
	if (bike < car)
	{
		cout << "Das Auto ist bereits weiter gefahren." << endl << endl;
	}
	else
	{
		cout << "Das Fahrrad ist bereits weiter gefahren." << endl << endl;
	}

	// Kopiermechanismen testen
	PKW carcopy1;
	PKW carcopy2 = car;	// mit Kopierkonstruktor
	carcopy1 = car;		// mit Zuweisungsoperator

	Fahrzeug::vHeaderAusgeben();
	cout << carcopy1 << endl << carcopy2 << endl;
}



