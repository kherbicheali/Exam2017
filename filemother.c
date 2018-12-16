//Numero compte examen : m1eea_100
//Nom Etudiant : Kherbiche
//Prenom Etudiant : Ali
/////////////////// Examen TIMN - session 1 - 19 décembre 2017

 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Nom de la structure à utiliser et à ne pas modifier */

struct Equation_Recurrente{
	int m;
	int n;
	float *coefa;
	float *coefb;
	//Equation_Recurrente->coefa=malloc((m)*sizeof(float));
};


/* En-têtes des fonctions
Il ne faut pas les modifier */
struct Equation_Recurrente Saisie();
struct Equation_Recurrente Saisie_Affichage();
float Gain_Statique1(struct Equation_Recurrente x);
float Gain_Statique2(struct Equation_Recurrente x, float K);
float Gain_Statique3(struct Equation_Recurrente x);
 


//Question 2 

struct Equation_Recurrente y;
struct Equation_Recurrente x;


struct Equation_Recurrente Saisie(){
	
	int a,b;	
	printf("Saisir l’ordre m de la suite des entrées Ek et l'ordre n de la suite des sorties Sk:\n");
	scanf("%d\t%d",&a,&b);
	y.m=a;	
	y.n=b;
	y.coefa=malloc((a+1)*sizeof(float));
	y.coefb=malloc((b+1)*sizeof(float));
	return y;
}



struct Equation_Recurrente Saisie_Affichage(){
	
	int a,b,i=0,j=0;
	float z=0,l=0;	
	printf("Saisir l’ordre m de la suite des entrées Ek et l'ordre n de la suite des sorties Sk:\n");
	scanf("%d\t%d",&a,&b);
	x.m=a;	
	x.n=b;
	x.coefa=malloc((a+1)*sizeof(float));
	x.coefb=malloc((b+1)*sizeof(float));
	for(;i<a;i++){
		printf("\ncoefa[%d]=",i);
		scanf("%f",&z);
		x.coefa[i]=z;		
	}
	for(;j<b;j++){
		printf("\ncoefb[%d]=",j);
		scanf("%f",&l);
		x.coefb[j]=l;		
	}

	return x;
}


//Question 3	

float Gain_Statique1(struct Equation_Recurrente x){

	int w=0;
	float S2=0;
	int s=0;	
	float S1=0;
	if(x.n==2 && x.m==1){			
	for(;w<x.m;w++){
		S1=S1+x.coefa[w];
	}
	for(;s<(x.n);s++){
		S2=S2+x.coefb[s];
	}
	printf("\nS1=%f\n",S1);
	printf("\nS2=%f\n",S2);
	if(S2==0){
		printf("\nGain infini !\n");		
	} else {	
		printf("\nGain=%f\n",S1/S2);
	}
	} else {
		printf("\nCalcul du gain statique impossible veuillez réesayer svp !");
	}
	return S1/S2;
}

//pour question 4
float Gain_Statique3(struct Equation_Recurrente x){

	int u=0;
	float s2=0;
	int g=0;	
	float s1=0;			
	for(;u<x.m;u++){
		s1=s1+x.coefa[u];
	}
	for(;g<(x.n);g++){
		s2=s2+x.coefb[g];
	}
	printf("\nS1=%f\n",s1);
	printf("\nS2=%f\n",s2);
	if(s2==0){
		printf("\nGain infini !\n");		
	} else {	
		printf("\nGain=%f\n",s1/s2);
	}
	return s1/s2;
}


/*

float Gain_Statique1(struct Equation_Recurrente x){

	int w=0;
	float S2=0;
	int s=0;	
	float S1=0;			
	for(;w<x.m;w++){
		S1=S1+x.coefa[w];
	}
	for(;s<(x.n);s++){
		S2=S2+x.coefb[s];
	}
	if(S2==0){
		printf("\nGain infini !\n");		
	} else {	
		printf("\nGain=%f\n",S1/S2);
	}
	return S1/S2;
}

*/

//Question 4

float Gain_Statique2(struct Equation_Recurrente x, float K){

	printf("\nEntrer la valeur de K:");
	scanf("%f",&K);
	
	if(K!=0){
	y=Saisie();
	printf("Création de y faite");
		if(y.n==3 && y.m==1){
		//y.coefa[0]=x.coefa[0]*K+x.coefa[0]-pow(x.coefa[0],2)*K/x.coefb[0];
		y.coefa[0]=x.coefa[0]*K;
		y.coefb[0]=x.coefa[0]*K-x.coefb[0];
		y.coefb[1]=x.coefb[0]-x.coefb[1];
		y.coefb[2]=x.coefb[1];
        	//Gain_Statique3(y);
		} else {
		printf("\nCalcul du gain statique impossible !");		
		}	
	} else {
		printf("\nK est nul! réessayer svp");
	}
	return Gain_Statique3(y);
}


int main(void){
	
	float K=1;
	Saisie_Affichage();
	Gain_Statique1(x);
	Gain_Statique2(x,K);
	/* Le main est à faire évoluer au cours de l’examen */
	return 0;
}
