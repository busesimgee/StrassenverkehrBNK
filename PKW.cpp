#include "PKW.h"
#include "Fahrzeug.h"

#include <iomanip>
#include <iostream>

using namespace std;

PKW::PKW()
	: Fahrzeug()
{
}

PKW::PKW(const PKW& rhs)
	: Fahrzeug(rhs), p_dVerbrauch(rhs.p_dVerbrauch), p_dTankvolumen(rhs.p_dTankvolumen), p_dTankinhalt(rhs.p_dTankinhalt)
{
}

PKW::PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(55), p_dTankinhalt(55.0 / 2)
{
}

PKW::PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{
}

PKW::~PKW()
{
}

void PKW::vSimulieren()
{
	// PKWs fahren nur, wenn Kraftstoff vorhanden ist
	if (p_dTankinhalt > 0)
	{
		double dGesamtStreckeTemp = p_dGesamtStrecke;

		Fahrzeug::vSimulieren(); // Fahrzeug fahren lassen

		p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeTemp) * p_dVerbrauch / 100; // Verbrauch nachrechnen

		if (p_dTankinhalt < 0) p_dTankinhalt = 0;
	}
}

void PKW::vAusgabe() const
{
	Fahrzeug::vAusgeben();
	cout << setprecision(2) << resetiosflags(ios::left) << setiosflags(ios::right)
		<< "  " << setw(12) << dVerbrauch() << " " << setw(12) << p_dTankinhalt;
}

double PKW::dTanken(double dMenge)
{
	double dMaxTankbar = p_dTankvolumen - p_dTankinhalt;

	if ((dMenge != -1.0) && (dMenge < dMaxTankbar))
	{
		// Normaler Tankvorgang
		p_dTankinhalt += dMenge;
	}
	else
	{
		// Volltanken
		dMenge = dMaxTankbar;
		p_dTankinhalt = p_dTankvolumen;
	}

	return dMenge;
}
