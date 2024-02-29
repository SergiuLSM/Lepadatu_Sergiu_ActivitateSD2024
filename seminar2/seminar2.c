#include <stdio.h>
#include <malloc.h>
struct Farmacie {
	int id;
	char* nume;
	float suprafata;
};

struct Farmacie initializareFarmacie(int id, const char* nume, float suprafata)
{
	struct Farmacie f;
	f.id = id;
	f.nume = (char*)malloc(sizeof(char*) * strlen(nume) + 1);
	strcpy(f.nume, nume);
	f.suprafata = suprafata;
	return f;

}

void afisareFarmacie(struct Farmacie farmacie)
{
	printf("%d. %s are o suprafata de %5.2f\n", farmacie.id, farmacie.nume, farmacie.suprafata);
}

void afisareVector(struct Farmacie* farmacii, int nrFarmacii) {
	for (int i = 0; i < nrFarmacii; i++)
	{
		afisareFarmacie(farmacii[i]);
	}
}

struct Farmacie* copiazaNElemente(struct Farmacie* vector, int nrFarmacii, int nrObiecteCopiate) {
	if (nrObiecteCopiate <= nrFarmacii && nrObiecteCopiate > 0)
	{
		struct Farmacie* copiat = (struct Farmacie*)malloc(sizeof(struct Farmacie) * nrObiecteCopiate);
		for (int i = 0; i < nrObiecteCopiate; i++)
		{
			copiat[i] = initializareFarmacie(vector[i].id, vector[i].nume, vector[i].suprafata);
		}
		return copiat;
	}
	else
	{
		return NULL;
	}
}

//functie care copiaza daca au suprafata mai mica

struct Farmacie* copiazaFarmaciiMici(struct Farmacie* farmacii, int nrFarmacii, float pragSuprafata, int* nrFarmaciiMici)
{
	*nrFarmaciiMici = 0;
	for (int i = 0; i < nrFarmacii; i++)
	{
		if (farmacii[i].suprafata < pragSuprafata)
		{
			(*nrFarmaciiMici)++;
		}
	}
	struct Farmacie* vector = (struct Farmacie*)malloc(sizeof(struct Farmacie) * (*nrFarmaciiMici));
	int k = 0;
	for (int i = 0; i < nrFarmacii; i++)
	{
		if (farmacii[i].suprafata <pragSuprafata)
		vector[k++]=initializareFarmacie(farmacii[i].id,farmacii[i].nume,farmacii[i].suprafata);
	}

	return vector;

}

void dezalocareVecotrFarmacii(struct Farmacie** vector,int *nrFarmacii)
{
	for (int i = 0; i < *nrFarmacii; i++)
	{
		free((*vector)[i].nume);
	}
	free(*vector);
	*nrFarmacii = 0;
	*vector = NULL;

}

struct Farmacie getFarmacieByID(struct Farmacie* vector, int nrFarmacii, int idCautat)
{
	for (int i = 0; i < nrFarmacii; i++)
	{
		if (vector[i].id == idCautat)
		{
			return initializareFarmacie(vector[i].id, vector[i].nume, vector[i].suprafata);


		}
	}

	return initializareFarmacie(0, "N/A", 0);
}

int main()
{
	//int v[40];
	//int* v2=;
	int nrFarmacii = 4;
	struct Farmacie* farmacii = (struct farmacie*)malloc(sizeof(struct Farmacie) * nrFarmacii);

	for (int i = 0; i < nrFarmacii; i++) {
		farmacii[i] = initializareFarmacie(i + 1, "Farmacie", 30 * i + 10);
	}
	afisareVector(farmacii, nrFarmacii);

	int nrFarmaciiCopiate = 2;
	struct Farmacie* FarmaciiCopiate = copiazaNElemente(farmacii, nrFarmacii, nrFarmaciiCopiate);
	afisareVector(FarmaciiCopiate, nrFarmaciiCopiate);
	int nrFarmaciiMici = 0;
	farmacii[3].suprafata = 20;

	struct Farmacie* farmaciiMici = copiazaFarmaciiMici(farmacii, nrFarmacii, 30, &nrFarmaciiMici);
	printf("\n\n");
	afisareVector(farmaciiMici, nrFarmaciiMici);

	struct Farmacie fcautat = getFarmacieByID(farmacii, nrFarmacii, 7);
	printf("Farmacie cautata:\n");
	afisareFarmacie(fcautat);
	free (fcautat.nume);

	dezalocareVecotrFarmacii(&farmacii, &nrFarmacii);
	dezalocareVecotrFarmacii(&FarmaciiCopiate, &nrFarmaciiCopiate);
	dezalocareVecotrFarmacii(&farmaciiMici, &nrFarmaciiMici);

}