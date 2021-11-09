#include "Fahrzeug.h"

Fahrzeug::Fahrzeug() : p_iID(++p_iMaxID), p_sName(""), p_dMaxGeschwindigkeit(0), p_dGesamtStrecke(0), p_dZeit(0), p_dGesamtZeit(0)
{
	cout << "Klasse: Fahrzeug Objekt : " << p_iID << " mit Name " << p_sName << " wurde erstellt " << endl;
}


Fahrzeug::Fahrzeug(string name) : p_sName(name), p_iID(++p_iMaxID), p_dMaxGeschwindigkeit(0), p_dGesamtStrecke(0), p_dZeit(0), p_dGesamtZeit(0)
{
	cout << "Klasse: Fahrzeug Objekt : " << p_iID << " mit Name " << p_sName << " wurde erstellt " << endl;
}

Fahrzeug::Fahrzeug(string name, double maxGeschwindigkeit) : p_sName(name), p_iID(++p_iMaxID),
p_dMaxGeschwindigkeit(maxGeschwindigkeit < 0 ? 0 : maxGeschwindigkeit), p_dGesamtStrecke(0), p_dZeit(0), p_dGesamtZeit(0)
{
	cout << "Klasse: Fahrzeug Objekt : " << p_iID << " mit Name " << p_sName << " wurde erstellt " << endl;
}

Fahrzeug::~Fahrzeug()
{
	cout << "Klasse: Fahrzeug Objekt : " << p_iID << " mit Name " << p_sName << " wurde gelscht " << endl;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}


void Fahrzeug::vKopf()
{
	cout << setiosflags(ios::right) << setw(5) << "ID" << setw(15) << "Name " << setw(strlen(" MaxGeschwindigkeit ")) << " MaxGeschwindigkeit "
		<< setw(strlen("Gesamtstrecke") + 5) << " Gesamtstrecke "
		<< setw(strlen(" atkuelle Geschwindigkeit [km/h] ")) << " atkuelle Geschwindigkeit [km/h] "
		<< setw(strlen(" Gesamtverbrauch [l] ")) << " Gesamtverbrauch [l] "
		<< setw(strlen(" Tankinhalt [l] ")) << " Tankinhalt [l] "
		<< endl << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

}

void Fahrzeug::vAusgeben(ostream& o) const
{
	o << setiosflags(ios::right) << setw(5) << p_iID << setw(15) << p_sName
		<< setw(strlen("MaxGeschwindigkeit") + 5) << setiosflags(ios::fixed) << setprecision(2) << p_dMaxGeschwindigkeit
		<< setiosflags(ios::fixed) << setprecision(2) << setw(strlen(" Gesamtstrecke ")) << p_dGesamtStrecke;
	// << setiosflags(ios::fixed) << setprecision(2) << setw(strlen(" atkuelle Geschwindigkeit [km/h] ")) << dGeschwindigkeit();   B�yle bir �ey bizim Aufgabelerde yok.
}

void Fahrzeug::vHeaderAusgeben()
{
	cout << "ID Name      : MaxKmh     AktKmh    GesStrecke    GesVerbrauch  Tankinhalt" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

ostream& Fahrzeug::ostreamAusgeben(ostream& out) const
{
	out << setprecision(2) << fixed // 2 feste Nachkommastellen
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(2) << p_iID << " "
		<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(10) << p_sName << ": "
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(6) << p_dMaxGeschwindigkeit << " "
		<< setw(10) << dGeschwindigkeit() << " "
		<< setw(12) << p_dGesamtStrecke;
	return out;
}

//die Fahrzeuge sich fortbewegen
void Fahrzeug::vSimulieren()
{
	//pruefe ob seit letzter Simulation Zeit vergangen ist 
	if (dGlobaleZeit > p_dZeit)
	{
		double dDeltaTime = dGlobaleZeit - p_dZeit;				//berechne Zeitdifferenz
		p_dZeit = dGlobaleZeit;									//setze letzen Simulationszeitpunkt auf aktuelle Zeit
		p_dGesamtZeit += dDeltaTime;						    //addiere Zeitdifferenz zur Fahrzeit	
		p_dGesamtStrecke += dDeltaTime * dGeschwindigkeit();;	// Addiere Streckendifferenz zur aktuellen Strecke 
	}
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}



bool Fahrzeug::operator < (const Fahrzeug& rhs) const
{
	if (this->p_dGesamtStrecke < rhs.p_dGesamtStrecke)
	{
		return true;
	}
	return false;
}


Fahrzeug& Fahrzeug::operator = (const Fahrzeug& rhs)
{
	p_sName = rhs.p_sName + " (K)";
	p_dMaxGeschwindigkeit = rhs.p_dMaxGeschwindigkeit;
	return *this;
}



ostream& operator << (ostream& out, const Fahrzeug& fzg)
{
	return fzg.ostreamAusgeben(out);
}



int Fahrzeug::p_iMaxID = 0;

ostream& operator<<(ostream& o, Fahrzeug& fahrzeug)
{
	fahrzeug.vAusgeben(o);
	return o;

}

