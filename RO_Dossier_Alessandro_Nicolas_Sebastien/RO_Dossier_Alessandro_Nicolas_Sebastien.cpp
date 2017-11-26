// RO_Dossier_Alessandro_Nicolas_Sebastien.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    return 0;
}


void initialisations(int s, int *fileNormale, int *fileExpress, int *nbMinInoccupation, int *nbPrioritaires, int *minStationExpress, int *minStationNormale, int *t, int *minCumulExpress, int *minCumNormale, int *minCumPrioritaire, int *minStationExpressPrécédent, int *tabStationExpress, ClientNormale *tabStationNormale)
{
	//Initialisations des stations

	int i = 0;
	while (i < NBSTATION_EXPRESS)
	{
		tabStationExpress[i] = 0;
	}

	i = 0;
	while (i < s)
	{
		tabStationNormale[i].DS = 0;
		tabStationNormale[i].type = VIDE;
	}

	//Initialisations des variables
	*fileNormale = *fileExpress = *nbMinInoccupation = *nbPrioritaires = *minStationExpress = *minStationNormale = *minCumulExpress = *minCumNormale = *minCumPrioritaire = *minStationExpressPrécédent = 0;
	*t = 1;
}

void placementEnFile(int nbArrivées, int *fileExpress, int *fileNormale, int *tabFileExpress, int *tabFileNormale, int *nbrExpressDansStationNormaleEtFileNormale, int nbPrioritaires, int *nbrNormaleDansSystème, int *cout)
{
	int i = 0;
	int DS = 0;
	int iPos;

	while (i < nbArrivées)
	{
		DS = générerDS();

		if (DS <= 3)
		{
			if (*fileExpress < 8)
			{
				tabFileExpress[*fileExpress] = DS;
				*fileExpress++;
			}
			else
			{
				*nbrExpressDansStationNormaleEtFileNormale++;
				iPos = nbPrioritaires;

				while (iPos < *fileNormale && tabFileNormale[iPos] <= 3)
				{
					iPos++;
				}

				décalageDroite(tabFileNormale, *fileNormale, iPos);
				tabFileNormale[iPos] = DS;
				*fileNormale++;
				*cout += 5;
			}
		}
		else
		{
			tabFileNormale[iPos] = DS;
			*fileNormale++;
			*nbrNormaleDansSystème++;
		}
		i++;
	}
}