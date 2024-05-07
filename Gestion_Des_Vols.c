#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LOGIN "admin"
#define MDP "root"

typedef struct passager{
    int  num_pass;                                          //numero du passager
    char nom_pass[20];                                      // nom du passager
    char prenom_pass[20];                                   //prenom du passager
    char num_passport[20];                                  //numéro du téléphone du passager
    char adresse_mail[60];                                  // adresse ou email du passager
    char nationalite[30];                                   //Nationalité du passager
    struct passager *suivant;
}passager;
typedef struct pilote{
    int  id_pil;                                            //id_pilote
    char nom_pil[20];                                       //nom du pilote
    char prenom_pil[20];                                    //prenom du pilote
    char CIN [10] ;                                         //CIN du pilote
    char num_tel_pil [40];                                  //Numéro du téléphone du pilote
    struct pilote *suivant;
}pilote;
typedef struct avion{
    int  num_avion;                                         //num identifiant de l'avion
    char nom_avion[20];                                     //nom d'avion
    int capacite_avion;                                     //La capacité de l'avion
    struct avion *suivant;
}avion;
struct date{                                                //structure date
		int jour ; int mois ; int annee ;
};

typedef struct vol{
	int num_vol;                                            //numéro du vol
	int heure_dep,heure_ar;                                 // heure de depart et heure d'arrivee
    struct date date_vol;
	struct vol* next_vol;
}vol;
//fonction pour rechercher un passager selon son numero pour l'utiliser dans la fonction d'ajout
int rechercher_num_pass(passager*liste_pass,int num_pass_test){
   passager *tmp=liste_pass;
   while(tmp!=NULL){
    if(tmp->num_pass == num_pass_test)
    {
        return 1;
    }
    tmp=tmp->suivant;
   }
    return 0;
}
//fonction qui aide à eviter le redoublement des pilotes
int rechercher_id_pil(pilote * liste_pil,int id_pil_test){
   pilote *tmp=liste_pil;
   while(tmp!=NULL){
    if(tmp->id_pil == id_pil_test)
        return 1;
    tmp=tmp->suivant;
   }
   return 0;
}
//rechercher un avion selon son numero identifiant pour l'utiliser dans la fonction ajout
int rechercher_num_avion(avion *liste_avion,int num_avion_test){
   avion *tmp=liste_avion;
   while(tmp!=NULL){
    if(tmp->num_avion == num_avion_test)
        return 1;
    tmp=tmp->suivant;
   }
    return 0;
}
// focntion pour eviter le redoublement des vols
int rechercher_num_vol(vol * v,int num_vol_test){
   vol *tmp=v;
   while(tmp!=NULL){
    if(tmp->num_vol == num_vol_test)
        return 1;
    tmp=tmp->next_vol;
   }
   return 0;
}
//ajout un passager
passager * Ajout_passager(passager *liste_pass){
    passager *nv_pass;                                      //nouveau_passager
    nv_pass=(passager *)malloc(sizeof(passager));
    if(liste_pass==NULL) printf("On va initialiser la liste\n");
    printf("Entrer les informations sur le passager : \n");   //les informations du passager à inserer
    printf("le numero du passager : ");
    scanf("%d",&nv_pass->num_pass);
    printf("le nom du passager : ");
    scanf("%s",nv_pass->nom_pass);
    printf("le prenom du passager : ");
    scanf("%s",nv_pass->prenom_pass);
    printf("Le numero du passport : ");
    scanf("%s",nv_pass->num_passport);
    printf("L\'adresse ou l\'email du passager : ");
    scanf("%s",nv_pass->adresse_mail);
    printf("La nationalite : ");
    scanf("%s",nv_pass->nationalite);
    nv_pass->suivant=NULL;
    if(liste_pass==NULL)
        return nv_pass;
    else{

        if(rechercher_num_pass(liste_pass,nv_pass->num_pass)==0){   //on a utiliser la fonction rechercher pour éviter la répetition du numero du passager
        passager * tmp =liste_pass;
        while(tmp->suivant!=NULL){
                tmp=tmp->suivant;
        }
        tmp->suivant=nv_pass;
        return liste_pass;
        }
        else{
            printf("Element existe deja\n");
            return liste_pass;
        }
}
}
//ajout des pilotes
pilote * ajout_pil(pilote *liste_pil){
    pilote *nv_pil;
    nv_pil=(pilote *)malloc(sizeof(pilote));
    if(liste_pil==NULL) printf("On va initialiser la liste\n");
    printf("Entrer les informations sur le pilote : \n");
    printf("l\'id du pilote : ");
    scanf("%d",&nv_pil->id_pil);
    printf("le nom du pilote : ");
    scanf("%s",nv_pil->nom_pil);
    printf("le prenom du pilote : ");
    scanf("%s",nv_pil->prenom_pil);
    printf("Le CIN du pilote: ");
    scanf("%s",nv_pil->CIN);
    printf("Le numero du telephone du pilote : ");
    scanf("%s",nv_pil->num_tel_pil);
    nv_pil->suivant=NULL;
    if(liste_pil==NULL)
        return nv_pil;
    else{
        if(rechercher_id_pil(liste_pil,nv_pil->id_pil)==0){
        pilote * tmp =liste_pil;
        while(tmp->suivant!=NULL){
                tmp=tmp->suivant;
        }
        tmp->suivant=nv_pil;
        return liste_pil;
        }
        else{
            printf("Element existe deja\n");
            return liste_pil;
        }
    }
}
//ajout d'un avion a la liste des avion
avion * Ajout_avion(avion *liste_avion){
    avion *nv_avion;
    nv_avion=(avion *)malloc(sizeof(avion));
    if(liste_avion==NULL) printf("On va initialiser la liste\n");
    printf("Entrer les informations sur l\'avion : \n");
    printf("entrer le numero de l\'avion : ");
    scanf("%d",&nv_avion->num_avion);
    printf("entrer le nom  de l\'avion : ");
    scanf("%s",nv_avion->nom_avion);
    printf("entrer la capacite de l\'avion : ");
    scanf("%d",&nv_avion->capacite_avion);
    nv_avion->suivant=NULL;
    if(liste_avion==NULL)
        return nv_avion;
    else{

    if(rechercher_num_avion(liste_avion,nv_avion->num_avion)==0){  //on a utiliser la fonction rechercher pour éviter la répetition d'un avion
        avion * tmp =liste_avion;
        while(tmp->suivant!=NULL){
                tmp=tmp->suivant;
        }
        tmp->suivant=nv_avion;
        return liste_avion;
        }
    else{
        printf("Element existe deja\n");
        return liste_avion;
    }

}
}
// ajout des vols
vol* ajout_vol_enfin(vol* v)
{
   vol* nv=(vol*)malloc(sizeof(vol));
   printf("entrer les infos sur le vol : \n");
   printf("num de vol :"); scanf("%d",&nv->num_vol);
   printf("heure de depart : ");scanf("%d",&nv->heure_dep);
   printf("heure d'arrivee : ");scanf("%d",&nv->heure_ar);
   printf("date de vol : ");scanf("%d%d%d",&nv->date_vol.jour,&nv->date_vol.mois,&nv->date_vol.annee);
   nv->next_vol = NULL;
   if(v==NULL)
     return nv;
   else{
    if(rechercher_num_vol(v,nv->num_vol)==0)
    {
   vol* tmp=v;
   while(tmp->next_vol != NULL)
    {
   tmp = tmp->next_vol;
   }
   tmp->next_vol = nv;
   return v;
}
   else
   {
        printf("Element existe deja\n");
        return v;
}
  }
}
//procedure pour rechercher un passager dans la liste
void rechercher_pass(passager *liste_pass , int num_pass_rec){
    passager *tmp=liste_pass;
    while(tmp!=NULL){
            if(tmp->num_pass==num_pass_rec){
                 printf("\tnum_pass=%d\tnom_pass=%s\tprenom_pass=%s\tnum_passport=%s\tadresse_mail=%s\tnationalite=%s\n",tmp->num_pass,tmp->nom_pass,tmp->prenom_pass,tmp->num_passport,tmp->adresse_mail,tmp->nationalite);
                 return;
            }
            tmp=tmp->suivant;
    }
    printf("l'element ne trouve pas dans la liste ! \n");
}
//la recherche d'un pilote
void rechercher_pil(pilote *liste_pil ,int id_pil_rec){
    pilote *tmp=liste_pil;
    while(tmp!=NULL){
            if(tmp->id_pil==id_pil_rec){
            	printf("\t l'ID=%d \t nomP=%s \t prenomP=%s \t CIN=%s \t numero du telephone =%s\n",tmp->id_pil,tmp->nom_pil,tmp->prenom_pil,tmp->CIN,tmp->num_tel_pil);
            	return;
			}
            tmp=tmp->suivant;
    }
   printf("l'element ne trouve pas dans la liste ! ");
}
//rechercher un avion selon son numero identifiant
void rechercher_avion(avion *liste_avion , int num_avion_rec){
    avion *tmp=liste_avion;
    while(tmp!=NULL){
            if(tmp->num_avion==num_avion_rec){
                 printf("\tnum_avion=%d\t\tnom_avion=%s\t\tcategorie_avion=%d\n",tmp->num_avion,tmp->nom_avion,tmp->capacite_avion);
                 return;
            }
            tmp=tmp->suivant;
    }
    printf("element non trouve\n");
}
// rechercher un vol  selon son identifiant
void rechercher_vol(vol* v,int val){

		while(v!=NULL)
	{
		if(v->num_vol==val)
		{
		printf("\tnum de vol=%d\theure de depart=%dh\theure d'arivee=%dh\tdate de vol=%d-%d-%d\n",v->num_vol,v->heure_dep,v->heure_ar,v->date_vol.jour,v->date_vol.mois,v->date_vol.annee);
		return;
		}
		v=v->next_vol;
	}
	printf("vol introuvable ! \n");
}
//supprimer un passager via sa reference
passager* supprimer_pass(passager *liste_pass, int num_pass_sup)
{

    passager *courant, *prochain;
    courant=liste_pass;
    if(liste_pass == NULL)
        return NULL;


    if(courant->num_pass == num_pass_sup)
    {


        prochain = courant->suivant;
        free(courant);

        return prochain;
    }
    else
    {
        liste_pass->suivant = supprimer_pass(liste_pass->suivant, num_pass_sup);
        return liste_pass;
    }
}
//supprimer un pilote
pilote* supprimer_pil(pilote *liste_pil, int id_pil_sup)
{

    pilote *courant, *prochain;
    courant=liste_pil;
    if(liste_pil == NULL)
        return NULL;


    if(courant->id_pil == id_pil_sup)
    {


        prochain = courant->suivant;
        free(courant);

        return prochain;
    }
    else
    {
        liste_pil->suivant = supprimer_pil(liste_pil->suivant, id_pil_sup);
        return liste_pil;
    }
}
//supprimer un avion de la liste des avions
avion  *supprimer_avion(avion *liste_avion, int num_avion_sup)
{

    avion *courant, *prochain;
    courant=liste_avion;
    if(liste_avion == NULL)
        return NULL;
    if(courant->num_avion == num_avion_sup)
    {
        prochain = courant->suivant;
        free(courant);
        return prochain;
    }
    else
    {
        liste_avion->suivant = supprimer_avion(liste_avion->suivant, num_avion_sup);
        return liste_avion;
    }
}
// supprimer un vol
vol* supp_vol(vol* v)
{

   vol* tmp,*p;
   int val;

   if( v!=NULL ) // si la liste n'est pas vide
   {
   	printf("entrer le vol a supprimer : ");
    scanf("%d",&val);
   	if( v->num_vol==val ) //si l'element recherche est le premier dans la liste
   	{
   		p=v;
   		v=v->next_vol;
   		free(p);
	   }
	else
	{
		tmp=v;
		while(tmp->next_vol!=NULL && tmp->next_vol->num_vol!=val ) // tant qu'ont a pas encore trouve l'element
		    tmp=tmp->next_vol; // passer a l'element suivant

		if (tmp->next_vol!=NULL)
		{
		   p=tmp->next_vol;
		   tmp->next_vol=tmp->next_vol->next_vol;
		   free(p);
		}
		printf("not found ! \n");
	}
   }
   return v;
}

