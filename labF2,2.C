#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

 double Eqt(double x); 

 double Left_Rect(double a,double b, int n); // інтегрування, метод лівних квадратів
 double Right_Rect(double a,double b, int n); // інтегрування, метод праих квадратів
 double Trapeze(double a,double b, int n); // інтегрування, метод трапецій
 double Parabola(double a,double b, int n); //  // інтегрування, метод парабол

 void Tabulation(double value);// табуляція в залежност від значень, щоб великі значенння не ламали таблицю

 int A[20]; // массив значень a
 int B[20]; // массив значень b
 int N[20]; // массив значень N, завжди != 0

 int Metod_Used = 0; /* вибраний метотд інтегрування :
                         1 - метод лівних квадратів
                         2 - метод праих квадратів
                         3 - метод трапецій
                         4 - метод парабол
                         5 - виводи всі значення, при цьому delta не виводиться
                     */

 int Gaps = 1; // кількість проміжків, завжди >= 1

 double DeltaMath = 0;

 int StD_CNT = 0; // суди прибавляєм +2, і рахуєм значення по новій, поки 0.00001 <= DeltaMath && DeltaMath <= 0.001

  SetConsoleOutputCP(1251); // вмикаєм кирилицю
  SetConsoleCP(1251);

//====================================== отримуємо значення параметрів =========================================//
  printf("\n Виберіть метод обчислення інтегралу:\n");

  printf("\n   1 - лівих квадратів");
  printf("\n   2 - правих квадратів");
  printf("\n   3 - трапецій");
  printf("\n   4 - парабол");
  printf("\n   5 - всі методи\n");

  printf("\n ВАША ВІДПОВІДЬ: ");
  while(scanf("%d", &Metod_Used) && Metod_Used - 1u >= 4){// перевіряєм правильність введених данних, діапазон методів 1-5
  printf("\n error, please try again: \n");
  }


  printf("\n Виберіть кількість проміжків: ");
  scanf("%d", &Gaps);
  if(Gaps == 0){Gaps = 1;} // перевіряєм правильність введених данних, мінімальна кількість проміжків повинна бути > 1
  printf("\n");


  for(int i = 0; i < Gaps; i++){ // в залежності від вибраної раніше кількості проміжків вводимо параметри для кожного з них
   do{
    printf(" Проміжок #%d , введіть a, b, N : ",i+1);
    scanf("%d %d %d",&A[i], &B[i], &N[i]);
   }while(N[i] == 0); // перевіряєм правильність введених данних, N не повинно борівнювати 0
  }

//====================================== друкуєм зоголовок таблиці =========================================//
printf("\n");
 switch(Metod_Used){ // в залежності від обраного методу
  case 5: // виводим всі значення
   case 1: // метод лівих квадратів
     printf("             Left_Rect          ");
     if(Metod_Used != 5){printf("Delta N            ");}//прикол з виденням всіх значень
   if(Metod_Used == 1){break;}
   case 2: // метод правих квадратів
     printf("Right_Rect         ");
     if(Metod_Used != 5){printf("Delta N            ");}//прикол з виденням всіх значень
   if(Metod_Used == 2){break;}
   case 3: // метод трапецій
     printf("Trapeze            ");
     if(Metod_Used != 5){printf("Delta N            ");}//прикол з виденням всіх значень
   if(Metod_Used == 3){break;}
   case 4: // метод парабол
     printf("Parabola           ");
     if(Metod_Used != 5){printf("Delta N            ");}//прикол з виденням всіх значень
   if(Metod_Used == 3){break;}
  break;
 }
//====================================== друкуємо саму таблицю =========================================//
for(int i = 0; i < Gaps; i++){ //виводим на екран значення всіх введених проміжків
do{
 printf("\n#%d",i+1);
 Tabulation(i+1);
 StD_CNT += 2;
 switch(Metod_Used){ // в залежності від обраного методу
  case 5:// виводим всі значення
   case 1:// метод лівих квадратів
     printf("%f", Left_Rect(A[i],B[i],N[i]));
     Tabulation(Left_Rect(A[i],B[i],N[i]));
     if(Metod_Used != 5){//виводим Delty, якщо вибраний лише один метод
      DeltaMath = Left_Rect(A[i],B[i],N[i]) - Left_Rect(A[i],B[i],N[i] + StD_CNT);
      printf("%f", DeltaMath);Tabulation(DeltaMath);
     }
   if(Metod_Used == 1){break;}
   case 2:// метод правих квадратів
     printf("%f", Right_Rect(A[i],B[i],N[i]));
     Tabulation(Right_Rect(A[i],B[i],N[i]));
     if(Metod_Used != 5){//виводим Delty, якщо вибраний лише один метод
       DeltaMath = Right_Rect(A[i],B[i],N[i]) - Right_Rect(A[i],B[i],N[i] + StD_CNT);
       printf("%f", DeltaMath);Tabulation(DeltaMath);
     }
   if(Metod_Used == 2){break;}
   case 3:// метод трапецій
     printf("%f", Trapeze(A[i],B[i],N[i]));
     Tabulation(Trapeze(A[i],B[i],N[i]));
     if(Metod_Used != 5){//виводим Delty, якщо вибраний лише один метод
      DeltaMath = Trapeze(A[i],B[i],N[i]) - Trapeze(A[i],B[i],N[i] + StD_CNT);
      printf("%f", DeltaMath);Tabulation(DeltaMath);
      }
   if(Metod_Used == 3){break;}
   case 4:// метод парабол
     printf("%f", Parabola(A[i],B[i],N[i]));
     Tabulation(Parabola(A[i],B[i],N[i]));
     if(Metod_Used != 5){//виводим Delty, якщо вибраний лише один метод
       DeltaMath = Parabola(A[i],B[i],N[i]) - Parabola(A[i],B[i],N[i] + StD_CNT);
       printf("%f", DeltaMath);Tabulation(DeltaMath);
     }
   if(Metod_Used == 3){break;}
  break;
 }
}while(0.00001 <= DeltaMath && DeltaMath <= 0.001); // виводим значення з заданою похибкою
}

 printf("\n\n\n");
  return 0;
}


double Eqt(double x){ // рівняння
   double math_X = 0;
   math_X = (2*x+3);
   math_X *= x;
   math_X += 2;
  return 1.0/math_X;
}
double Left_Rect(double a,double b, int n){ // метод лівих квадратів
   double h = (b - a) / n;
   double sum = 0.0;
   for(int i = 0; i <= n - 1; i++){
    sum += h * Eqt(a + i * h);
   }
 return sum;
}
double Right_Rect(double a,double b, int n){ // метод правих квадратів
   double h = (b - a) / n;
   double sum = 0.0;
   for(int i = 1; i <= n; i++){
    sum += h * Eqt(a + i * h);
   }
 return sum;
}
double Trapeze(double a,double b, int n){  // метод трапецій
   double h = (b - a) / n;
   double sum = Eqt(a) + Eqt(b);
   for(int i = 1; i <= n - 1; i++){
    sum += 2 * Eqt(a + i * h);
   }
   sum *= h / 2;
 return sum;
}
double Parabola(double a, double b, int n){  // метод парабол
   double h = (b - a) / n;
   double sum = Eqt(a) + Eqt(b);
   int k;
   for(int i = 1; i <= n - 1; i++){
    k = 2 + 2 * (i % 2);
    sum += k * Eqt(a + i * h);
   }
   sum *= h / 3;
 return sum;
}
void Tabulation(double value){ // функція табуляції
 int i = 12 - (value / 10);
 while(i > 0){
   i --;
   printf(" ");
 }
}
