#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



//Nume:Lepadatu Sergiu

struct Laser {

	string culoare = "N/A";

	int cantitate = 0;

	float* distanta = nullptr;

};



//citire de la tastatura



Laser citireLaser()

{

	Laser laser;



	cout << "Introduceti culoarea laserului: ";

	cin >> laser.culoare;



	cout << "Introduceti cantitatea: ";

	cin >> laser.cantitate;



	laser.distanta = new float[laser.cantitate];

	for (int i = 0; i < laser.cantitate; i++)

	{

		cout << "Introduceti distanta (in metri) maxima a laserului " << i + 1 << ":";

		cin >> laser.distanta[i];

	}






	return laser;

}



//suma distantelor



float sumaDistante(Laser laser)

{

	float sum = 0;

	for (int i = 0; i < laser.cantitate; i++)

	{

		sum += laser.distanta[i];

	}





	return sum;

}

//modificare culoare

void modificaCul(Laser& laser, string nouaCuloare)

{

	laser.culoare = nouaCuloare;

}



//afisarea

void afisareLaser(Laser laser)

{

	cout << "Culoare: " << laser.culoare << endl;

	cout << "Cantitate: " << laser.cantitate << endl;

	cout << "Distante:" << endl;

	for (int i = 0; i < laser.cantitate; i++) {

		cout << "Distanta " << i + 1 << ": " << laser.distanta[i] << "metri" << endl;

	}

}



void main()

{

	Laser laser = citireLaser();

	cout << "Suma distantelor: " << sumaDistante(laser);

	cout << endl;

	modificaCul(laser, "Violet");

	cout << "Afisare dupa modificare:" << endl;

	afisareLaser(laser);



}