//modifier les informations d'un passager
passager * modifier_info(passager * liste_pass , int num_pass_modif){
    char nom_pass_mod[20];
    char prenom_pass_mod[20];
    char num_passport_mod[20];
    char adresse_mail_mod[60];
    char nationalite_mod[30];
     passager *tmp=liste_pass;
     while(tmp!=NULL){
     if(tmp->num_pass == num_pass_modif){
            printf("entrer les informations de modification : \n");
            printf("Le nom de modification  du passager : ");
            scanf("%s",nom_pass_mod);
            printf("le prenom de modification du passager : ");
            scanf("%s",prenom_pass_mod);
            printf("Le numero de passeport de modification  du passager : ");
            scanf("%s",num_passport_mod);
            printf("L\{adresse ou L\' email de modification du passager : ");
            scanf("%s",adresse_mail_mod);
            printf("La nationalité de modification du passager : ");
            scanf("%s",nationalite_mod);
            strcpy(tmp->nom_pass,nom_pass_mod);
            strcpy(tmp->prenom_pass,prenom_pass_mod);
            strcpy(tmp->num_passport,num_passport_mod);
            strcpy(tmp->adresse_mail,adresse_mail_mod);
            strcpy(tmp->nationalite,nationalite_mod);
            printf("modification avec succes\n");
    }
    tmp=tmp->suivant;
   }
    printf("modification echoue (passager non trouve)\n");
}
//modifier les coordonées d'un pilote
void modifier_info_pilote(pilote * liste_pil , int id_pil_modif){
    char nom_pil_mod  [20];
    char prenom_pil_mod [20];
    char CIN_mod [10];
    char num_tel_pil_mod [40];
    pilote * tmp = liste_pil;
    while(tmp!= NULL){
        if(tmp->id_pil == id_pil_modif){
            printf("entrer les informations de modification : \n");
            printf("Le nom de modification du pilote : ");
            scanf("%s",nom_pil_mod);
            printf("le prenom de modification du pilote : ");
            scanf("%s",prenom_pil_mod);
            printf("CIN de modification  du pilote : ");
            scanf("%s",CIN_mod);
            printf("Le numero du telephone de modification du pilote : ");
            scanf("%s",num_tel_pil_mod);
            strcpy(tmp->nom_pil,nom_pil_mod);
            strcpy(tmp->prenom_pil,prenom_pil_mod);
            strcpy(tmp->CIN,CIN_mod);
            strcpy(tmp->num_tel_pil,num_tel_pil_mod);
             printf("modification par succes\n");
			}
			tmp = tmp->suivant;
		}
        printf("cet Id n'existe pas !");

}
//modifier les informations d'un avion
avion * modifier_info_avion(avion * liste_avion , int num_avion_modif){
    char nom_avion_mod[20];
    int capacite_avion_mod;
    avion  *tmp=liste_avion;
     while(tmp!=NULL){
     if(tmp->num_avion == num_avion_modif){
            printf("entrer les informations de modification : \n");
            printf("Le nom de modification  d\'avion : ");
            scanf("%s",nom_avion_mod);
            printf("La capacite de modification d\'avion : ");
            scanf("%d",&capacite_avion_mod);
            strcpy(tmp->nom_avion,nom_avion_mod);
            tmp->capacite_avion=capacite_avion_mod;
            printf("modification avec succes\n");
    }
    tmp=tmp->suivant;
   }
    printf("modification echoue\n");
}

