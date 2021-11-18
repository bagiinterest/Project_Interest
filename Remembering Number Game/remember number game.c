#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <limits.h>

int x,y,num,num1,num2,num3,num4;
	int s,s1,num,z;
	int a[16]= {};
	int c[16]= {};
	int b[13]= {};
	int mArr[100][100]={};

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

void randomArray (int Arr[], int z){	
	int r;
		for(r=0; r<z; r++){
		Arr[r]= rand() %50+1;
	}
}

void randomArrayrandom (int Arr[]){
	int i;
	for (i = 0; i < 16; i++) {     // fill array
   	 Arr[i] = i;
  //  printf("%d,", array1[i]);
	}
	
	for (i = 0; i < 16; i++) {    // shuffle array
    int temp1 = Arr[i];
    int randomIndex1 = rand() % 16;

    Arr[i]           = Arr[randomIndex1];
    Arr[randomIndex1] = temp1;
	}
	
}

void matriksArray (int Arr[],int Arr1[],int Arr2[100][100]){
	int r1,r2,z=0;
	for( r1=0; r1<4; r1++){	
		for( r2=0; r2<4; r2++){
		
			Arr2[r1][r2]= Arr[Arr1[z]];
			z++;
		}
	}
}
void atas(){          //Tampilan awal                                                    
printf(" _____                     _                            _     \n");      
printf("| __  |___ _____ ___ _____| |_ ___ ___    ___ _ _ _____| |_ ___ ___ \n");
printf("|    -| -_|     | -_|     | . | -_|  _|  |   | | |     | . | -_|  _| \n");
printf("|_|\\__|___|_|_|_|___|_|_|_|___|___|_|    |_|_|___|_|_|_|___|___|_|  \n\n\n");                                                                                                                                                          
}
void level(int tahap,int level){
	
if(tahap==1){
	printf("\t\t\t\t\tMudah\n");
	printf("\t\t\t\t\tLevel: %d\n\n",level); 
}
if(tahap==2){
	printf("\t\t\t\t\tSedang\n");
	printf("\t\t\t\t\tLevel: %d\n\n",level); 
 }
if(tahap==3){
	printf("\t\t\t\t\tSusah\n");
	printf("\t\t\t\t\tLevel: %d\n\n",level); 
}
}


void tampil(int tes2[100][100]){
	int i,j,x=0,y;
	printf("\n\n");
	
	for(i=1;i<=13;i++){
		if(i==1 || i%3==1){
			printf("\t*********************************\n");
		}
		else if(i%3==0){
			printf("\t|       |       |       |       |\n");
		}
		else{
			printf("\t");
			for(j=0;j<=3;j++){
				printf("|%d",tes2[x][j]);
				if(tes2[x][j]<10){
					printf("      ");}
				else if(tes2[x][j]>=10 && tes2[x][j]<100){
					printf("     ");}
				else{
					printf("    ");
				}
				
				
			}
			x=x+1;
			printf("|\n");
		}
	}
	
}



void kosong(){  //tampilan saat menebak angka
	printf("\n\n");
	printf("\t*****************************\n");
	printf("\t|      |      |      |      |\n");
	printf("\t|      |      |      |      |\n");
	printf("\t*****************************\n");
	printf("\t|      |      |      |      |\n");
	printf("\t|      |      |      |      |\n");
	printf("\t*****************************\n");
	printf("\t|      |      |      |      |\n");
	printf("\t|      |      |      |      |\n");
	printf("\t*****************************\n");
	printf("\t|      |      |      |      |\n");
	printf("\t|      |      |      |      |\n");
	printf("\t*****************************\n");

}


static int cmp(const void *p1, const void *p2){
	if (p1!=0 && p2!=0)
	return *(int*)p1 > *(int*)p2;
}

void answer(int Arr[],int z){   //array jawaban user berupa angka 
	int i,s=0;
	
	printf ("Urutkan angka dengan urutan terkecil ke terbesar:\n");
	for (i=0; i<z; i++){
		s=16-z;
		s=s+i;
		printf("angka ke %d=",i+1);
		scanf("%d", &Arr[s]);
	}
}

