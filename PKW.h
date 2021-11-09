#pragma once
#include "Fahrzeug.h"
#include <iomanip>
#include <iostream>


class PKW : public Fahrzeug
{
public:
	// Erstellt ein neuen PKW mit eindeutiger ID.
	PKW();

	// Kopierkonstruktor. Erstellt ein neuen PKW nach Vorlage der rhs.
	PKW(const PKW& rhs);

	// Erstellt ein neuen PKW mit eindeutiger ID, maximaler Geschwindigkeit und Verbrauch.
	PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch);

	// Erstellt ein neuen PKW mit eindeutiger ID, maximaler Geschwindigkeit, Verbrauch und Tankvolumen.
	PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen);

	// Standard-Destruktor.
	virtual ~PKW();

	// Diese Funktion gibt alle wichtigen Daten des PKW auf cout aus. 
	virtual void vAusgabe() const;

	// Diese Funktion gibt alle wichtigen Daten des PKW auf einem Stream aus.
	virtual ostream& ostreamAusgabe(ostream& out) const;

	// Diese Funktion l�sst den PKW fahren, sofern gen�gend Kraftstoff vorhanden ist.
	virtual void vSimulieren();

	// Ermittelt den bisherigen Gesamtverbrauch an Kraftstoff.
	double dVerbrauch() const;

	// Diese Funktion betankt ein PKW mit der gew�nschten Menge und gibt die tats�chlich getankte Menge zur�ck.
	// Ohne Parameterangabe (default -1.0) wird vollgetankt.
	virtual double dTanken(double dMenge = -1.0);

	// Diese Operator�berladung erm�glicht das direkte Zuweisen eines PKW (assign).
	PKW& operator = (const PKW& rhs);

private:

	// Kraftstoffverbrauch (Liter/100km)
	double p_dVerbrauch;

	// Gesamtvolumenen des Tanks
	double p_dTankvolumen;

	// Aktueller Inhalt des Tanks (Liter)
	double p_dTankinhalt;
};