// modifier un vol
void modifier_vol(vol * v , int num_vol_modif){
    int heure_dep_modif,heure_ar_modif;
    int jour_modif,mois_modif,annee_modif;
    vol * tmp = v;
    while(tmp!= NULL){
        if(tmp->num_vol == num_vol_modif){
            printf("entrer les informations de modification : \n");
            printf("L'heure de depart de modification du vol : ");
            scanf("%d",&heure_dep_modif);
            printf("l'heure d'arrivee de modification du pilote : ");
            scanf("%d",&heure_ar_modif);
            printf("date de modification  du pilote : ");
            scanf("%d%d%d",&jour_modif,&mois_modif,&annee_modif);
            tmp->heure_dep=heure_dep_modif;
            tmp->heure_ar=heure_ar_modif;
            tmp->date_vol.jour=jour_modif;
            tmp->date_vol.mois=mois_modif;
            tmp->date_vol.annee=annee_modif;
             printf("modification par succes\n");
			}
			tmp = tmp->next_vol;
		}
        printf("ce vol n'existe pas !");

}

//afficher la liste des passager
void afficher_passagers(passager *liste_pass){
    if(liste_pass==NULL)
        printf("fichier vide\n");
    else{
            printf("\tnum_pass\tnom_pass\tprenom_pass\tnum_transport\tadresse_mail\tnationalite\n");
            passager *tmp=liste_pass;
            while(tmp!=NULL){
                    printf("\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",tmp->num_pass,tmp->nom_pass,tmp->prenom_pass,tmp->num_passport,tmp->adresse_mail,tmp->nationalite);
                    tmp=tmp->suivant;
            }
    }
}
//affichage de la liste des pilotes
void afficher_pilotes(pilote *liste_pil){
    if(liste_pil==NULL)
        printf("pile vide");
    else{
            pilote *tmp=liste_pil;
            printf("\tID\tNomP\tPrenom\tCIN\tNumero du tel\n");
            while(tmp!=NULL){
                   printf("\t%d\t%s\t%s\t%s\t%s\n",tmp->id_pil,tmp->nom_pil,tmp->prenom_pil,tmp->CIN,tmp->num_tel_pil);
                    tmp=tmp->suivant;
            }
    }
}
//afficher la liste des avions
void afficher_avions(avion *liste_avion){
    if(liste_avion==NULL)
        printf("  pile vide\n");
    else{
            printf("\tnum_avion\tnom_avion\tcategorie_avion\n");
            avion *tmp=liste_avion;
            while(tmp!=NULL){
                    printf("\t%d\t\t%s\t\t%d\n",tmp->num_avion,tmp->nom_avion,tmp->capacite_avion);
                    tmp=tmp->suivant;
            }
    }
}
// affichage des vols
void affiche_vol(vol* v){
	vol* tmp=v;
	if(v==NULL)
	printf("liste vide \n");
	else
	{
	while(tmp != NULL)
	{
		printf("\tnum de vol\theure de depart\theure d'arrivee\tdate de vol\n");
		printf("\t%d\t\t%dh\t\t%dh\t\t%d-%d-%d\n",tmp->num_vol,tmp->heure_dep,tmp->heure_ar,tmp->date_vol.jour,tmp->date_vol.mois,tmp->date_vol.annee);
		tmp=tmp->next_vol;
	}
}
}
//sauvegarder la liste des passagers dans un fichier .txt
FILE *sauvgarder_liste_pass(passager *liste_pass , FILE *f){
char nomFichier[30]="passager.txt";
do{
    f=fopen(nomFichier,"a");
    if(!f)
        printf("\a erreur : fichier non ouvert\n");
}while(!f);
passager *tmp=liste_pass;
while(tmp!=NULL){
        fprintf(f,"\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",tmp->num_pass,tmp->nom_pass,tmp->prenom_pass,tmp->num_passport,tmp->adresse_mail,tmp->nationalite);
        tmp=tmp->suivant;
}
fclose(f);
return f;
}
//sauvegarde de la liste des pilotes dans un fichier .txt
FILE *sauvgarder_liste_pil(pilote *liste_pil , FILE *f){
char nomFichier[30]="pilote.txt";
do{
    f=fopen(nomFichier,"a");
    if(!f)
        printf("\a erreur : fichier non ouvert\n");
}while(!f);
pilote *tmp=liste_pil;
while(tmp!=NULL){
        fprintf(f,"\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n",tmp->id_pil,tmp->nom_pil,tmp->prenom_pil,tmp->CIN,tmp->num_tel_pil);
        tmp=tmp->suivant;
}
fclose(f);
return f;
}
//sauvegarder la liste des avions
FILE *sauvgarder_liste_avion(avion *liste_avion , FILE *A){
char nomFichier[30]="avion.txt";
do{
    A=fopen(nomFichier,"a");
    if(!A)
        printf("\a erreur : fichier non ouvert\n");
}while(!A);
avion *tmp=liste_avion;
while(tmp!=NULL){
        fprintf(A,"\t%d\t\t%s\t\t%d\n",tmp->num_avion,tmp->nom_avion,tmp->capacite_avion);
        tmp=tmp->suivant;
}
fclose(A);
return A;
}
// sauvegarder dans un fichier
FILE *sauvgarder_liste_vol(vol *v , FILE *f){
char nomFichier[30]="vol.txt";
do{
    f=fopen(nomFichier,"a");
    if(!f)
        printf("\a erreur : fichier non ouvert\n");
}while(!f);
vol *tmp=v;
while(tmp!=NULL){
        fprintf(f,"\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",tmp->num_vol,tmp->heure_dep,tmp->heure_ar,tmp->date_vol.jour,tmp->date_vol.mois,tmp->date_vol.annee);
        tmp=tmp->next_vol;
}
fclose(f);
return f;
}
//menu des passagers
void menu_passager(){
    system ("CLS");
	system("COLOR 0B");
   passager *liste_pass;
   FILE *f;
   int num_pass_sup;
   int num_pass_rec;
   int num_pass_modif;
   int i;
        do{
        printf("\n\t\t\tMENU\n");
        printf("\t1:Initialiser la liste\n");
        printf("\t2:ajouter un passager a la liste des passagers\n");
        printf("\t3:affichage de la liste\n");
        printf("\t4:Rechercher un passager de la liste des passagers via son numero\n");
        printf("\t5:supprimer un passager de la liste des passagers via son numero\n");
        printf("\t6:modifier un passager de la liste des passagers via son numero\n");
        printf("\t7:sauvegarder la liste dans un fichier binaire\n");
        printf("\t8:Lecture du fichier ou la liste est enregistre\n");
        printf("\t9:supprimer le fichier\n");
        printf("\t20:sortir\n\n");
        printf("\n entrer votre choix selon le menu : ");
        scanf("%d",&i);
        switch(i){
            case 1 : liste_pass=NULL;break;
            case 2 : liste_pass=Ajout_passager(liste_pass);break;
            case 3 : afficher_passagers(liste_pass);break;
            case 4 : printf("entrer le numero du passager a extraire : ");
                     scanf("%d",&num_pass_rec);
                     rechercher_pass(liste_pass,num_pass_rec);
                     break;
            case 5 : printf("entrer le numero du passager a supprimer : ");
                     scanf("%d",&num_pass_sup);
                     if(rechercher_num_pass(liste_pass,num_pass_sup)!=0)
                        printf("supression avec succes\n");
                     else
                        printf("passager non trouve\n");
                     liste_pass=supprimer_pass(liste_pass,num_pass_sup);break;
            case 6 : printf("entrer le numero du passager a modfier : ");
                     scanf("%d",&num_pass_modif);
                     modifier_info(liste_pass,num_pass_modif);
                     break;
            case 7 : f=sauvgarder_liste_pass(liste_pass,f);break;
            case 8 : f=fopen("passager.txt","r"); //lire le contenu du fichier passager.txt
                      printf("\tnum_pass\tnom_pass\tprenom_pass\tnum_transport\tadresse_mail\tnationalite\n");
                      while(!feof(f)){
                        passager *tmp=liste_pass;
                            fscanf(f,"\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",&tmp->num_pass,tmp->nom_pass,tmp->prenom_pass,tmp->num_passport,tmp->adresse_mail,tmp->nationalite);
                            printf("\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",tmp->num_pass,tmp->nom_pass,tmp->prenom_pass,tmp->num_passport,tmp->adresse_mail,tmp->nationalite);
                            tmp=tmp->suivant;
                      }
                      fclose(f);break;
            case 9 : f=remove("passager.txt");break;
            case 20 : break;
            default : printf("choix invalide\n");break;
        }
        }while(i!=20);
}
//menu des avions
void menu_pilote(){

	system("COLOR E");
    pilote * liste_pil;
    FILE *f;
   int id_pil_sup;
   int id_pil_rec;
   int id_pil_modif ;
   int i;
        do{
        printf("\t\t\tMENU\n");
        printf("\t1:Initialiser la liste\n");
        printf("\t2:ajouter un pilote a la liste des pilotes\n");
        printf("\t3:affichage de la liste es pilotes\n");
        printf("\t4:Rechercher un pilotes de la liste des pilote via son id\n");
        printf("\t5:supprimer un pilote de la liste des pilotes via son id\n");
        printf("\t6:modifier un pilote de la liste des pilotes via son id\n");
        printf("\t7:sauvegarder la liste dans un fichier .txt\n");
        printf("\t8:Lecture du fichier ou la liste est enregistre\n");
        printf("\t9:supprimer le fichier\n");
        printf("\t20:sortir\n\n");
        printf("\n entrer votre choix selon le menu : ");
        scanf("%d",&i);
        switch(i){
            case 1 : liste_pil=NULL;break;
            case 2 : liste_pil=ajout_pil(liste_pil);break;
            case 3 : afficher_pilotes(liste_pil);break;
            case 4 : printf("entrer l\'id du pilote a extraire : ");
                     scanf("%d",&id_pil_rec);
                     rechercher_pil(liste_pil,id_pil_rec);
                     break;
            case 5 : printf("entrer l\'id du pilote a supprimer : ");
                     scanf("%d",&id_pil_sup);
                     liste_pil=supprimer_pil(liste_pil,id_pil_sup);break;
            case 6 :  printf("entrer l\'id de modification : ");
                      scanf("%d",&id_pil_modif);
                     modifier_info_pilote(liste_pil,id_pil_modif);
                     break;
            case 7 : f=sauvgarder_liste_pil(liste_pil,f);break;
            case 8 :
			f=fopen("pilote.txt","r");

            printf("\tid_pil\tnomP\tprenom_pil\tCIN\tnum_tel_pil\n");
            while(!feof(f)){
            	fscanf(f,"\t%d\t%s\t%s\t%s\t%s\n",&liste_pil->id_pil,liste_pil->nom_pil,liste_pil->prenom_pil,liste_pil->CIN,liste_pil->num_tel_pil);
				printf("\t%d\t%s\t%s\t%s\t%s\n",liste_pil->id_pil,liste_pil->nom_pil,liste_pil->prenom_pil,liste_pil->CIN,liste_pil->num_tel_pil);
			}
			fclose(f);
				break;
            case 9 : f=remove("pilote.txt");
			break;
            case 20 : break;
            default : printf("choix invalide");break;
        }
        }while(i!=20);
}
//menu des avions
void menu_avion(){

    system("COLOR D");
   avion *liste_avion;
   FILE *A;
   int num_avion_sup;
   int num_avion_rec;
   int num_avion_modif;
   int i;
        do{
        printf("\n\t\t\tMENU\n");
        printf("\t1:Initialiser la liste\n");
        printf("\t2:ajouter une avion  a la liste des avions\n");
        printf("\t3:affichage de la liste\n");
        printf("\t4:Rechercher un avion de la liste des avions via son numero\n");
        printf("\t5:supprimer un avion de la liste des avions  via son numero\n");
        printf("\t6:modifier un avion de la liste des avion via son numero\n");
        printf("\t7:sauvegarder la liste dans un fichier \n");
        printf("\t8:Lecture du fichier ou la liste est enregistre\n");
        printf("\t9:supprimer le fichier\n");
        printf("\t20:sortir\n\n");
        printf("\n entrer votre choix selon le menu : ");
        scanf("%d",&i);
        switch(i){
            case 1 : liste_avion=NULL;break;
            case 2 : liste_avion=Ajout_avion(liste_avion);break;
            case 3 : afficher_avions(liste_avion);break;
            case 4 : printf("entrer le numero de l\'avion a extraire : ");
                     scanf("%d",&num_avion_rec);
                     rechercher_avion(liste_avion,num_avion_rec);
                     break;
            case 5 : printf("entrer le numero de l\'avion a supprimer : ");
                     scanf("%d",&num_avion_sup);
                     if(rechercher_num_avion(liste_avion,num_avion_sup)!=NULL)
                        printf("supression avec succes\n");
                     else
                        printf("avion non trouve\n");
                     liste_avion=supprimer_avion(liste_avion,num_avion_sup);break;
            case 6 : printf("entrer le numero de l\'avion a modfier : ");
                     scanf("%d",&num_avion_modif);
                     modifier_info_avion(liste_avion,num_avion_modif);
                     break;
            case 7 : A=sauvgarder_liste_avion(liste_avion,A);break;
            case 8 : A=fopen("avion.txt","r");    //lecture des fichiers
                      printf("\tnum_avion\tnom_avion\tcategorie_avion\n");
                      while(!feof(A)){
                            fscanf(A,"\t%d\t\t%s\t\t%d\n",&liste_avion->num_avion,liste_avion->nom_avion,&liste_avion->capacite_avion);
                            printf("\t%d\t\t%s\t\t%d\n",liste_avion->num_avion,liste_avion->nom_avion,liste_avion->capacite_avion);
                      }
                      fclose(A);break;
            case 9 : A=remove("avion.txt");break;
            case 20 : break;
            default : printf("choix invalide\n");break;
        }
        }while(i!=20);
}
// menu des vols
void menu_vol(){
      system("COLOR C");
      int choix,val,n;
      int j,m,a;
      int num_vol_mod;
      FILE* f;
      vol* v;
      do{
        printf("\t\t\t\------Menu_vols------\n");
        printf("\t 1 : initialiser la liste des vols \n");
        printf("\t 2: ajouter un vol a la fin de la liste \n");
        printf("\t 3: Modifier les informations d\'un vol \n");
        printf("\t 4: Supprimer un vol \n");
        printf("\t 5: Rechercher un vol \n");
        printf("\t 6: Affichage de la liste \n");
        printf("\t 7: enregistrer dans la liste dans un fichier \n");
        printf("\t 8: lire depuis le fichier \n");
        printf("\t 9: supprimer le fichier \n");
        printf("\n \tquelle est votre choix : ");
        scanf("%d",&choix);

        switch(choix){

            case 1 : v=NULL;break;
			case 2: v=ajout_vol_enfin(v);break;
        	case 3:  printf("entrer le numero de vol de modification : ");
        	         scanf("%d",&num_vol_mod);
        	        modifier_vol(v,num_vol_mod);
        	        break;
        	case 4:
			     v=supp_vol(v);break;
        	case 5: printf("entrer le num de vol rehcerche : ");scanf("%d",&val);
        	    rechercher_vol(v,val);
				break;
        	case 6:   affiche_vol(v);break;
        	case 7: f=sauvgarder_liste_vol(v,f);break;
        	case 8: f=fopen("vol.txt","r");

            printf("\tnum_vol\t heure de depart\t heure d'arrivee\t date\n");
            while(!feof(f)){
            	fscanf(f,"\t%d\t%d\t%d\t%d\t%d\t%d\n",&v->num_vol,&v->heure_dep,&v->heure_ar,&v->date_vol.jour,&v->date_vol.mois,&v->date_vol.annee);
				printf("\t%d\t\t%d\t\t%d\t\t\t%d-%d-%d\n",v->num_vol,v->heure_dep,v->heure_ar,v->date_vol.jour,v->date_vol.mois,v->date_vol.annee);
			}
			fclose(f);
			break;
			case 9 : f=remove("vol.txt");break;
        	case 20 : break;
        	default : printf("choix invalide \n");
		}
        } while(choix!=20);
}

