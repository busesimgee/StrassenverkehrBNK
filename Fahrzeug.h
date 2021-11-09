#pragma once
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

extern double dGlobaleZeit;
extern bool bEqual(double x, double y);


class Fahrzeug
{
public:

	//Konstruktoren& Destruktoren
	Fahrzeug();
	Fahrzeug(string p_sName);
	Fahrzeug(string sName, double dMaxgeschwindigkeit);
	void vKopf();
	double p_dGesamtStrecke;
	double p_dMaxGeschwindigkeit;

	virtual double dGeschwindigkeit() const;
	virtual void vAusgeben(std::ostream& o) const;
	static void vHeaderAusgeben();
	virtual ostream& ostreamAusgeben(ostream& out) const;
	bool operator< (const Fahrzeug& rhs) const;
	Fahrzeug& operator = (const Fahrzeug& rhs);
	void    vSimulieren();
	virtual double dTanken(double dMenge = -1.0);
	virtual ~Fahrzeug();

private:
	//Klassen Variablen
	static int p_iMaxID;
	double p_dZeit;
	string p_sName = "";
	const string p_iID;
};

ostream& operator << (ostream& out, const Fahrzeug& fzg);