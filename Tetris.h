#include"C:/Users/janro/source/repos/Llibreria_Grafica/intro_llibreria_grafica_estudiants/0. C++ Code/Logic Game/Partida.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<forward_list>


using namespace std;

typedef struct
{
	string nom;
	int puntuacio;
} Jugador;

class Tetris
{
public:
	void afegeixPuntuacio(const string nomJugador, const int puntuacio);//feta
	void juga(Screen pantalla, const string& nomFitxerTauler, const string& nomFitxerFigures, const string& nomFitxerMoviments);//feta
	void jugaModeTests(Screen pantalla, const string& nomFitxerTauler, const string& nomFitxerFigures, const string& nomFitxerMoviments);//feta
	void mostraPuntuacions();
	void passarPuntuacioFitxer(const string& nomFitxer);

private:
	Partida m_partida;
	std::forward_list<Jugador> m_jugador;

	const string m_fitxerPuntuacions = "C:/Users/janro/source/repos/Llibreria_Grafica/intro_llibreria_grafica_estudiants/2. Platforms/0. Windows Desktop/FitxerAmbMillorsPuntuacions.txt";
	const string m_taulerBuit = "C:/Users/janro/source/repos/Llibreria_Grafica/intro_llibreria_grafica_estudiants/2. Platforms/0. Windows Desktop/TaulerBuit.txt";
	const string m_fitxerInicial = "C:/Users/janro/source/repos/Llibreria_Grafica/intro_llibreria_grafica_estudiants/2. Platforms/0. Windows Desktop/fitxerTauler.txt";
	const string m_fitxerMoviments = "C:/Users/janro/source/repos/Llibreria_Grafica/intro_llibreria_grafica_estudiants/2. Platforms/0. Windows Desktop/fitxerMoviments.txt";
	const string m_fitxerFigures = "C:/Users/janro/source/repos/Llibreria_Grafica/intro_llibreria_grafica_estudiants/2. Platforms/0. Windows Desktop/fitxerFigures.txt";
};