void menu_principal(){
    system("COLOR 02");
   int z;
        do{
        system ("CLS");
        printf("\n\t\t\tMENU_PRINCIPALE\n");
        printf("\t1:menu des passagers\n");
        printf("\t2:menu des pilotes\n");
        printf("\t3:menu des avions\n");
        printf("\t4:menu des vols\n");
        printf("\t20:sortir\n\n");
        printf("\n entrer votre choix selon le menu : ");
        scanf("%d",&z);

        switch(z){
            case 1 : system ("CLS");
                menu_passager();break;
            case 2 : system ("CLS");
                menu_pilote();break;
            case 3 : system ("CLS");
                menu_avion();break;
            case 4 : system ("CLS");
                menu_vol();break;
            case 20 : break;
            default : printf("choix invalide\n");break;
        }
        }while(z!=20);
}
int main()
{
    system("COLOR 09");
    char nom_utilisateur[20] ;
    do
    {
        system ("CLS");                                //pour vider le console
        printf ("Nom  d'utilisateur : ");
        scanf("%s", nom_utilisateur);
        if(strcmp(nom_utilisateur,LOGIN)!=0)
        {
            printf("Nom d'utilisateur invalide ! (press enter) ");
            getch ();
        }


    }while (strcmp(nom_utilisateur,LOGIN)!=0);
    char d;                                 //Stocke le caractère courant
    char mot_de_pass[10] ;                  //Mot de passe  final saisie
    char chaine[10];                       //Mot de passe  initial saisie
    int nb;                                //compte le nombre de caractère que contient le mot de passe
    int i;
    do
     {
        printf("Mot de passe pour acceder au projet: ");
        nb=0;
        while ((d=getch())!=13)            //code ASCII de la touche ENTER  est 13
        {
            if(d!=8 && nb<10)              //code ASCII de la  touche BACKSPACE est 8
            {
                chaine [nb]=d;             //pour entrer un caractere de mot de passe
                nb++;
                printf("*");
            }
            else
            {
                if(nb>0)
                {
                    nb--;                   //pour effacer un caractere du mot de passe
                   chaine[nb]='\0';
                }
            }
        }
                                            //On copie tous les caractères contenu dans la chaine
        for( i=0;i<nb; i++)
        {
            mot_de_pass[i]=chaine[i];
        }
        mot_de_pass[i]='\0';                   //On indique le caractère de fin de ligne
        if(strcmp(mot_de_pass, MDP)!=0)
        {
            printf("\n \a\a\aMot de passe invalide \n");
        }
    }while(strcmp(mot_de_pass,MDP)!=0);
    passager * liste_pass = (passager *)malloc(sizeof(passager));
    pilote * liste_pil = (pilote *)malloc(sizeof(pilote));
    avion * liste_avion = (avion * )malloc(sizeof(avion));
    vol * v= (vol* )malloc(sizeof(vol));
    menu_principal();
    return 0;
}
