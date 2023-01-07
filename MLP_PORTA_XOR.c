#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void conta_segundos (int l) {

  int i = 0, virada = 1, agora = 0, anterior = 0;


  while (i <= l)
    {
      //se virada C) par eu vou guardar o valor aleatC3rio em agora
      if (virada % 2 == 0)
{
 srand ((unsigned) time (NULL));
 agora = rand () % 10 + 1;
}
      //se virada nC#o C) par eu vou guardar o valor aleatC3rio em anterior
      if (virada % 2 != 0)
{
 srand ((unsigned) time (NULL));
 anterior = rand () % 10 + 1;
}
      /*se o valor que eu guardei quando virada era par for diferente do que eu guardei quando virada
         era C-mpar, entC#o significa que o valor aleatC3rio gerado acabou de mudar
         se ele mudou, quer dizer que passou um segundo */

      if (agora != anterior)
{
 //printf("%i,",i);
 i++;
}

      virada++;

    }

  return;
}

int main(){
   
    //int l,c;
    //scanf("%d%d",&l,&c);
    float m[4][3];
   
    int i, j;
    //inicializando matriz
   /* for(i=0;i<l;i++){
       
        for(j=0;j<c;j++){
           
            printf("digite um valor para a tabela ");
            scanf("%f",&m[i][j]);
        }
    printf("\n");
       
    }*/
 
m[0][0]=0;           m[0][1]=0;         m[0][2]=0;
m[1][0]=0;           m[1][1]=1;         m[1][2]=1;
m[2][0]=1;           m[2][1]=0;         m[2][2]=1;
m[3][0]=1;           m[3][1]=1;         m[3][2]=0;



   

    //printando matriz
    for(i=0;i<4;i++){
       
        for(j=0;j<3;j++){
           
            printf(" %f ",m[i][j]);
        }
    printf("\n");    
    }
   
    float w1,w2,w3,w4,w5,w6,w7,w8,teta1,teta2,N,s1,s2,s3,s4,g1,g2,g3,g4,erro=1,euler=2.7182818,epoca=0;
    float d1,d2,d3,d4,d5,d6,d7,d8;
    //atribui valores aleatórios para w1,w2,w3,w4,w5,w6,w7,w8
    printf("aguarde enquanto gero valores aleatorios para os pesos iniciais\n");
    srand(time(NULL));
    w1=rand() % 10;
    w1=(1/(w1+1));
    conta_segundos (1);
    w2=rand() % 10;
    w2=(1/(w2+1));
    conta_segundos (1);
    w3=rand() % 10;
    w3=(1/(w3+1));
    conta_segundos (1);
    w4=rand() % 10;
    w4=(1/(w4+1));
    conta_segundos (1);
    w5=rand() % 10;
    w5=(1/(w5+1));
    conta_segundos (1);
    w6=rand() % 10;
    w6=(1/(w6+1));
    conta_segundos (1);
    w7=rand() % 10;
    w7=(1/(w7+1));
    conta_segundos (1);
    w8=rand() % 10;
    w8=(1/(w8+1));
    conta_segundos (1);
    teta1=rand() % 10;
    teta1=(1/(teta1+1));
    conta_segundos (1);
    teta2=rand() % 10;
    teta2=(1/(teta2+1));
   
    printf("w1=%f W2=%f W3=%f w4=%f w5=%f w6=%f w7=%f w8=%f teta1=%f teta2=%f \n",w1,w2,w3,w4,w5,w6,w7,w8,teta1,teta2);
    printf("Determine o passo de correção do erro \n");
    scanf("%f",&N);
   
   
    for(i=0;i<4;i++){
    while(erro>0.00005){
       
       
                //propagação
    //calculando a saída da primeira camada    
        s1=(m[i][0]*w1)+(m[i][1]*w2)-teta1;
        s2=(m[i][0]*w3)+(m[i][1]*w4)-teta1;
   
    //aplicar a função de ativação na saída
   
        g1=(1/(1+pow(euler,(-s1))));
        g2=(1/(1+pow(euler,(-s2))));
        
        //printf("g1=%f\n",g1);
        //printf("g2=%f\n",g2);
   
    //calculando a saída da segunda camada    
   
        s3=(g1*w5)+(g2*w6)-teta2;
        s4=(g1*w7)+(g2*w8)-teta2;
   
    //aplicar a função de ativação na saída  
   
        g3=(1/(1+pow(euler,(-s3))));
        g4=(1/(1+pow(euler,(-s4))));
        //printf("g3=%f\n",g3);
        //printf("g4=%f\n",g4);
    
                //EQM
               
    erro=( pow((g3-m[i][2]),2)+pow((g4-m[i][2]),2) )/2;
    printf("erro=%f\n",erro);
   
                //corrige os pessos
                if(erro>0.00005){
    d5=-(m[i][2]-g3)*g3*(1-g3)*g1;
    d6=-(m[i][2]-g3)*g3*(1-g3)*g1;
    d7=-(m[i][2]-g4)*g4*(1-g4)*g2;
    d8=-(m[i][2]-g4)*g4*(1-g4)*g2;
    
    d1=-(m[i][2]-g3)*g3*w5-(m[i][2]-g4)*g4*w7;
    d2=-(m[i][2]-g3)*g3*w6-(m[i][2]-g4)*g4*w8;
    d3=-(m[i][2]-g4)*g4*w8-(m[i][2]-g3)*g3*w6;
    d4=-(m[i][2]-g3)*g3*w6-(m[i][2]-g4)*g4*w8;
                    
    w8=w8 - N*(d8);
    w7=w7 - N*(d7);
    w6=w6 - N*(d6);
    w5=w5 - N*(d5);
    w4=w4 - N*(d4);
    w3=w3 - N*(d3);
    w2=w2 - N*(d2);
    w1=w1 - N*(d1);
                                }
            epoca++;
            printf("%f ",epoca);
    }
            
    }
   printf("rede treinada\nw1=%f\nw2=%f\nw3=%f\nw4=%f\nw5=%f\nw6=%f\nw7=%f\nw8=%f\nteta1=%f\nteta2=%f",w1,w2,w3,w4,w5,w6,w7,w8,teta1,teta2);
   return 0;
}
