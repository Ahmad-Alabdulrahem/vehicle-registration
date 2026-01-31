
// student: Ahmad Alabdulrahem 

#include"lab3.h"



void check(char* x)
{
    int i = 0;
    
    while(x[i] == ' '){
        printf("Du kan inte börja med ett mellanslag!!!. Försök igen..\n");
        fgets(x, M, stdin);
    }
}

vehicle_t addavehicle()
{
    vehicle_t p;
    int i = 0;
    char name[STR_MAX];
    char age[STR_MAX];
    int AGE;
    char vehicle_type[STR_MAX];
    char model[STR_MAX];
    char registration_number[STR_MAX];
    
    printf("Ange ditt namn...\n");
    fgets(name, M, stdin);
    check(name);
    strtok(name, "\n");
    while(name[i] == ' ');
    printf("Ange din ålder...\n");
    fgets(age, M, stdin);
    AGE = atoi(age);
    
    while (AGE == 0)
    {
        printf("Felaktig ålder, ange din ålder igen!");
        fgets(age, M, stdin);
        AGE = atoi(age);
    };
    
    printf("Ange fordonets typ...\n");
    fgets(vehicle_type, M, stdin);
    check(vehicle_type);
    strtok(vehicle_type, "\n");

    
    printf("Ange fordonets modell...\n");
    fgets(model, M, stdin);
    check(model);
    strtok(model, "\n");



    printf("Ange registreringsnumret...\n");
    fgets( registration_number, M, stdin);
    check(registration_number);
    strtok(registration_number, "\n");

    
    
    strcpy(p.owner.name, name);
    p.owner.age = AGE;
    strcpy(p.vehicle_type, vehicle_type);
    strcpy(p.model, model);
    strcpy(p.registration_number, registration_number);
    
    return p;
    
}




void printall(vehicle_t places[], int size)
{
    
    int i;
    if(size == 0)
        printf("Alla platser är tomma!!\n");
    else
    {
   
        for(i = 0 ; i < size; i++)
        {
            printf("Fordonsnummer %d.......\n", i + 1);
            printf("......................................\n");
            printf("Ägarens namn är: %s\n", places[i].owner.name);
            printf("......................................\n");
            printf("Ägarens ålder är: %d\n", places[i].owner.age);
            printf("......................................\n");
            printf("Fordonstypen är: %s\n", places[i].vehicle_type);                 
            printf("......................................\n");
            printf("Fordonsmodellen är: %s\n", places[i].model);
            printf("......................................\n");
            printf("Fordonets registreringsnummer är: %s\n", places[i].registration_number);
        
        }   
    }
}


void print(vehicle_t places[], int size)
{
    char choice1[STR_MAX];
    int CHOICE1;
    printf("välj en position mellan 1 och 10...\n");
    fgets(choice1, M, stdin);
    CHOICE1 = atoi(choice1);
     do 
    {
        if (CHOICE1 == 0 || CHOICE1 > 10)
        {
            printf("Felaktigt VAL, ange en position igen!");
            fgets(choice1, M, stdin);
            CHOICE1 = atoi(choice1);
        }
    
    }

    while(CHOICE1 == 0 || CHOICE1 > 10);
    
    
    if(CHOICE1 > size)
        printf("Positionen är tom!\n");
    
    else
    {
        CHOICE1 = CHOICE1 - 1;
        printf("Ägarens namn är: %s\n", places[CHOICE1].owner.name);
        printf("......................................\n");
        printf("Ägarens ålder är: %d\n", places[CHOICE1].owner.age);
        printf("......................................\n");
        printf("Fordonstypen är: %s\n", places[CHOICE1 ].vehicle_type);                 
        printf("......................................\n");
        printf("Fordonsmodellen är: %s\n", places[CHOICE1 ].model);
        printf("......................................\n");
        printf("Fordonets registreringsnummer är: %s\n", places[CHOICE1].registration_number);
        
    }
    
}


