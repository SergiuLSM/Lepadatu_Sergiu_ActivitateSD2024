#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct Santier Santier;
//lista se parcurge element cu element

struct Santier {
	char* numeProiect;
	int nrMuncitori;
	float suprafata;
};
typedef struct NodLdi NodLdi;

struct NodLdi
{
	NodLdi* prev;
	NodLdi* next;
	Santier info;
};

typedef struct ListaDubla ListaDubla;

struct ListaDubla {
	NodLdi* prim;
	NodLdi* ultim;
};


void inserareInceput(ListaDubla* lista, Santier s)
{
	NodLdi* aux = malloc(sizeof(NodLdi));
	aux->info = s;
	aux->next = lista->prim;
	aux->prev = NULL;
	if (lista->prim != NULL)
	{
		lista->prim->prev = aux;
	}
	else {
		lista->ultim = aux;
	}
	lista->prim = aux;


}

Santier initializareSantier(const char* numeProiect, int nrMuncitori, float suprafata)
{
	Santier santier;
	santier.numeProiect = (char*)malloc(strlen(numeProiect) + 1);
	strcpy(santier.numeProiect, numeProiect);
	santier.nrMuncitori = nrMuncitori;
	santier.suprafata = suprafata;

	return santier;
}





void afisareSantier(Santier santier)
{
	printf("Santierul %s are %d muncitori si o suprafata de %5.2f\n", santier.numeProiect, santier.nrMuncitori, santier.suprafata);

}

void afisareLdiDeLaInceput(ListaDubla lista)
{
	for (NodLdi* nod = lista.prim; nod != NULL; nod = nod->next)
	{
		afisareSantier(nod->info);
	}
	printf("\n\n\n");
}

void stergereSanterDupaNume(ListaDubla* lista, const char* numeSantier)
{
	NodLdi* nod = lista->prim;

	while (nod != NULL)
	{
		if (strcmp(nod->info.numeProiect, numeSantier) == 0)
		{
			if (nod->prev == NULL)
			{
				if (nod->next = NULL)
				{
					lista->prim = NULL;
					lista->ultim = NULL;
				}
				else
				{
					nod->next->prev = NULL;
					lista->prim = nod->next;
				}
			}
			else
			{
				if (nod->next == NULL) {
					nod->prev->next = NULL;
					lista->ultim = nod->prev;
				}
				else {
					nod->prev->next = nod->next;
					nod->next->prev = nod->prev;
				}
			}

			free(nod->info.numeProiect);
			free(nod);
			nod = NULL;

			//primul nod
		}
		else {
			nod = nod->next;

		}
	}
}

void stergereCompleta(ListaDubla* lista) {
	if (lista != NULL)
	{
		NodLdi* aux = lista->prim;
		while (aux != NULL)
		{
			NodLdi* temp = aux->next;
			free(aux->info.numeProiect);
			free(aux);
			aux = temp;

		}
		lista->prim = NULL;
		lista->ultim = NULL;


	}
}

int calculNrTotalMuncitori(ListaDubla lista)
{
	int suma = 0;
	for (NodLdi* i = lista.prim; i != NULL; i = i->next)
	{
		suma += i->info.nrMuncitori;
	}
	return suma;
}

int main() {
	ListaDubla lista;
	Santier s1 = initializareSantier("Proiect 1", 4, 300);
	Santier s2 = initializareSantier("Proiect 2", 10, 3000);
	Santier s3 = initializareSantier("Proiect 3", 7, 4000);

	lista.prim = NULL;
	lista.ultim = NULL;


	inserareInceput(&lista, s1);
	inserareInceput(&lista, s2);
	inserareInceput(&lista, s3);
	afisareLdiDeLaInceput(lista);

	/*stergereSanterDupaNume(&lista, "Proiect 2");

	afisareLdiDeLaInceput(lista);

	stergereSanterDupaNume(&lista, "Proiect 1");

	afisareLdiDeLaInceput(lista);

	stergereSanterDupaNume(&lista, "Proiect 3");

	afisareLdiDeLaInceput(lista); */


	printf("Nr total de muncitori este: %d", calculNrTotalMuncitori(lista));

	stergereCompleta(&lista);
}