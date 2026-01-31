

// student: Ahmad Alabdulrahem 

#include"lab3.h"



int main ()
{
    vehicle_t places[MAX];  
    char choice[STR_MAX];
    int CHOICE;
    int i = 0;
    int size = 0;
    read(places, "in.txt", &size);
    printf("%d\n", size);
    
    do 
    {
     
      printf("1: Lägg till ett fordon...\n");
      printf("2: Ta bort ett fordon...\n");
      printf("3: Sortering efter fordonsmodell....\n");
      printf("4: Skriv ut information om ett fordon...\n");
      printf("5: Skriv ut alla fordonsregister...\n");
      printf("6: Stänga...\n");
     
    
      fgets(choice, M, stdin);
      CHOICE = atoi(choice);
     
        
      switch(CHOICE)
      {
          case 1: 
                  printf("%d\n", size);
              if (i == MAX)
                  printf("Det finns inga tomma platser kvar!");
              else
              {
                  places[size++]= addavehicle(); 
                  printf("size=%d\n",size);
                
              }       
              break;
          case 2: 
              deleteavehicle(places, &size);
              break; 
          case 3: 
              sort(places, size); 
              break; 
          case 4:
              print(places, size); 
              break;
          case 5: 
              printall(places, size); 
              break;
          case 6: 
              if (size != 0)
              {              
                  write(places, "in.txt.", size);
              }
              
              break;
          default: 
              printf("%d Felaktigt val!! Försök igen...\n", CHOICE);
        }
    }

    while(CHOICE != 6);

}
        
