#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voiture
{
    char matricule[50];
    int annee;
    char marque[50];
    char modele[50];
    char couleur[20];
    float prix;
    struct voiture *suivant;
};

struct voiture *tete = NULL;

struct voiture *inserer_voiture(struct voiture *tete)
{
    struct voiture *p;
    p = (struct voiture *)malloc(sizeof(struct voiture));

    printf("Insérer l immatriculation de la voiture : ");
    scanf("%s", p->matricule);
    printf("Insérer l'année de la voiture : ");
    scanf("%d", &(p->annee));
    printf("Insérer la marque de la voiture : ");
    scanf("%s", p->marque);
    printf("Insérer le modele de la voiture : ");
    scanf("%s", p->modele);
    printf("Insérer la couleur de la voiture : ");
    scanf("%s", p->couleur);
    printf("Insérer le prix de la voiture : ");
    scanf("%f", &(p->prix));

    if (tete == NULL)
    {
        tete = p;
    }
    else
    {
        p->suivant = tete;
        tete = p;
    }

    return tete;
}

void afficher(struct voiture *tete)
{
    struct voiture *p;
    if (tete == NULL)
    {
        printf("La liste est vide.\n");
    }
    else
    {
        p = tete;
        while (p != NULL)
        {
            printf("Matricule: %s\n", p->matricule);
            printf("Année: %d\n", p->annee);
            printf("Marque: %s\n", p->marque);
            printf("Modele: %s\n", p->modele);
            printf("Couleur: %s\n", p->couleur);
            printf("Prix: %.2f\n", p->prix);
            printf("\n\n");
            p = p->suivant;
        }
    }
}

void choixprix(struct voiture *tete, float prixinf, float prixsup)
{
    struct voiture *p;
    if (tete == NULL)
    {
        printf("La liste est vide.\n");
    }
    else
    {
        p = tete;
        while (p != NULL)
        {
            if ((p->prix >= prixinf) && (p->prix <= prixsup))
            {
                printf("Matricule: %s\n", p->matricule);
                printf("Année: %d\n", p->annee);
                printf("Marque: %s\n", p->marque);
                printf("Modele: %s\n", p->modele);
                printf("Couleur: %s\n", p->couleur);
                printf("Prix: %.2f\n", p->prix);
            }
            p = p->suivant;
        }
    }
}

int nbr_voiture(struct voiture *tete, int an)
{
    struct voiture *p;
    int n = 0;
    p = tete;

    while (p != NULL)
    {
        if (p->annee == an)
        {
            n = n + 1;
        }
        p = p->suivant;
    }

    return n;
}

char* voiture_chere(struct voiture *tete, int ans)
{
    struct voiture *p;
    float prixMax = 0;
    char* matriculeMax = NULL;
    p = tete;

    while (p != NULL)
    {
        if (p->annee == ans)
        {
        if (p->prix > prixMax)
        {
            prixMax = p->prix;
            matriculeMax = p->matricule;
        }
        }
        p = p->suivant;
    }

    return matriculeMax;
}

int main()
{
    int choix;
    float prixInf, prixSup;
    int annee;
    char* matriculeCher;

    do {
        printf("\n1. Inserer une voiture\n");
        printf("2. Afficher les voitures\n");
        printf("3. Afficher les voitures dans une certaine plage de prix\n");
        printf("4. Nombre de voitures d'une annee donnee\n");
        printf("5. Matricule de la voiture la plus chere\n");
        printf("0. Quitter\n");

        printf("\nChoix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                tete = inserer_voiture(tete);
                break;
            case 2:
                afficher(tete);
                break;
            case 3:
                printf("Prix minimum : ");
                scanf("%f", &prixInf);
                printf("Prix maximum : ");
                scanf("%f", &prixSup);
                choixprix(tete, prixInf, prixSup);
                break;
            case 4:
                printf("Annee : ");
                scanf("%d", &annee);
                printf("Nombre de voitures de l'annee %d : %d\n", annee, nbr_voiture(tete, annee));
                break;
            case 5:
                printf("Annee : ");
                scanf("%d", &annee);
                matriculeCher = voiture_chere(tete, annee);
                printf("Matricule de la voiture la plus chere : %s\n", matriculeCher);
                break;
            case 0:
                printf("Programme termine.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
printf("\n");
    return 0;
}