char compareArray(int a[],int b[],int size){
	int i;
	for (i=0; i<size; i++){
		if(a[i] != b[i])
			return 1;
	}
	return 0;
}

int border(){  //menu
printf("\n");
printf("_______________________________________________________________________________\n");
printf("\n");
}

int next(){
	atas();
  printf("[4] Kembali ke menu awal\n");
  printf("[5] Exit\n");
  printf("Pilihan anda : ");
   int rows =0;  
    char c;
    do
    {  
        printf("\n");

    } while (((scanf("%d%c", &rows, &c)!=2 || c!='\n') && clean_stdin()) || rows<4 || rows>5);
 // scanf("%d",&num2);
  switch (rows) {
    case 4:
    system("cls");
    body();

    case 5:
    system("cls");
    end();
  }
}

void reset(int Arr1[], int Arr2[], int Arr3[],int Arrm[100][100]){
	int i,j;
	for(i=0;i<16;i++){
		Arr1[i]=0;
		Arr3[i]=0;
	}
	for(i=0;i<13;i++){
		Arr2[i]=0;
		
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			Arrm[i][j]=0;
		}
	}
}

int play(){   //memilih level
	atas();
	printf("Pilih level:\n");
	printf("[1] Mudah\n");
	printf("[2] Sedang\n");
	printf("[3] Sulit\n");
	int rows =0;  
    char c;
    do
    {  
        printf("\n");

    } while (((scanf("%d%c", &rows, &c)!=2 || c!='\n') && clean_stdin()) || rows<1 || rows>3);
	//scanf("%d",&num1);
	
	
	switch (rows){
		case 1:
			system("cls");
			y=1;
			x=1;
			while (y <= 5){
				if (y%2==0)
				x=x+1;
			//	printf("%d\n",x);
				game(x);
				++y;
			}
			border();
  			next();
		case 2:
			system("cls");
			y=1;
			x=3;
			while (y <= 5){
				if (y%2==0)
				x=x+1;
			//	printf("%d\n",x);
				game(x);
				++y;
			}
			border();
  			next();
		case 3:
			system("cls");
				y=1;
			x=5;
			while (y <= 5){
				if (y%2==0)
				x=x+1;
				printf("%d\n",x);
				game(x);
				++y;
			}
			border();
  			next();
	}
}

int body(){
  system("cls");
  atas();
printf("[1] Mulai\n");
printf("[2] Bantuan\n");
printf("[3] Keluar\n");
printf("Pilihan Anda : ");
scanf("%d",&num);

switch (num) {
  case 1:
  system("cls");
  play();
  border();
  next();
  break;

  case 2:
  system("cls");
  border();
  next();
  break;
  
  case 3:
  system("cls");
  end();
}
}

int game(int x){
	reset(a,b,c,mArr);
	z=x+2;
	randomArray(a,z);
/*	for(s=0; s<z; s++){
		printf("%d\n", a[s]);
	}
	printf("\n");*/
	randomArrayrandom(b);
	/*	for(s=0; s<16; s++){
		printf("%d\n", b[s]);
	}*/
	matriksArray(a,b,mArr);
/*	for( s=0; s<4; s++){
		for( s1=0; s1<4; s1++){
			printf("%d ", mArr[s][s1]);
		}
		printf("\n\n");
	}*/
	atas();
	tampil(mArr);
	printf("\tJumlah angka acak= %d\n",z);
	printf("\tIngatlah angkanya\n\n");
	system("pause");
	system("cls");
	atas();
	kosong();
	qsort(a, sizeof(a)/sizeof(int), sizeof(int), cmp);
	/*	for (s=0; s<sizeof(a)/sizeof(int); ++s)
		printf("%d ", a[s]);
		printf("\n");*/
		
	answer(c,z);
	if (compareArray(a,c,16)==0){
		printf("\nCorrect\n\n");
	}
	else {
		printf("\nWrong\n\n");
	}
	system("pause");
	system("cls");
}

int main (){
	srand(time(NULL));
	  body();
	
}