void write(vehicle_t places[], char filename[], int size)
{
    FILE * in;
    in = fopen("in.txt", "w");
    if(!in)
        printf("Filen öppnades inte!");
    
    for (int i = 0; i < size; i++)
    fprintf(in, "%s %d %s %s %s\n",places[i].owner.name, places[i].owner.age, places[i].vehicle_type, places[i].model, places[i].registration_number);
    
    fclose(in);
}



void read(vehicle_t places[], char filename[], int *size) {
    int read;
    FILE *in;
    in = fopen(filename, "r");
    if (!in) {
        printf("Couldn't open file!");
        return;
    }

    do {
        read = fscanf(in, "%s %d %s %s %s", places[*size].owner.name, &places[*size].owner.age, places[*size].vehicle_type, places[*size].model, places[*size].registration_number);
        if (read != EOF) {
            (*size)++;
        }
    } while (read != EOF);

    fclose(in);
}



void deleteavehicle(vehicle_t places[], int *size)
{
    char pos[STR_MAX];
    int pos1;
    do 
    {
         printf("Vilken position vill du ta bort? välj mellan 1 och 10\n");
         fgets(pos, M, stdin);
         pos1 = atoi(pos);
         if (pos1 == 0 || pos1 > 10)
             printf("felaktigt, försök igen!\n");
    }
    
    while(pos1 == 0 || pos1 > 10);
    
    
    
    pos1 = pos1 - 1; 
    
    if(pos1 < *size)
    {
        for(int i = pos1; i < MAX; i++)
        {
            strcpy (places[i].owner.name,  places[i + 1].owner.name);
            places[i].owner.age  = places[i + 1].owner.age;
            strcpy (places[i].vehicle_type, places[i + 1].vehicle_type);
            strcpy (places[i].model, places[i + 1].model);
            strcpy (places[i].registration_number,  places[i + 1].registration_number);
        
        }
    *size = *size - 1;
     printf("%d", *size);
        
        
    }
        
    else
  
      printf("positionen är tom\n");
     printf("%d", *size);
        
  
}        
     

void sort(vehicle_t places[], int size)
{
    char temp_name[STR_MAX];
    int temp_age;
    char temp_type[STR_MAX];
    char temp_model[STR_MAX];
    char temp_reg[STR_MAX];
    
    
    
    for(int i = 1; i < size; i++)
    {
        for(int k = 0; k < size - 1; k++)
        {
            if(strcmp(places[k].model, places[k+1].model) > 0)
            {
               strcpy (temp_name,  places[k].owner.name);
               temp_age = places[k].owner.age;
               strcpy (temp_type, places[k].vehicle_type);
               strcpy (temp_model, places[k].model);
               strcpy (temp_reg,  places[k].registration_number);
                
               strcpy (places[k].owner.name,  places[k + 1].owner.name);
               places[i].owner.age  = places[k + 1].owner.age;
               strcpy (places[k].vehicle_type, places[k + 1].vehicle_type);
               strcpy (places[k].model, places[k + 1].model);
               strcpy (places[k].registration_number,  places[k + 1].registration_number);
                
               strcpy (places[k+1].owner.name,  temp_name);
               places[k+1].owner.age  = temp_age ;
               strcpy (places[k+1].vehicle_type, temp_type);
               strcpy (places[k+1].model, temp_model);
               strcpy (places[k+1].registration_number,  temp_reg);
                
            }
        }
        
    }
    
    for(int j = 0 ; j < size; j++)
    {
        printf("Fordonsnummer %d.......\n", j + 1);
        printf("......................................\n");
        printf("Ägarens namn är: %s\n", places[j].owner.name);
        printf("......................................\n");
        printf("Ägarens ålder är: %d\n", places[j].owner.age);
        printf("......................................\n");
        printf("Fordonstypen är: %s\n", places[j].vehicle_type);                 
        printf("......................................\n");
        printf("Fordonsmodellen är: %s\n", places[j].model);
        printf("......................................\n");
        printf("Fordonets registreringsnummer är: %s\n", places[j].registration_number);
        
    }   
}
