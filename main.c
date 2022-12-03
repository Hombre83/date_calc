#include <iostream>

int main()
{
	int d;
	int m;
	int y;
	int ly = 0; // Schaltjahr (leap year) - Standardwert: nein
	float lyc; // Schaltjahr-Berechnung

	int err = 0;

	int od;
	int om;
	int oy;

	printf("Willkommen zum Datumsrechner!\n\n");

	printf("Zum Beenden des Programms geben Sie beim Tag bitte 0 ein!\n\nBitte geben Sie den Tag ein!\n");
	scanf_s("%d", &d);

	if (d != 0)
	{
		printf("\nBitte geben Sie den Monat ein!\n");
		scanf_s("%d", &m);
	}

	if (d != 0)
	{
		printf("\nBitte geben Sie das Jahr ein!\n");
		scanf_s("%d", &y);
	}

	getchar();

	for (int i = 1; i > 0;)
	{

		if (d != 0)
		{
			lyc = y;

			if (((y / 400) / (lyc / 400)) * ((y / 400) / (lyc / 400)) == 1)														// SCHALTJAHR?
			{
				ly = 1;																				// SCHALTJAHR
			}
			else if (((y / 100) / (lyc / 100)) * ((y / 100) / (lyc / 100)) == 1)
			{
				ly = 0;																				// KEIN SCHALTJAHR
			}
			else if (((y / 4) / (lyc / 4)) * ((y / 4) / (lyc / 4)) == 1)
			{
				ly = 1;																				// SCHALTJAHR
			}
			else
			{
				ly = 0;																				// KEIN SCHALTJAHR
			}
		}

		if (d > 0 && d < 32 && m > 0 && m < 13 && y > -1000000 && y < 1000000)						// GUELTIGE EINGABE
		{
			if (m == 2)																			// MONAT IST FEBRUAR?
			{
				if (d == 28)																	// TAG IST 28?
				{
					if (ly > 0)																	// SCHALTJAHR?
					{
						od = 29;
						om = m;
						oy = y;
					}
					else																		// KEIN SCHALTJAHR
					{
						od = 1;
						om = m + 1;
						oy = y;
					}
				}
				else if (d == 29 && ly > 0)																// TAG IST 29?
				{
					od = 1;
					om = m + 1;
					oy = y;
				}
				else if (d < 28)																			// TAG IST NICHT 28 || 29
				{
					od = d + 1;
					om = m;
					oy = y;
				}
				else if (d == 29 && ly == 0)
				{
					printf("\nDas angegebene Jahr ist kein Schaltjahr!\n\n");
					err = 1;
				}
				else
				{
					printf("\nUngueltige Eingabe! Dieser Monat kann nur entweder 28 oder 29 Tage haben!\n\n");
					err = 1;
				}
			}
			else																				// MONAT IST NICHT FEBRUAR
			{
				if (d == 30 || d == 31)															// TAG IST 30 || 31?
				{
					if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)	// MONAT HAT 31 TAGE?
					{
						if (d == 30)															// TAG IST 30?
						{
							od = 31;
							om = m;
							oy = y;
						}
						else if (m == 12)														// TAG IST NICHT 30
						{
							od = 1;
							om = 1;
							oy = y + 1;
						}
						else
						{
							od = 1;
							om = m + 1;
							oy = y;
						}
					}
					else if (d == 30)
					{
						od = 1;
						om = m + 1;
						oy = y;
					}
					else
					{
						printf("\nUngueltige Eingabe! Dieser Monat hat weniger als 31 Tage!\n\n");
						err = 1;
					}
				}
				else																			// TAG IST NICHT 30 || 31
				{
					od = d + 1;
					om = m;
					oy = y;
				}
			}
		}
		else if (d == 0)																		// EINGABE FUER DAS JAHR = 0 = PROGRAMM BEENDEN
		{
			i = 0;
		}
		else																					// EINGABE IST UNGUELTIG
		{
			printf("\nBitte machen Sie eine gueltige Eingabe!\n\n");
			err = 1;
		}

		if (err == 0 && d != 0)
		{
			printf("\nDer nachfolgende Tag ist der %d.%d.%d!\n\n", od, om, oy);
		}
		else
		{
			err = 0;
		}
			
		if (d != 0)
		{
			printf("Zum Beenden des Programms geben Sie beim Tag bitte 0 ein!\n\n");

			printf("Bitte geben Sie den Tag ein!\n");
			scanf_s("%d", &d);

			if (d != 0)
			{
				printf("\nBitte geben Sie den Monat ein!\n");
				scanf_s("%d", &m);

				printf("\nBitte geben Sie das Jahr ein!\n");
				scanf_s("%d", &y);
			}
		}

		getchar();

		if (d == 0)
		{
			i = 0;
		}

	}

}
