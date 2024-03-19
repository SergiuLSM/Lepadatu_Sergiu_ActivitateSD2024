#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct Santier Santier;
typedef struct Nod Nod;

//lista se parcurge element cu element

struct Santier {
	char* numeProiect;
	int nrMuncitori;
	float suprafata;


};

struct Nod {
	Santier santier;
	Nod* next;


};

Santier initializareSantier(const char* numeProiect, int nrMuncitori, float suprafata)
{
	Santier santier;
	santier.numeProiect = (char*)malloc(strlen(numeProiect) + 1);
	strcpy(santier.numeProiect, numeProiect);
	santier.nrMuncitori = nrMuncitori;
	santier.suprafata = suprafata;

	return santier;
}

Nod* inserareInceput(Santier santier, Nod* lista)
{
	Nod* nod=(Nod*)malloc(sizeof(Nod));
	nod->santier = santier;
	nod->next = lista;
	return nod;



}

int sumaMuncitori(Nod* lista)
{
	int suma = 0;
	while (lista !=NULL )
	{
		suma = suma + lista->santier.nrMuncitori;
		lista = lista->next;
	}
	return suma;
}

char* densitateSantier(Nod* lista)
{
	float densitate = 0;
	Nod* retinut=NULL;
	while (lista != NULL)
	{
		if (lista->santier.suprafata / lista->santier.nrMuncitori > densitate)
		{
			densitate = lista->santier.suprafata / lista->santier.nrMuncitori;
			retinut = lista;
		}
		lista = lista->next;
	}
	if (retinut != NULL)
		return retinut->santier.numeProiect;
	else return "\nLista este goala";

}

void afisareSantier(Santier santier)
{
	printf("Santierul %s are %d muncitori si o suprafata de %5.2f\n",santier.numeProiect,santier.nrMuncitori,santier.suprafata);

}

void afisareLista(Nod* lista)
{
	while (lista != NULL)
	{
		//procesare
		afisareSantier(lista->santier);
		lista = lista->next;
	}

}

void stergereLista(Nod** lista)
{
	while ((*lista) != NULL)
	{
		free((*lista)->santier.numeProiect);
		Nod* aux;
		aux = ((*lista)->next);
		free(*lista);
		(*lista) = aux;
	}
	(*lista) = NULL;
}

int main() {
	Nod* lista = NULL;
	Santier s1 = initializareSantier("Proiect 1", 4, 300);
	Santier s2 = initializareSantier("Proiect 2", 10, 3000);
	Santier s3 = initializareSantier("Proiect 3", 7, 4000);

	lista =inserareInceput(s1, lista);
	lista=inserareInceput(s2, lista);
	lista= inserareInceput(s3, lista);
	printf("\n");
	afisareSantier(s1);
	afisareSantier(s2);
	afisareSantier(s3);

	printf("\nIn lista:\n");

	afisareLista(lista);

	int suma = sumaMuncitori(lista);
	printf("Suma muncitori: %d\n", suma);

	printf("Densitatea maxima: %s", densitateSantier(lista));
	stergereLista(&lista);
	afisareLista(lista);


}