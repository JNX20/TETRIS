#include "Joc.h"
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <iostream>

using namespace std;

/*void printFigura(Joc& prova1)
{
	cout << "\n" << "\n" << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << prova1.getFigura(i, j) << " ";
		}
		cout << "\n";
	}
	cout << "\n" << "\n" << "\n";
}*/

void printTauler(Joc& prova1)
{
	cout << "\n" << "\n" << "\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << prova1.getTauler(i, j) << " ";
		}
		cout << "\n";
	}
	cout << "\n" << "\n" << "\n";
}

int main()
{
	Joc prova1;

	prova1.inicialitza("lectura.txt");
	prova1.print();
	printTauler(prova1);
	prova1.baixaFigura();
	prova1.print();
	
	

	//prova1.giraFigura(GIR_HORARI);
	//prova1.print();

	//printFigura(prova1);
	//printFigura(prova1);
	//prova1.escriuTauler("Resultat.txt");
	
	//cout << "Fila: " << prova1.getFila() << "  Columna: " << prova1.getColumna() << "\n" << "\n" << "\n";
}
