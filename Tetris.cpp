#include "Tetris.h"

/*void Tetris::afegeixPuntuacio(const string nomJugador, const int puntuacio)
{
	std::forward_list<Jugador>::iterator anterior = m_jugador.before_begin();
	std::forward_list<Jugador>::iterator actual = m_jugador.begin();
	bool trobat = false;

	while (!trobat && actual != m_jugador.end())
	{
		if ((*actual).puntuacio < puntuacio)
			trobat = true;
		else
		{
			anterior = actual;
			actual++;
		}
	}

	Jugador jugador;

	jugador.nom = nomJugador;
	jugador.puntuacio = puntuacio;
}*/

void Tetris::jugaModeTests(Screen pantalla, const string& nomFitxerTauler, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
	m_partida.inicialitza(0, nomFitxerTauler, nomFitxerFigures, nomFitxerMoviments);
}

void Tetris::juga(Screen pantalla, const string& nomFitxerTauler, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
	//Mostrem la finestra grafica
	m_partida.inicialitza(1, nomFitxerTauler, nomFitxerFigures, nomFitxerMoviments);
	pantalla.show();

	bool partidaEnCurs = true;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();
		m_partida.actualitza(deltaTime);

	} while (!m_partida.getFinalPartida());
	
}


void Tetris::mostraPuntuacions()
{
	cout << "\n";
	for (std::forward_list<Jugador>::iterator actual = m_jugador.begin(); actual != m_jugador.end(); actual++)
		cout << (*actual).nom << " " << (*actual).puntuacio << "\n";
}


void Tetris::passarPuntuacioFitxer(const string& nomFitxerPuntuacions)
{
	ofstream fitxer;
	fitxer.open(nomFitxerPuntuacions);
	Jugador jugadorTemporal;
	if (fitxer.is_open())
	{
		while (!m_jugador.empty())
		{
			jugadorTemporal = m_jugador.front();
			m_jugador.pop_front();
			fitxer << jugadorTemporal.nom << " " << jugadorTemporal.puntuacio << "\n";
		}
	}
}
